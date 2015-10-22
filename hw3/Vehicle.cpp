//
//  Vehicle.cpp
//  hw3
//
//  Created by apple on 10/21/15.
//  Copyright © 2015 apple. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "Vehicle.h"

Vehicle::Vehicle(){
    
}


void Vehicle::setState(State x){
    _state.setXPos(x.getXPos());
    _state.setYPos(x.getYPos());
    _state.setTireAngle(x.getTireAngle());
    _state.setTimeStamp(x.getTimeStamp());
    _state.setHeading(x.getHeading());
}


State Vehicle::getState() const{
    return _state;
}

void Vehicle::stateUpdate(Input u, double duration){
    double xpos_prev = _state.getXPos();
    double ypos_prev = _state.getYPos();
    double tire_prev = _state.getTireAngle();
    double head_prev = _state.getHeading();
    double vel = u.getVelocity();
    double angle = u.getTireAngleRate();
    
    State n;
    n.setXPos(xpos_prev + duration*vel*cos(tire_prev)*cos(head_prev));
    n.setYPos(ypos_prev + duration*vel*cos(tire_prev)*cos(head_prev));
    
    
    
}