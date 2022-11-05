#pragma once

#include "Servo.h"

namespace control
{
Servo servo;

void setup()
{
  pinMode(BUZZER_pin, OUTPUT);
  servo.attach(SERVO_pin);
  //  servo.write(0);
}

void controlMotor(const uint8_t& value)
{
  switch (value)
  {
    case 0:
      analogWrite(MOTOR_pin, 0);
      break;
    case 1:
      analogWrite(MOTOR_pin, 70);
      break;
    case 2:
      analogWrite(MOTOR_pin, 100);
      break;
    case 3:
      analogWrite(MOTOR_pin, 255);
      break;
  }
}

void controlLedSS(const uint8_t& value)
{
  switch (value)
  {
    case 0:
      analogWrite(LEDSS_pin, 0);
      break;
    case 1:
      analogWrite(LEDSS_pin, 50);
      break;
    case 2:
      analogWrite(LEDSS_pin, 150);
      break;
    case 3:
      analogWrite(LEDSS_pin, 255);
      break;
  }
}

void controlBuzzer(const bool& value)
{
  digitalWrite(BUZZER_pin, value);
}

void controlServo(const uint8_t& value)
{
  servo.write(value);
}
}
