# ESP32 Remote Control Relay

This project allows you to control a relay using an ESP32 and the Blynk app. It can be set up to control electrical devices either through a local server or remotely via Blynk Cloud.

## Description

With this project, you can turn electrical devices (such as lights, fans, etc.) on and off from your smartphone or via a local server, using the Blynk platform. The ESP32 connects to a Wi-Fi network and communicates with the Blynk app for remote control.

## Features

- Control a relay with the Blynk app
- Option to use a local Blynk server or the Blynk Cloud
- Simple setup with the ESP32
- Easy integration with other Blynk widgets

## Requirements

- **Hardware:**
  - ESP32 development board
  - Relay module
  - Jumper wires and breadboard (optional, for prototyping)

- **Software:**
  - Blynk app (available for iOS and Android)
  - Arduino IDE or PlatformIO with the ESP32 board support
  - Blynk library for Arduino

## Circuit Diagram

![image](https://github.com/user-attachments/assets/bfc803fa-e3b7-4b9a-a6ea-6888d19d016b)

**Note:** Connect the relay's input pin to GPIO 26 of the ESP32, and the relay's output to the electrical device you want to control.

## Setup

### 1. Install Libraries
Install the necessary libraries in the Arduino IDE:

- **Blynk**: You can install it from the Arduino Library Manager.

### 2. Setup the Blynk App

- Create a new project in the Blynk app.
- Select your device (ESP32) and connection type (Wi-Fi).
- Add a button widget in the app to control the relay. Set the pin as V1 and the mode to `Switch`.

### 3. Configure the Code

Open the `ESP32 Remote Control Relay` code in Arduino IDE and modify the following parameters:

```cpp
// Wi-Fi credentials
char ssid[] = "YourWiFiNetworkName";
char pass[] = "YourWiFiPassword";

// Blynk Auth Token
char auth[] = "YourBlynkAuthToken";

// Local Blynk Server details (optional)
char localServer[] = "192.168.1.100"; // IP of your local server
uint16_t localPort = 8080; // Default Blynk Local Server port
