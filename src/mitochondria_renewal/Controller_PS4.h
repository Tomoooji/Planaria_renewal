#pragma once
#include <Arduino.h>
#include <PS4Controller.h>

class Controller_PS4{
private:
  const char* mac_address = nullptr;
  
  struct info{
    float angle; // radian
    int dist; // 0~255 ?
    int turn; // -255(right)~255(left) :ラジアンと同じ
  } data;

  struct config{
    int ignore_range_stick;
    int ignore_limit_triger;
    //int ignore_time_button;
  } gain;
  
  int _filter(int valX, int valY){
    return sq(valX)+sq(valY) > sq(this->gain.ignore_range_stick)? sqrt(sq(valX)+sq(valY)): 0;
  }

  int _filter(int val){
    return (val > this->gain.ignore_limit_triger)? val: 0;
  }
  
public:
  Controller_PS4(const char* mac):mac_address(mac){}
  
  bool begin(){
    return PS4.begin(this->mac_address);
  }
  
  bool update(){
    if(PS4.isConnected()){
      this->data.angle = atan2(PS4.LStickY(),PS4.LStickX());
      this->data.dist = _filter(PS4.LStickY(),PS4.LStickX());
      this->data.turn = _filter(PS4.L2()) - _filter(PS4.R2());
      return true;
    }
    return false;
  }

  const info& get_data(){
    return this->data;
  }

  config& get_gain(){
    return this->gain;
  }

};