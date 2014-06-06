#include "motor_shield.h"

RobotMovil R2A2;

void setup()
{
 // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }

  // send an intro:
  Serial.println("send any byte and I'll tell you everything I can about it");
  Serial.println();
}

void loop()
{
  if (Serial.available() > 0) 
  {
    int thisChar = Serial.read();
    if (thisChar == 'f') {R2A2.forward(100,100,500);}
    else if(thisChar == 'r') {R2A2.reverse(100,100,500);}
    else if(thisChar == 'd') {R2A2.rotate(100,500);}
    else if(thisChar == 'i') {R2A2.rotate(100,-500);}
    else {R2A2.brake();}
  } 
}
