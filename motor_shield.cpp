#include <Arduino.h>
#include "motor_shield.h"
#define dir_a 12
#define dir_b 13
#define pwm_a 3
#define pwm_b 11
#define brake_a 9
#define brake_b 8

RobotMovil::RobotMovil()
{
  pinMode(dir_a, OUTPUT);
  pinMode(dir_b, OUTPUT);
  pinMode(pwm_a, OUTPUT);
  pinMode(pwm_b, OUTPUT);
  pinMode(brake_a, OUTPUT);
  pinMode(brake_b, OUTPUT);
  digitalWrite(dir_a, LOW);
  digitalWrite(dir_b, LOW);
  digitalWrite(pwm_a, LOW);
  digitalWrite(pwm_b, LOW);
  digitalWrite(brake_a, LOW);
  digitalWrite(brake_b, LOW);
}

void RobotMovil::forward(int l, int r, int t)
{
  relase();
  digitalWrite(dir_a, LOW);
  digitalWrite(dir_b, LOW);
  analogWrite(pwm_a, l);
  analogWrite(pwm_b, r);
  delay(t);
  brake();
}

void RobotMovil::reverse(int l, int r, int t)
{
  relase();
  digitalWrite(dir_a, HIGH);
  digitalWrite(dir_b, HIGH);
  analogWrite(pwm_a, l);
  analogWrite(pwm_b, r);
  delay(t);
  brake();
}

void RobotMovil::rotate(int p, int t)
{
  relase();
  if (t>0)
   {
    digitalWrite(dir_a, HIGH);
    digitalWrite(dir_b, LOW);
    analogWrite(pwm_a, p);
    analogWrite(pwm_b, p);
   }
  else
   {
    
    digitalWrite(dir_a, LOW);
    digitalWrite(dir_b, HIGH);
    analogWrite(pwm_a, p);
    analogWrite(pwm_b, p);
   } 
  delay(abs(t));
  brake();
}

void RobotMovil::brake()
{
  digitalWrite(pwm_a, LOW);
  digitalWrite(brake_a, HIGH);
  digitalWrite(pwm_b, LOW);
  digitalWrite(brake_b, HIGH);
}

void RobotMovil::relase()
{
  digitalWrite(brake_a, LOW);
  digitalWrite(brake_b, LOW);
}
