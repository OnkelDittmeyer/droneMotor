/*
  DroneMotor.cpp - Library for Agatha Haines BioDrone.
  Created by Marcel Helmer, September 5th, 2015.
  Released into the public domain.
*/

#include "Arduino.h"
#include "DroneMotor.h"


DroneMotor::DroneMotor()
{
  ++count;


}

void DroneMotor::setRegNum(int leftNum, int rightNum){
  left = leftNum;
  right = rightNum;
}

void DroneMotor::update(){

  if(onOff){
    if(!_oldOnOff){
      state = 0;
      _startState = millis();
      _oldOnOff = onOff;
    }
    _time = millis();
    switch(state){
      case 0:
        //flap right
        if(_time - _startState >= flapTime){
          ++state;
          _startState = millis();
          _dir = true;
          break;
        }
        break;
      case 1:
        // gets pushed back by spring
        if(_time - _startState >= neutralTime){
          if(_dir){
            ++state;
          }else{
            --state;
          }
          _startState = millis();
        }
        break;
      case 2:
        // flap left
        if(_time - _startState >= flapTime){
          --state;
          _startState = millis();
          _dir = false;
          break;
        }
        break;
      default:
        break;
    }
  }else{
    _oldOnOff = onOff;
  }
}
