# Soil-Moisture-Sensor-System
The Soil Moisture Sensor System is an IoT-based project built with an ESP32 microcontroller. It connects to a Wi-Fi network, serving real-time soil moisture data through a web page, and continuously updates and displays the soil moisture percentage. 

The code provided is for an ESP32-based soil moisture sensor system. Here's a summary of what the code does:
- It includes necessary libraries like WiFi, WebServer, and an HTML template.
- It sets up a web server on port 80.
- The MainPage function serves an HTML page when a user accesses the root URL ("/"). This HTML page is defined in an external HTML template.
- The SoilMoisture function sends the current soil moisture value to the web server when a specific URL path ("/readMoisture") is accessed.
- In the setup function, the ESP32 connects to a Wi-Fi network using the provided SSID and password. It then sets up the web server to handle root requests ("/") and requests to read the moisture value.
- The loop function repeatedly reads the soil moisture sensor (connected to pin A0), calculates the moisture level, and updates it on the web server. It also prints the moisture value to the serial monitor.
- This code essentially creates a web server that provides real-time soil moisture data when accessed via a web browser. It's a simple IoT application for monitoring soil moisture levels.

This project demonstrates how to monitor soil moisture using an ESP32 microcontroller and display the moisture level on a web page.

## Table of Contents

- [Prerequisites](#prerequisites)
- [Getting Started](#getting-started)
- [Hardware Setup](#hardware-setup)
- [Usage](#usage)
- [Customization](#customization)
- [Contributing](#contributing)

## Prerequisites

Before you begin, ensure you have the following components ready:

- Nodemcu ESP8266
- Battery (9v)
- Moisture Sensor
- Bread board
- Jumper wire
- Plant for testing
- Arduino IDE (or PlatformIO) installed on your computer

## Getting Started

1. Clone or download this project to your local machine.
2. Open the project in Arduino IDE or PlatformIO.
3. Configure the project settings by setting your Wi-Fi SSID and password in the code.
4. Upload the code to your ESP32 microcontroller.
5. Connect the soil moisture sensor to the ESP32.
6. Power on your ESP32 and connect it to your Wi-Fi network.

## Hardware Setup
- Connect the soil moisture sensor's output to the A0 pin on the ESP32.
- Power the ESP32 and soil moisture sensor as per your hardware configuration.

## Usage

1. Once the ESP32 is powered on and connected to Wi-Fi, it will create a web server.
2. Access the soil moisture data by opening a web browser and navigating to the ESP32's IP address (displayed in the serial monitor during setup).
3. The web page will display the current soil moisture percentage.
4. The moisture level will be updated every 2 seconds.

## Customization

You can customize the project by modifying the code and HTML page:
- Change the appearance and layout of the web page by editing the HTML in the `output-page.html` file.
- Customize the Wi-Fi credentials and other settings in the Arduino code.
- Adjust the update interval of the moisture level on the web page.

## Contributing

If you'd like to contribute to this project, please fork the repository and create a pull request with your changes.

For more information and detailed instructions, visit [ElectronicWings - ESP32 Soil Moisture Sensor](http://www.electronicwings.com/esp32/esp32-soil-moisture-sensor-web-server).
