/*
  ESP32 Soil Moisture Sensor
  http://www.electronicwings.com
*/

//Required Libraries/Header Files
#include <WiFi.h>
#include <WebServer.h>
#include "output-page.html"

WebServer server(80);
// Soil moisture sensor output pin
int _moisture, sensor_analog;
// Soil moisture sensor output pin  
const int sensor_pin = A0;            
// Enter your WiFi SSID
const char *ssid = "Your SSID"; 
// Enter your WiFi password      
const char *password = "Your Password"; 

void MainPage()
{
  // Read the HTML page
  String _html_page = html_page;           
   // Send the HTML page to the web server
  server.send(200, "text/html", _html_page); 
}

void SoilMoisture()
{
  // Convert moisture value into a string
  String MoistuValue = String(_moisture);   
  // Send the updated moisture value to the web server
  server.send(200, "text/plain", MoistuValue); 
}

void setup(void)
{
  // Set the baud rate to 115200
  Serial.begin(115200); 
  WiFi.mode(WIFI_STA); 
  // Set WiFi in station mode
  WiFi.begin(ssid, password);
  Serial.print("Connecting to ");
  Serial.println(ssid);
  // Wait for 1000ms
  while (WiFi.waitForConnectResult() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(100);
  }
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("Your Local IP address is: ");
  // Print the local IP address
  Serial.println(WiFi.localIP());         
  // Display the web/HTML page
  server.on("/", MainPage);                 
  // Start the server
  server.on("/readMoisture", SoilMoisture); 
  // Start the server
  server.begin();                           
  // Wait for 1000ms
  delay(1000);                              
}

void loop(void)
{
  sensor_analog = analogRead(sensor_pin);
  _moisture = 100 - ((sensor_analog / 4095.00) * 100);
  server.handleClient();
  Serial.print("Moisture = ");
  // Print moisture value on the serial window
  Serial.print(_moisture); 
  Serial.println("%");
  // Wait for 1000ms
  delay(1000); 
}
