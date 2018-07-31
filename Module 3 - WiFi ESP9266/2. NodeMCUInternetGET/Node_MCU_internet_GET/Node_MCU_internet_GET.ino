/*
 *  Simple HTTP get webclient test
 *  
 *  
 *  wifitest.adafruit.com/testwifi/index.html
 *  
 */

#include <ESP8266WiFi.h>

//NETWORK CONNECTION CREDENTIALS
const char* ssid     = "Hackland"; // NAME OF WIFI NETWORK
const char* password = "hackland1"; // PASSWORD

//const char* host = "wifitest.adafruit.com";
//String url = "/testwifi/index.html";

const char* host = "wifitest.adafruit.com";
String url = "/testwifi/index.html";

//const char* host = "jsonplaceholder.typicode.com";
//String url = "/posts/1";

//const char* host = "google.com";
//String url = "/search?q=esp8266";

void setup() {
  Serial.begin(115200);
  delay(100);

  // We start by connecting to a WiFi network

  Serial.println();
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
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.print("Netmask: ");
  Serial.println(WiFi.subnetMask());
  Serial.print("Gateway: ");
  Serial.println(WiFi.gatewayIP());
}

int value = 0;

void loop() {
  delay(5000);
  ++value;

  Serial.print("connecting to ");
  Serial.println(host);
  
  // Use WiFiClient class to create TCP connections
  WiFiClient client;
  const int httpPort = 80;
  if (!client.connect(host, httpPort)) {
    Serial.println("connection failed");
    return;
  }
  
  // We now create a URI for the request
  
  Serial.print("Requesting URL: ");
  Serial.println(url);
  
  // This will send the request to the server
  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" + 
               "Connection: close\r\n\r\n");
  delay(500);
  
  // Read all the lines of the reply from server and print them to Serial
  while(client.available()){
    //String line = client.readStringUntil('\r');
    String line = client.readString();
    Serial.print(line);
  }
  
  Serial.println();
  Serial.println("closing connection");
}

