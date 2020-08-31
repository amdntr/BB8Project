/*
Remote controlled BB8 - DIY Machines
This is an easy to build Disney Star Wars BB8 inspired robot. It's controlled by an Arduino UNO over a bluetooth connection from your smartphone.
==========
More info: https://diymachines.co.uk/projects/star-wars-bb8-inspired-rc-printed-robot.html
3D printed parts can be downloaded from here: https://www.thingiverse.com/thing:2749613
==========
SAY THANKS:
Buy me a coffee to say thanks: https://ko-fi.com/diymachines
Support us on Patreon: https://www.patreon.com/diymachines
SUBSCRIBE:
■ https://www.youtube.com/channel/UC3jc4X-kEq-dEDYhQ8QoYnQ?sub_confirmation=1
INSTAGRAM: https://www.instagram.com/diy_machines/?hl=en
FACEBOOK: https://www.facebook.com/diymachines/
*/


void setup() {
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
}

#include <AFMotor.h>

//creates two objects to control two terminals on the motor shield 
AF_DCMotor motor1(2); 
AF_DCMotor motor2(1); 

void forward()
{
  motor1.setSpeed(220); //Define maximum velocity
  motor1.run(BACKWARD); //rotate the motor clockwise
  motor2.setSpeed(220); //Define maximum velocity
  motor2.run(FORWARD); //rotate the motor clockwise
}

void back()
{
  motor1.setSpeed(220); 
  motor1.run(FORWARD); //rotate the motor counterclockwise
  motor2.setSpeed(220); 
  motor2.run(BACKWARD); //rotate the motor counterclockwise
}

void left()
{
  motor1.setSpeed(220); //Define maximum velocity
  motor1.run(FORWARD); //rotate the motor clockwise
  motor2.setSpeed(100);
  motor2.run(FORWARD); //turn motor2 off
}

void right()
{
  motor1.setSpeed(100);
  motor1.run(FORWARD); //turn motor1 off
  motor2.setSpeed(220); //Define maximum velocity
  motor2.run(FORWARD); //rotate the motor clockwise
}

void stationary()
{
  motor1.setSpeed(0);
  motor2.run(RELEASE); //turn motor1 off
  motor2.setSpeed(0);
  motor2.run(RELEASE); //turn motor2 off
}


char command;
void loop(){
  if(Serial.available() > 0){ 
    command = Serial.read(); 
    //Change pin mode only if new command is different from previous.   
    //Serial.println(command);
    switch(command){
    case 'F':  
      forward();
      break;
    case 'B':  
      back();
      break;
    case 'L':  
      left();
      break;
    case 'R':  
      right();
      break;
    case 'S':
      stationary();
      break;
    }
  } 
}
