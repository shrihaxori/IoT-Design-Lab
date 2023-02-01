#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

// Replace with your network credentials
const char* ssid = "your_SSID";
const char* password = "your_PASSWORD";

// Replace with your Firebase database host and authentication credentials
#define FIREBASE_HOST "your_firebase_host.firebaseio.com"
#define FIREBASE_AUTH "your_firebase_secret"

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  // Connect to Firebase
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Serial.println("Connected to Firebase");
}

void loop() {
  // Read a value from the Firebase database
  String value = Firebase.getString("/test");
  Serial.println("Value: " + value);

  // Write a value to the Firebase database
  Firebase.setString("/test", "Hello World");

  // Wait for 5 seconds
  delay(5000);
}
