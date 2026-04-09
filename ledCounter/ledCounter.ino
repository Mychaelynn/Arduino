int b1 = 13;
int b2 = 12;
int b3 = 11;
int b4 = 8;

int ledPins[] = {b4, b3, b2, b1};
bool pattern[] = {false, false, false, false};

void setup() {
  Serial.begin(9600);
  
  // pinMode must come before digitalWrite
  pinMode(b1, OUTPUT);
  pinMode(b2, OUTPUT);
  pinMode(b3, OUTPUT);
  pinMode(b4, OUTPUT);

}

void loop() {
  // Commented out so it doesn't instantly overwrite your setup logic
  /*
  digitalWrite(b1, HIGH);
  digitalWrite(b2, HIGH);
  digitalWrite(b3, HIGH);
  digitalWrite(b4, HIGH);
  */

  
  float log2Val = log(2); // Use float for math

  // Light up for 0 first 
  for (int j = 0; j < 4; j++) {
    digitalWrite(ledPins[j], pattern[j] ? HIGH : LOW);
  }
  delay(2000);

  for (int i = 1; i < 16; i++) {
    // Reset pattern array (C++ syntax)
    for (int j = 0; j < 4; j++) pattern[j] = false;

    int num; 
    if (i % 2 != 0) {
      num = i - 1;
      pattern[0] = true;
    } else {
      num = i;
      pattern[0] = false;
    }

    // Fixed while loop syntax and variable names
    while (num > 0) {
      int ledNum = (log(num) / log2Val) + 0.1; // Add 0.1 to avoid rounding errors
      
      pattern[ledNum] = true; 
      

      int ans = pow(2, ledNum) + 0.1;
      num = num - ans;
      
      if (num <= 0) break;
    }

    // Update LEDs
    for (int j = 0; j < 4; j++) {
      digitalWrite(ledPins[j], pattern[j] ? HIGH : LOW);
    }

    Serial.print("LED IS SHOWING ");
    Serial.print(i);
    Serial.print(" | Binary: ");
    Serial.println(i,BIN);
    delay(2000);
  }
}