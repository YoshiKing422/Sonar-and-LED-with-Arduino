// Include NewPing Library
#include "NewPing.h"

// Hook up HC-SR04 with Trig to Arduino Pin 9, Echo to Arduino pin 10
#define TRIGGER_PIN 9
#define ECHO_PIN 10
#define LED_PIN 8  // Define LED pin

// Maximum distance we want to ping for (in centimeters).
#define MAX_DISTANCE 400

// NewPing setup of pins and maximum distance.
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);  // Set pin 8 as output
}

void loop() {
  // Get the distance in cm
  int distance = sonar.ping_cm();

  Serial.print("Distance = ");
  Serial.print(distance);
  Serial.println(" cm");

  // Turn LED on if distance is 100 cm or less, otherwise off
  if (distance > 0 && distance <= 100) {
    digitalWrite(LED_PIN, HIGH);
  } else {
    digitalWrite(LED_PIN, LOW);
  }

  delay(500);
}
