//DIP Switch mode 0b10110100

int LMotor = 7; //Dig 2
int RMotor = 4; //Dig 1 
int enableleftMotor = 5; //AN 2 
int enablerightMotor = 6; //AN 1
//int motorOff = 127;
//int motorForward = 200;
//int motorBackwards = 50;

void setup() {
  Serial.begin(9600); // Serial comm begin at 9600bps
  pinMode(LMotor,OUTPUT);
  pinMode(RMotor,OUTPUT);
  pinMode(enableleftMotor,OUTPUT);
  pinMode(enablerightMotor,OUTPUT);
}

void loop() {
  if (Serial.available() > 0){ // if serial value is available 
    int val = Serial.read();// then read the serial value
    if (val == 'e'){ //Right motor forward
      analogWrite(enablerightMotor,100);
      digitalWrite(RMotor,HIGH);
     }
    if (val == 'q'){ //Right motor backward
      analogWrite(enablerightMotor,100);
      digitalWrite(RMotor,LOW);
    }
    if (val == 'd'){ //Left motor backwards
      analogWrite(enableleftMotor,100);
      digitalWrite(LMotor,HIGH);
    }
    if (val == 'a'){ //Left motor forwards
      analogWrite(enableleftMotor,100);
      digitalWrite(LMotor,LOW);
    }
    if (val == 's'){ //Stop right motor
      analogWrite(enablerightMotor,0);
    }
    if (val == 'w'){ //Stop left motor
      analogWrite(enableleftMotor,0);
    }
    if (val == 'z'){ //Both stop
      analogWrite(enableleftMotor,0);
      analogWrite(enablerightMotor,0);
    }
   /* if (val == 'w'){
      analogWrite(leftMotor, motorForward);
      analogWrite(rightMotor, motorForward);
    }
    if (val == 's'){
      analogWrite(leftMotor, motorOff);
      analogWrite(rightMotor, motorOff);
    }
    if (val == 'c'){
      analogWrite(rightMotor, motorBackwards);
    }
    if (val == 'z'){
      analogWrite(leftMotor, motorBackwards);
    }
    if (val == 'x'){
      analogWrite(leftMotor, motorBackwards);
      analogWrite(rightMotor, motorBackwards);
    }
    */
  }
}
