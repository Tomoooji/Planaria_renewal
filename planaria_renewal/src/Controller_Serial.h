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
    while(this->SER.available()){
      String pair = this->SER.readStringUntil(',');
      int colon = pair.indexOf(':');
      if(colon>0){
        int index = pair.substring(0,colon).toInt();
        int value = pair.indexOf().toInt();//
        if(index==OO) return true;
      }
    }
    return false;
  /*
  while(Serial.available()){
    String pair = Serial.readStringUntil(',');
    //Serial.print(pair);
    int siteColon = pair.indexOf(':');
    //Serial.println(siteColon);
    if(siteColon>0){
      int index = pair.substring(0,siteColon).toInt();
      int value = pair.substring(siteColon+1).toInt();
      if(index>=0 && index<data_num){
        inputData[index] = value;
        writeArray();
        if(index == data_num-1){
          return;
        }
      }
    }
  }
  */
  }
  const InputData& get_input(){return this->input;}
  //ConfigData& get_config(){return this->config;}
};