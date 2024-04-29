#include <WiFi.h>
#include <WiFiClientSecure.h>


const char* ssid = "OPPO Reno6 5G";
const char* password = "hello241";

const char* API_KEY = "96f07fa9-d493-42b3-aef2-6339acd7ba5c";
const float stop_area_latitude = 48.844383;
const float stop_area_longitude = 2.622568;

WiFiClientSecure client;

void setup() {
  Serial.begin(115200);
  delay(1000);

  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");

  Serial.println("Requesting departures...");

  // Make a HTTPS request
  if (client.connect("api.navitia.io", 443)) {
    Serial.println("Connected to server");
    
    // Make the HTTP request
    client.print(String("GET /v1/coverage/fr-idf/coords/") + stop_area_longitude + ";" + stop_area_latitude + "/departures?count=10" + " HTTP/1.1\r\n" +
                 "Host: api.navitia.io\r\n" +
                 "Authorization: " + API_KEY + "\r\n" +
                 "Connection: close\r\n\r\n");
    delay(500);
    
    // Read and print the response
    while (client.available()) {
      String line = client.readStringUntil('\r');
      Serial.print(line);
    }

    client.stop();
    Serial.println("\n\nDisconnected from server");
  } else {
    Serial.println("Connection failed");
  }
}

void loop() {
  // Nothing here
}
