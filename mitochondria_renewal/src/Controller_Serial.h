#pragma once
#include <Arduino.h>

class Controller_Serial{
private:
  bool _ser2; // true:Serial2 / false:Serial
  int _baudrate;
  
  struct InputData{
    float angle; // radian
    int dist; // 0~255
    int turn; // -255~255
  } input;

  //struct ConfigData{} config;

  public:
  Controller_Serial(int baudrate,bool use_serial2=false):_baudrate(baudrate),_ser2(use_serial2){}
  bool begin(){}
  bool updata(){}
  const InputData& get_input(){return this->input;}
  //ConfigData& get_config(){return this->config;}
};