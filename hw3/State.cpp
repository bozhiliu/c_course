//
//  State.cpp
//  hw3
//
//  Created by apple on 10/21/15.
//  Copyright © 2015 apple. All rights reserved.
//

#include <stdio.h>
#include "stdlib.h"
#include "State.h"


State::State() {
    _xpos = 0;
    _ypos = 0;
    _tire_angle = 0;
    _heading = 0;
    _timestamp = 0;
    
}




State::State(double x1, double x2, double x3, double x4, double timestamp){
    
    _xpos = x1;
    _ypos = x2;
    _tire_angle = x3;
    _heading = x4;
    _timestamp = timestamp;
    
}


double State::getXPos() const{
    return this->_xpos;
}

void State::setXPos(double xpos){
    this->_xpos = xpos;
}

double State::getYPos() const{
    return _ypos;
}

void State::setYPos(double ypos){
    _ypos = ypos;
}

double State::getTireAngle() const{
    return _tire_angle;
}

void State::setTireAngle(double angle){
    _tire_angle = angle;
}

double State::getHeading() const{
    return _heading;
}

void State::setHeading(double heading){
    _heading = heading;
}

double State::getTimeStamp() const{
    return _timestamp;
}

void State::setTimeStamp(double timestamp){
    _timestamp = timestamp;
}