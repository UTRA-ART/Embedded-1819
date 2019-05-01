/*     Arduino Rotary Encoder Tutorial

   by Dejan Nedelkovski, www.HowToMechatronics.com

*/

#define outputA 6
#define outputB 8
#define index A1

double wheelRadius = 0.13335; //wheel radius in meters

int state = 0;
long int period;
double timeRotation; //time for one revolution in seconds
double rotPerSec;
double roverSpeed; //speed of rover in mph

//Time in microseconds
int time1 = 0;
int time2 = 0;

int counter = 0;
int aState;
int aLastState;

int motorDirection;

int frequency = 3000; //Units in hertz
double delayTime = 1000 / (frequency * 2); //Units in millisec
void setup() {
  pinMode (outputA, INPUT);
  pinMode (outputB, INPUT);
  pinMode (index, INPUT);

  Serial.begin (9600);
  // Reads the initial state of the outputA
  aLastState = digitalRead(outputA);
  //indexLastState = digitalRead(index);
}
void loop() {
  
  aState = digitalRead(outputA); // Reads the "current" state of the outputA

  // If Channel A goes from low to high, we count a pulse
  if (aState == HIGH && aLastState == LOW) {
    // If the outputB state is different to the outputA state, that means the encoder is rotating clockwise
    if (digitalRead(outputB) == HIGH) {
      motorDirection = 1;
      counter ++;
    }
    else {
      motorDirection = 0;
      counter--;
    }
  }

  //If channel A goes from high to low, start timer
  if (aState == LOW && aLastState == HIGH && state == 0){
    time1 = micros();
    state = 1;
  }
  //Once channel A goes from low to high, increment period
  if (aState == HIGH && aLastState == LOW && state == 1){
    time2 = micros();
    state = 2;
  }

  //If half period is reached
  if (state == 2){
    period = 2 * (time2 - time1);
    timeRotation = 500 * period;
    rotPerSec = 1000000 / timeRotation;
    roverSpeed = 2 * M_PI * wheelRadius * rotPerSec * 2.23694;
    Serial.println(roverSpeed); //speed of motor in mph
    state = 0;
  }

  //IMPLEMENT ROLLING AVERAGE REDUCE VARIANCE


  aLastState = aState; // Updates the previous state of the outputA with the current state
  //indexLastState = indexState;
}
