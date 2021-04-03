#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>

#include <ESP8266HTTPClient.h>

#include <WiFiClient.h>

ESP8266WiFiMulti WiFiMulti;

const char* ssid = "xxxx";
const char* password = "xxx";


String ID ="1235";
String postData;
void setup() {
  Serial.begin(115200);
  delay(500);
  WiFi.begin(ssid, password);
  Serial.println("");
  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  };
  Serial.println("");
  Serial.print("Successfully connected to : ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
    
 if ((WiFiMulti.run() == WL_CONNECTED)) {
    HTTPClient http;
    int temp = random(25,35);
    String url = "http://192.168.1.5/blocker/coin/add.php?temp="+String(temp);
    Serial.println(url);
    http.begin(url); //HTTP
    
    int httpCode = http.GET();
    if (httpCode > 0) {
    Serial.printf("[HTTP] GET... code: %d\n", httpCode);
    if (httpCode == HTTP_CODE_OK) {
    String payload = http.getString();
    Serial.println(payload);
    }
    } else {
    Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
    }
    http.end();
    }
    delay(3000);
    
  }
