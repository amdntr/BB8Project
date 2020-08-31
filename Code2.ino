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


// RemoteXY select connection mode and include library 
#define REMOTEXY_MODE__SOFTSERIAL
#include <SoftwareSerial.h>

#include <RemoteXY.h>

// RemoteXY connection settings 
#define REMOTEXY_SERIAL_RX 2
#define REMOTEXY_SERIAL_TX 3
#define REMOTEXY_SERIAL_SPEED 9600


// RemoteXY configurate  
#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] =
  { 255,1,0,0,0,13,0,10,13,0,
  1,0,43,24,12,12,2,31,88,0 };
  
// this structure defines all the variables and events of your control interface 
struct {

    // input variables
  uint8_t button_1; // =1 if button pressed, else =0 

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0 

} RemoteXY;
#pragma pack(pop)

/////////////////////////////////////////////
//           END RemoteXY include          //
/////////////////////////////////////////////

#define PIN_BUTTON_1 13


void setup() 
{
  RemoteXY_Init (); 
  
  pinMode (PIN_BUTTON_1, OUTPUT);
  
  // TODO you setup code
  
}

void loop() 
{ 
  RemoteXY_Handler ();
  
  digitalWrite(PIN_BUTTON_1, (RemoteXY.button_1==0)?LOW:HIGH);
  
  // TODO you loop code
  // use the RemoteXY structure for data transfer
  // do not call delay() 


}
