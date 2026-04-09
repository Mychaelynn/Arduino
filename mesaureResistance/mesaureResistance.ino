int analogPin = A0;
int raw = 0;
float Vin = 5.0;
float Vout = 0;
float R1 = 10000; // Value of your KNOWN resistor (10k Ohms)
float R2 = 0;     // This will be the mystery resistor
float buffer = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  raw = analogRead(analogPin);
  if (raw) {
    // Calculate the voltage at A0
    buffer = raw * Vin;
    Vout = (buffer) / 1024.0;
    
    // Calculate Resistance using Ohm's Law formula
    buffer = (Vin / Vout) - 1;
    R2 = R1 / buffer;
    
    Serial.print("Resistance: ");
    Serial.print(R2);
    Serial.println(" Ohms");
    delay(1000);
  }
}