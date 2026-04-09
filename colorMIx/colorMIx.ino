int red = 6;
int green = 5;
int blue = 4;

void setup() {
  // put your setup code here, to run once:
  pinMode(red,OUTPUT);
  pinMode(green,OUTPUT);
  pinMode(blue,OUTPUT);


}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(red,HIGH);
  analogWrite(blue,150);

}
