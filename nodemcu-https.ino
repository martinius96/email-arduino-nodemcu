#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>

const char* ssid = "wifiname";
const char* password = "wifipassword";

const char* host = "mywebsite.com"; //without https and without www
const int httpsPort = 443;
const char* fingerprint = "35 85 74 EF 67 35 A7 CE 40 FF 50 F3 C0 F6 EE CF 80 3B 2E 19"; //sha1 fingerprint of HTTPS certificate

void setup() {
  Serial.begin(9600);
  Serial.println();
  Serial.print("connecting to ");
  Serial.println(ssid);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  

}

void loop() {
  WiFiClientSecure client;
  if (client.verify(fingerprint, host)) {} else {}
  if (client.connect(host, httpsPort)) {
    String url = "/email.php"; 
    client.print(String("GET ") + url + " HTTP/1.1\r\n" + "Host: " + host + "\r\n" + "User-Agent: NodeMCU\r\n" + "Connection: close\r\n\r\n");
  }else if (!client.connect(host, httpsPort)) {
    Serial.println("Connection unsucesssful");
  }
}
