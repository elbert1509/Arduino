#include <WiFi.h>
#include <HTTPClient.h>
#include "time.h"
#include "sntp.h"

const char* ssid = "OPPO Reno6 5G";
const char* password = "hello241";

const char* ntpServer1 = "pool.ntp.org";
const char* ntpServer2 = "time.nist.gov";
const long  gmtOffset_sec = 3600;
const int   daylightOffset_sec = 3600;

const char* time_zone = "CET-1CEST,M3.5.0,M10.5.0/3";  // TimeZone rule for Europe/Rome including daylight adjustment rules (optional)

void printLocalTime()
{
  struct tm timeinfo;
  if(!getLocalTime(&timeinfo)){
    Serial.println("No time available (yet)");
    return;
  }
  Serial.println(&timeinfo, "%A, %B %d %Y %H:%M:%S");
}

void setup() {
  Serial.begin(115200);
  delay(100);

  sntp_set_time_sync_notification_cb( timeavailable );
  sntp_servermode_dhcp(1);    // (optional)
  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer1, ntpServer2);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }
  Serial.println("Connected to WiFi");

  // Faire la requête HTTP
  getBusSchedule();


}

void timeavailable(struct timeval *t)
{
  Serial.println("Got time adjustment from NTP!");
  printLocalTime();
}

void loop() {
  delay(5000);
  printLocalTime(); 
}

void getBusSchedule() {
  HTTPClient http;

  float stop_area_latitude = 48.844383;
  float stop_area_longitude = 2.622568;
  const char* API_KEY = "96f07fa9-d493-42b3-aef2-6339acd7ba5c";

  // URL de l'API avec l'arrêt et le numéro de bus
  //String url = "https://api.nativ.io/horaires?arret=ferme-du-buisson&ligne=211";
  String url = "https://api.navitia.io/v1/coverage/fr-idf/coords/"+ String(stop_area_longitude) +";"+ String(stop_area_latitude) +"/departures?count=10";

  Serial.print("Sending HTTP request to: ");
  Serial.println(url);

  // Envoyer la requête GET
  http.begin(url,API_KEY);

  // Attendre la réponse
  int httpCode = http.GET();

  // Si la réponse est reçue
  if (httpCode > 0) {
    // Afficher le code de réponse
    Serial.print("HTTP Response code: ");
    Serial.println(httpCode);

    // Si la réponse est de type "application/json"
    if (httpCode == HTTP_CODE_OK) {
      // Lire la réponse JSON
      String payload = http.getString();
      Serial.println("Response:");
      Serial.println(payload);
    }
  } else {
    // Si la requête a échoué
    Serial.print("Error on HTTP request: ");
    Serial.println(http.errorToString(httpCode).c_str());
  }

  // Libérer les ressources
  http.end();
}
