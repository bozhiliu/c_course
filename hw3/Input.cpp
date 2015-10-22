//
//  Input.cpp
//  hw3
//
//  Created by apple on 10/21/15.
//  Copyright © 2015 apple. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "Input.h"

Input::Input(){
    _velocity = 0;
    _tire_angle_rate = 0;
    _timestamp = 0;
}


Input::Input(double vel, double tireAngleRate, double timestamp){
    _velocity = vel;
    _tire_angle_rate = tireAngleRate;
    _timestamp = timestamp;
}


double Input::getVelocity() const{
    return _velocity;
}

void Input::setVelocity(double vel){
    _velocity = vel;
}

double Input::getTireAngleRate() const{
    return _tire_angle_rate;
}

void Input::setTireAngleRate(double angle){
    _tire_angle_rate = angle;
}

double Input::getTimeStamp() const{
    return _timestamp;
}

void Input::setTimeStamp(double timestamp){
    _timestamp = timestamp;
}