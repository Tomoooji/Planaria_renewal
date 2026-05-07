#pragma once
#include <Arduino.h>
#include <PS4Controller.h>

class Controller_PS4{
private:
  const char* mac_address = nullptr;
  
  struct InputData{
    float angle; // radian
    int dist; // 0~255
    int turn; // -255(right)~255(left) :ラジアンと同じ
  } input;

  struct ConfigData{
    int ignore_range_stick;
    int ignore_limit_triger;
    //int ignore_time_button;
  } config;
  
  float _filter(int valX, int valY){
    return sq(valX)+sq(valY) > sq(this->config.ignore_range_stick)? sqrt(sq(valX)+sq(valY)): 0;
  }

  int _filter(int val){
    return (val > this->config.ignore_limit_triger)? val: 0;
  }
  
public:
  Controller_PS4(const char* mac):mac_address(mac){}
  
  bool begin(){
    return PS4.begin(this->mac_address);
  }
  
  bool update(){
    if(PS4.isConnected()){
      this->input.angle = atan2(PS4.LStickY(),PS4.LStickX());
      this->input.dist = _filter(PS4.LStickY(),PS4.LStickX())*2;
      this->input.turn = _filter(PS4.L2()) - _filter(PS4.R2());
      return true;
    }
    return false;
  }

  const InputData& get_input(){
    return this->input;
  }

  ConfigData& get_config(){
    return this->config;
  }

};