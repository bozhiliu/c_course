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
