#define leftmotorreverse 3
#define leftmotorforward 5
#define rightmotorreverse 6
#define rightmotorforward 9

#define leftIR  A0
#define rightIR  A1
#define middleIR A2
void setup(){
  pinMode(leftmotorforward,OUTPUT);
  pinMode(rightmotorforward,OUTPUT);
  pinMode(leftmotorreverse, OUTPUT);
  pinMode(rightmotorreverse,OUTPUT); 
  pinMode(leftIR ,INPUT);
  pinMode(rightIR ,INPUT);
  pinMode(middleIR ,INPUT);

  Serial.begin(9600);
}
void loop(){
  if (analogRead(leftIR) == LOW && analogRead(middleIR) == HIGH  && analogRead(rightIR) == LOW )// Forward
  {
    analogWrite(leftmotorforward, HIGH);
    analogWrite(rightmotorforward, HIGH);
    
  }
  else if (analogRead(leftIR)== LOW  && analogRead(middleIR)==HIGH && analogRead(rightIR) ==HIGH)// Right
  {
    analogWrite(leftmotorforward,HIGH);
    analogWrite(rightmotorforward,LOW ); 
  }
  else if (analogRead(leftIR) == HIGH && analogRead(middleIR) == HIGH && analogRead(rightIR)== LOW )// Left
  {
    analogWrite(leftmotorforward,LOW );
    analogWrite(rightmotorforward,HIGH ); 
  }
  else if (analogRead(leftIR) ==HIGH && analogRead(middleIR) == HIGH && analogRead(rightIR) ==HIGH )// Stop
  {
    analogWrite(leftmotorforward,LOW );
    analogWrite(rightmotorforward,LOW ); 
  }
  delay(1);
}
