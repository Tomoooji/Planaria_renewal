#pragma once
#include <Arduino.h>

class Controller_Serial{
private:
  HardwareSerial& Ser;
  int _baudrate;
  
  struct InputData{
    float angle; // radian
    int dist; // 0~255
    int turn; // -255~255
  } input;

  //struct ConfigData{} config;

public:
  Controller_Serial(HardwareSerial& serial, int baudrate):SER(serial),_baudrate(baudrate){}
  bool begin(){
    this->SER.begin(this->_baodrate);
  }
  bool begin(const uint8_t Rx, const uint8_t Tx){
    this->SER.begin(this->_baodrate, SERIAL_8N1, Rx, Yx); //8ビット、パリティなし、ストップビット1（8N1）
  }
  bool update(){
    
  }
  const InputData& get_input(){return this->input;}
  //ConfigData& get_config(){return this->config;}
};