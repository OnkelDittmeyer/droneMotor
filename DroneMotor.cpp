/*
  DroneMotor.cpp - Library for Agatha Haines BioDrone.
  Created by Marcel Helmer, September 5th, 2015.
  Released into the public domain.
*/

#include "Arduino.h"
#include "DroneMotor.h"


DroneMotor::DroneMotor()
{
  state = 0;
  ++count;

}

DroneMotor::update(){

  if(onOff){
    if(!_oldOnOff){
      state = 0;
      _startState = millis();
      _oldOnOff = onOff;
    }
    _time = millis();
    switch(state){
      case 0:
        if(_time - _startState >= flapTime){
          ++state;
          _startState = millis();
          break;
        }
        break;
      case 1:
        if(_time - _startState >= neutralTime){
          ++state;
          _startState = millis();
          break;
        }
        break;
      case 2:
        if(_time - _startState >= flapTime){
          ++state;
          _startState = millis();
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
