/*
  DroneMotor.cpp - Library for Agatha Haines BioDrone.
  Created by Marcel Helmer, September 5th, 2015.
  Released into the public domain.
*/

#include "Arduino.h"
#include "DroneMotor.h"

DroneMotor::DroneMotor(int pinA, int pinB)
{
  pinMode(pinA, OUTPUT);
  pinMode(pinB, OUTPUT);
  _pinA = pinA;
  _pinB = pinB;

}

void DroneMotor::flapping(boolean onOff){
  if(onOff){
    //timer reset everytime one flap is finished
    if(digitalRead(_pinA)==LOW && digitalRead(_pinB) == LOW){
      flapStart = millis();
      //Serial.println("flapStart set");
    }

    if(dir){
      Serial.println("Flap right");
      digitalWrite(_pinB, LOW);
      digitalWrite(_pinA, HIGH);
      timer = millis();
      if(timer - flapStart >= flapTime){
        dir = false; //set dir to opposite dir
        digitalWrite(_pinA, LOW);
        digitalWrite(_pinB, LOW);
        _waiting(bufferTime);  //wait for motor to return to pos 0
      }
    }else{
      Serial.println("Flap left");
      digitalWrite(_pinA, LOW);
      digitalWrite(_pinB, HIGH);
      timer = millis();
      if(timer - flapStart >= flapTime){
        dir = true; //set dir to opposite dir
        digitalWrite(_pinA, LOW);
        digitalWrite(_pinB, LOW);
        _waiting(bufferTime); //wait for motor to return to pos 0
      }
    }
  }
}


void DroneMotor::_waiting(int waitingTime){
  _waitingTime = waitingTime;
  timer = millis();
  _startWaiting = timer;
  while(timer - _startWaiting < _waitingTime){
      timer = millis();
      //Serial.println("waiting");
  }
}

void DroneMotor::motorOn(boolean leftRight){
  if(leftRight){
    if(Serial.available()){Serial.println("Spin right");}
    digitalWrite(_pinB, LOW);
    digitalWrite(_pinA, HIGH);
  }else{
    if(Serial.available()){Serial.println("Spin left");}
    digitalWrite(_pinA, LOW);
    digitalWrite(_pinB, HIGH);
  }
}

void DroneMotor::motorTest(){
  digitalWrite(_pinA, HIGH);
  delay(200);
  analogWrite(_pinA, LOW);
}
