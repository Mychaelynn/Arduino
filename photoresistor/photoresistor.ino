
int lightPen = A0;
int lightVal;

int red = 2;
int green = 3;


void setup() {
  // put your setup code here, to run once:
  pinMode(lightPen,INPUT);
  pinMode(red,OUTPUT);
  pinMode(green,OUTPUT);
  Serial.begin(9600);

  //as light gets darker --> resistence goes up --> current goes down --> voltage across 5k resistor will go down
}


void loop() {
  // put your main code here, to run repeatedly:

  lightVal = analogRead(lightPen);
  Serial.print("Light value is: ");
  Serial.println(lightVal);///

  if (lightVal>600){//outside light is on
    digitalWrite(red,HIGH);
    digitalWrite(green,LOW);
  } 
  else{
    digitalWrite(green,HIGH);
    digitalWrite(red,LOW);
  }
  delay(250);

}
