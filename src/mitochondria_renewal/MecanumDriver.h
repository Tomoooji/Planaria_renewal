#pragma once
#include <Arduino.h>
#include <AnalogMotorDriver.h>

class Mecanum{
private:
  AnalogMotor motors[4];
  
  enum MOTOR{
    FRONTLEFT,BACKLEFT,BACKRIGHT,FRONTRIGHT
  };

  struct gain{
    bool reversed[4];
    int max_speed[4];
  } config;

public:
  Mecanum();
 
  void begin(const uint8_t pin[]);

  void move(int FR_BL, int FL_BR, int turn);
};