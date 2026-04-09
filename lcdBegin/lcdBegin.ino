#include <LiquidCrystal.h>

// Pins: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

void setup() {
  // Use a comma here, and add a semicolon at the end
  lcd.begin(16, 2); 
  
  // Add a semicolon here
  lcd.print("Hello, World!");
}

void loop() {
  // This sets the cursor to the first column (0), second row (1)
  lcd.setCursor(0, 1);
  
  // Prints the number of seconds since the program started
  lcd.print(millis() / 1000);
}