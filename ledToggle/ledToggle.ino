int led = 2;
int button =8;
int read = A0;
int status = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(led,OUTPUT);
  pinMode(button,INPUT);
  pinMode(read,INPUT);
  Serial.begin(9600);

}

void loop() {


  int butt = digitalRead(button);
  if (butt==1){
    if (status==0){
      status=1;
    }
    else{
      status =0;
    }
    
  }
  digitalWrite(led,status);

  delay(250);
  
  int resist = analogRead(read);
  //Serial.println(resist);


}
