#include "motor_shield.h"

RobotMovil bailarin;

void setup()
{

}

void loop()
{
bailarin.forward(80,80,700);
bailarin.reverse(80,80,700);
bailarin.rotate(80,500);
bailarin.rotate(80,-500);
bailarin.brake();
delay(1000);

bailarin.forward(150,150,700);
bailarin.reverse(150,150,700);
bailarin.rotate(150,500);
bailarin.rotate(150,-500);
bailarin.brake();
delay(1000);


bailarin.forward(200,80,1000);
bailarin.forward(120,120,1500);
bailarin.forward(80,200,1000);
bailarin.forward(120,120,1500);
bailarin.reverse(80,80,1000);
bailarin.rotate(80,500);
bailarin.rotate(80,-500);
bailarin.brake();
delay(1000);
} 
