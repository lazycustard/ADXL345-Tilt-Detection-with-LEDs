#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_ADXL345_U.h>

Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified(12345);

const int leftLED = 3;
const int rightLED = 4;
const int forwardLED = 5;
const int backwardLED = 6;
const float tiltThreshold = 2.0; // Sensitivity Level 

void setup() {
  Serial.begin(9600);
  
  pinMode(leftLED, OUTPUT);
  pinMode(rightLED, OUTPUT);
  pinMode(forwardLED, OUTPUT);
  pinMode(backwardLED, OUTPUT);

  if (!accel.begin()) {
    Serial.println("ADXL345 not detected!");
    while (1);
  }
  accel.setRange(ADXL345_RANGE_2_G); 
}

void loop() {
  sensors_event_t event;
  accel.getEvent(&event);

  digitalWrite(leftLED, LOW);
  digitalWrite(rightLED, LOW);
  digitalWrite(forwardLED, LOW);
  digitalWrite(backwardLED, LOW);

  if (event.acceleration.x < -tiltThreshold) {
    digitalWrite(rightLED, HIGH);
  }

  if (event.acceleration.x > tiltThreshold) {
    digitalWrite(leftLED, HIGH);
  }
  if (event.acceleration.y < -tiltThreshold) {
    digitalWrite(forwardLED, HIGH);
  }
  if (event.acceleration.y > tiltThreshold) {
    digitalWrite(backwardLED, HIGH);
  }
  Serial.print("X: ");
  Serial.print(event.acceleration.x);
  Serial.print(" Y: ");
  Serial.print(event.acceleration.y);
  Serial.print(" Z: ");
  Serial.println(event.acceleration.z);

  delay(300);
}
