#include <Servo.h>

Servo servo;
int servoPin = 8;

int echo = 7;
int trig = 6;

float duration;
float distanceCM;
float distanceIN;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(echo, INPUT);
  pinMode(trig, OUTPUT);
  servo.attach(servoPin);

}

void loop() {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  duration = pulseIn(echo, HIGH);
  distanceCM = (0.034 * duration) / 2;
  distanceIN = distanceCM / 2.54;

  // Use println so each reading is on a new line
  Serial.print("Distance: ");
  Serial.print(distanceIN);
  Serial.println(" in");

  // Only trigger if distance is between 0.1 and 6 inches
  // This prevents the "0" error from triggering the servo
  // if (distanceIN <= 6 && distanceIN > 0.1) {
  //   servo.write(90);
  // } else {
  //   servo.write(0);
  // }


//MAPPING TO DISTANCE
  int servoPos = map (distanceCM,0, 30, 0, 180);
  servo.write(servoPos);

//rotate according to distance

  delay(100); // Give the sensor and servo time to breathe!
}