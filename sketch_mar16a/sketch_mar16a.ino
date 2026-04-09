#include <Servo.h>
Servo servo1;
int servoPin = 9;
int potPin = A0;

void setup() {
  servo1.attach(servoPin);
}

void loop() {
  int reading = analogRead(potPin);
  int angle = map(reading, 0, 1023, 0, 180);
  servo1.write(angle);
}