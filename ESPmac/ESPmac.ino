#include <WiFi.h>
#include <esp_wifi.h>

// Set your new MAC Address
uint8_t newMACAddress[] = {0xD0, 0xBC, 0xC1, 0x98, 0x2E, 0xF3};

void setup(){
  Serial.begin(115200);
  Serial.println();
  
  WiFi.mode(WIFI_STA);
  
  Serial.print("[OLD] ESP32 Board MAC Address:  ");
  Serial.println(WiFi.macAddress());
  
  // ESP32 Board add-on before version < 1.0.5
  //esp_wifi_set_mac(ESP_IF_WIFI_STA, &newMACAddress[0]);
  
  // ESP32 Board add-on after version > 1.0.5
  esp_wifi_set_mac(WIFI_IF_STA, &newMACAddress[0]);
  
  Serial.print("[NEW] ESP32 Board MAC Address:  ");
  Serial.println(WiFi.macAddress());
}
 
void loop(){

}
