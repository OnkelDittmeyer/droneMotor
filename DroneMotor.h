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
    DroneMotor(int pinA, int pinB);
    int flapTime = 500; //time motor moves right/left
    int bufferTime = 400; //time waiting to get to 0 position
    int timer = millis(); //current time
    int lastFlap; //last time motor moved right/left
    int flapStart; //time current motor movement started

    void flapping(boolean onOff);

    void motorOn(boolean leftRight);

    void motorTest();


  private:
    int _pinA;
    int _pinB;
    boolean dir = true; //direction of motor

    void _waiting(int waitingTime);
    int _startWaiting;
    int _waitingTime;
};

#endif
