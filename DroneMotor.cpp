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

void DroneMotor::idle(long duration, long delay){
  idleDuration = duration;
  idleDelay = delay;

  if(!onOff){
        onOff = true;
        _idleStartTime = millis();
        // Serial.print("Turn on motor for ");
        // Serial.print(duration);
        // Serial.println(" milliseconds");
        idleMode = true;
    }
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

    _time = millis();
    if(idleMode && _time - _idleStartTime > idleDuration){
      onOff = false;
    }

    _time = millis();
    if(idleMode && _time - _idleStartTime > (idleDuration + idleDelay)){
      idleMode = false;
    }
}
