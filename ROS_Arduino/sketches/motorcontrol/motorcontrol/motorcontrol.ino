/* 
 * rosserial Subscriber Example
 * Blinks an LED on callback
 */

#include <ros.h>
#include <std_msgs/Float64.h>

ros::NodeHandle  nh;
int leftmotor = 5;
int rightmotor = 6;
float leftspeed = 0;
float rightspeed = 0;
float leftcommand = 127;
float rightcommand = 127;

void rmotorCb( const std_msgs::Float64& control_msg){
  
  rightspeed = control_msg.data;
  rightcommand = (127 + (80.5*rightspeed)); 
}

void lmotorCb( const std_msgs::Float64& control_msg){
  
  leftspeed = control_msg.data;
  leftcommand = (127 + (80.5*leftspeed)); 
}

ros::Subscriber<std_msgs::Float64> sub("/right_wheel/command", &rmotorCb );
ros::Subscriber<std_msgs::Float64> sub2("/left_wheel/command", &lmotorCb );
void setup()
{ 
  nh.initNode();
  nh.subscribe(sub);
  nh.subscribe(sub2);
}

void loop()
{  
  nh.spinOnce();
  analogWrite(rightmotor,rightcommand);
  analogWrite(leftmotor,leftcommand);
  delay(1);
}



