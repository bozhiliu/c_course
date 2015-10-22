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
    _state.setHeading(0);
    _state.setTimeStamp(0);
    _state.setTireAngle(0);
    _state.setXPos(0);
    _state.setYPos(0);
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
    n.setYPos(ypos_prev + duration*vel*cos(tire_prev)*sin(head_prev));
   
    n.setTireAngle(tire_prev + duration*angle);
    while(n.getTireAngle()<MIN_TIRE_ANGLE)
    {
        n.setTireAngle(MIN_TIRE_ANGLE);
    }
    while(n.getTireAngle()> MAX_TIRE_ANGLE)
    {
        n.setTireAngle(MAX_TIRE_ANGLE);
    }
    
    n.setHeading(head_prev + duration*vel*sin(tire_prev)/L);
    while(n.getHeading() < 0)
    {
        n.setHeading(n.getHeading() + M_TWO_TIMES_PI);
    }
    while(n.getHeading() >= M_TWO_TIMES_PI)
    {
        n.setHeading(n.getHeading() - M_TWO_TIMES_PI);
    }
    
    n.setTimeStamp(u.getTimeStamp()+duration);
    
    
    setState(n);
}