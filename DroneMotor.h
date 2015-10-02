/*
  DroneMotor.cpp - Library for Agatha Haines BioDrone.
  Created by Marcel Helmer, September 5th, 2015.
  Released into the public domain.
*/

#ifndef DroneMotor_h
#define DroneMotor_h

#include "Arduino.h"

class DroneMotor
{
  public:
    static int count = 0;
    Boolean onOff = false; //is motor active?
    int state;  //current state of the motor 0=left 1=neutral 2=right

    int flapTime = 500; //time motor moves left or right;
    int neutralTime = 300; //time motor remains neutral to get pushed back by spring

    DroneMotor();


  private:
    int _time;
    int _startState;

    int _oldOnOff = onOff; //check if motor got turned on/off *huehuehue*
};

#endif
