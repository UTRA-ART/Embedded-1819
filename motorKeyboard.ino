int leftMotor = 5;
int rightMotor = 6;
int motorOff = 127;
int motorForward = 200;
int motorBackwards = 50;

void setup() {
  Serial.begin(9600); // Serial comm begin at 9600bps
}

void loop() {
  if (Serial.available() > 0){ // if serial value is available 
    int val = Serial.read();// then read the serial value
    if (val == 'e'){ 
      analogWrite(rightMotor, motorForward);
     }
    if (val == 'q'){
      analogWrite(leftMotor, motorForward);
    }
    if (val == 'd'){
      analogWrite(rightMotor, motorOff);
    }
    if (val == 'a'){
      analogWrite(leftMotor, motorOff);
    }
    if (val == 'w'){
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
  }
}
