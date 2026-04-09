int readPin = A0;
float v2=0;
int delayTime = 500;
int led = 3;

void setup() {
  pinMode(readPin, INPUT);
  // Start serial communication at 9600 bits per second
  Serial.begin(9600); 
  pinMode(led,OUTPUT);
}

void loop() {
  v2 = analogRead(readPin);
  float light = (v2*255.0)/1023;
  v2 = (v2*5.0)/1023;
  
  
  Serial.print("Voltage: ");
  Serial.print(v2);
  Serial.print("V | LED Brightness (0-255): ");
  Serial.println(light);

  analogWrite(led,light);
}