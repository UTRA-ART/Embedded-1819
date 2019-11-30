#include <Servo.h>
Servo motor;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  motor.attach(7);
}
void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()> 0){
    int val = Serial.read();
    if (val == 'w'){
      motor.write(180);
    }
    if (val == 'x'){
      motor.write(0);
    }
    if (val == 's'){
      motor.write(90);
    }
  }
}
