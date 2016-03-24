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
    int count = 0;
    bool onOff = false; //is motor active?
    int state = 1;  //current state of the motor 0=left 1=neutral 2=right

    int flapTime = 300; //time motor moves left or right;
    int neutralTime = 300; //time motor remains neutral to get pushed back by spring

    int left = 0;
    int right = 0;

    bool idleMode = false;
    long idleDuration = 0;
    long idleDelay = 0;

    DroneMotor();
    void setRegNum(int leftNum, int rightNum);
    void update();
    void idle(long duration, long delay);


  private:
    int _dir;
    long _time;
    int _startState;

    int _oldOnOff = onOff; //check if motor got turned on/off *huehuehue*

    long _idleStartTime;
    bool _idleMode;
};

#endif
