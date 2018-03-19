#include <SPI.h>
#include <Ethernet.h>
#define Hostname "Arduino"   
byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};    
char server[] = "www.mywebsite.com";      
IPAddress ip(192, 168, 1, 254);
EthernetClient client;   
void setup() {
 Serial.begin(9600);
}
 
void loop() {
   if (Ethernet.begin(mac) == 0) {    
    Serial.println("IP address not set from DHCP server, trying static IP"); 
    Ethernet.begin(mac, ip);                       
  }  


if (client.connect(server, 80)) { 
    Serial.println("Connected sucesfully to webserver, making request: "); 
    client.print("GET /email.php");     
    client.println(" HTTP/1.1");              
    client.println("Host: www.mywebsite.com");
    client.println("Connection: close");    
    client.println();                       
 client.stop();    
 Serial.println("E-mail sucessfully sent!"); 
  } else {                                          
    Serial.println("Connection unsucessful..."); 
  }  
delay(10000);
}
