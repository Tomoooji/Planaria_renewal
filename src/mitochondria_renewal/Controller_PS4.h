#pragma once
#include <Arduino.h>
#include <PS4Controller.h>

#define NONEDIRECTION 5

class Controller_PS4{
private:
  constexpr char[] MACAddress = nullptr;
  
  struct info{
    int FRBL_speed; // -255~255
    int FLBR_speed; // -255~255
    int turn_speed; // -255(right)~255(left) :ラジアンと同じ
  } data;

  struct gain{
    int ignore_range_stick;
    int ignore_limit_triger;
    //int ignore_time_button;
  } config;

public:
  Controller_PS4(const char mac):MACAddress(mac){}
  
  bool begin(){
    return PS4.begin(this->MACAddress);
  }

  bool stickFilter(int valX, int valY){
    return sp(valX)+sp(valY) > sq(this->config.ignore_range_stick);
  }

  int trigerFilter(int val){
    return (val > this->config.ignore_limit_triger)? val: 0;
  }
  
  bool update(){
    if(PS4.isConnected()){
      this->data.FRBL_speed = stickFilter(PS4.LStickX(),PS4.LStickY()) ? PS4.LStickX()+PS4.LStickY()) : 0;
      this->data.FLBR_speed = stickFilter(PS4.LStickX(),PS4.LStickY()) ? -PS4.LStickX()+PS4.LStickY()) : 0;
      this->data.turn_speed = trigerFilter(PS4.R2) - trigerFilter(PS4.L2);
      return true;
    }
    else{
      return false;
    }
  }

};