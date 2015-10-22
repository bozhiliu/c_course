//
//  data_sink.cpp
//  hw3
//
//  Created by apple on 10/21/15.
//  Copyright © 2015 apple. All rights reserved.
//

#include "data_sink.h"

data_sink::data_sink(){
}

void data_sink::record_state(State sin){
    this->state_list.push_back(sin);
}

void data_sink::show(){
    for(vector<State>::iterator it = state_list.begin(); it!=state_list.end(); it++)
    {
        //printf("%lf %lf %lf %lf %lf\n",it->getTimeStamp(), it->getXPos(), it->getYPos(), it->getTireAngle(), it->getHeading());
        cout << it->getTimeStamp() << "," << it->getXPos() << "," << it->getYPos() << "," << it->getTireAngle() << "," << it->getHeading() << endl;
    }
}


void data_sink::write_output(ofstream& fout){
    for(vector<State>::iterator it = state_list.begin(); it != state_list.end(); it++)
    {
        fout << it->getTimeStamp() << "," << it->getXPos() << "," << it->getYPos() << "," << it->getTireAngle() << "," << it->getHeading() << endl;
    }
}