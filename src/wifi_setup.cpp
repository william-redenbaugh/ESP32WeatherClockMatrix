#include "wifi_setup.h"

#define WIFI_SSID "WIFI"
#define WIFI_PASSWORD "PASSWORD" 

// #define WIFI_SSID "3Blossomsguest"
// #define WIFI_PASSWORD "4customersonly"

void setup_wifi(void){
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println();
  Serial.println("WiFi connected");
  Serial.println("IP address: "); Serial.println(WiFi.localIP());
}
