/*
 * rosserial Publisher Example
 * Prints "hello world!"
 */

#include <ros.h>
#include <std_msgs/Float64.h>

ros::NodeHandle  nh;


std_msgs::Float64 encoder2_msg;
ros::Publisher encoder2("/left_controller/state", &encoder2_msg);

const int channelB = 2;
const int channelA = 3;
//volatile int state = LOW; //to change variables in an ISR, need to define as volatile
volatile int countB = 0;
volatile int stateA = 0;
volatile int dir = 1;
int countp1;
int countp2;
float enc = 500;
float circ = 0.797;
float deltacount1;
float deltacount2;
float vel1;
float vel2;
volatile int toggleA = 0;

void setup()
{
  nh.initNode();
  nh.advertise(encoder2);
  pinMode(channelB, INPUT_PULLUP); //uses internal pullup resistors to prevent floating errors
  attachInterrupt(digitalPinToInterrupt(channelB), counterB, RISING); //attach an interrupt to an ISR, our encoder increments on the falling edge of channel B
  pinMode(channelA, INPUT_PULLUP); //uses internal pullup resistors to prevent floating errors
  attachInterrupt(digitalPinToInterrupt(channelA), counterA, CHANGE); //attach an interrupt to an ISR, our encoder increments on the falling edge of channel B
}

void loop()
{
  countp1 = countB;
  delay(500);
  deltacount1 = countB-countp1;
  vel1 = ((deltacount1/enc)*circ)/0.5;
  encoder2_msg.data = dir*vel1;
  encoder2.publish( &encoder2_msg );
  nh.spinOnce();  
}
void counterB() {
  countB++;
  if(stateA){
    dir = -1;
  }
  else{
    dir = 1;
  }
}

void counterA() {
    if(countB!=0){
        stateA = !stateA;
    }
}

