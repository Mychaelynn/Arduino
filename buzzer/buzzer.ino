// Pin Definitions
const int buzzPin = 8;  // Connect the (+) leg of buzzer to Pin 8
const int dt = 200;     // Short delay for a "beep" effect
int pot = A0;

int num;

void setup() {
  Serial.begin(9600);
  pinMode(buzzPin, OUTPUT);
  pinMode(pot,INPUT);
}
 

void loop() {
  // Check if user has typed anything
  int val = analogRead(pot);
  val = map(val,0,1023,500,4000);

  tone(buzzPin,val);
  Serial.print("Value is: ");
  Serial.println(val);
  delay(100);

}

// Function to handle the beeping logic
void triggerAlarm() {
  for (int i = 0; i <= 5500; i+=500) {
    Serial.print("Playing: ");
    Serial.println(i);
    tone(buzzPin, i); // Turn ON
    delay(dt);                   // Wait
    noTone(buzzPin);  // Turn OFF
    delay(dt);                   // Wait
  }
}