
int lightPen = A0;
int lightVal;

int buzz = 2;



void setup() {
  // put your setup code here, to run once:
  pinMode(lightPen,INPUT);
  pinMode(buzz,OUTPUT);
  Serial.begin(9600);

  //as light gets darker --> resistence goes up --> current goes down --> voltage across 5k resistor will go down
}


void loop() {
  // put your main code here, to run repeatedly:

  lightVal = analogRead(lightPen);
  Serial.print("Light value is: ");
  Serial.println(lightVal);///

  int buzzVal = map(lightVal,0,1023,1000,4500);
  tone(buzz,buzzVal);
  delay(250);

}
