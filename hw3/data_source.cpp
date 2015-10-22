//
//  data_source.cpp
//  hw3
//
//  Created by apple on 10/21/15.
//  Copyright © 2015 apple. All rights reserved.
//

#include "data_source.h"

data_source::data_source(){
    
}


void data_source::data_source_parse(FILE* fin)
{
    
    double time;
    double vel;
    double angle;
    int ret;
    ret = fscanf(fin, "%lf %lf %lf",&time, &vel, &angle);
    if(ret == 3){
        Input i(vel, angle, time);
        command_list.push_back(i);
    }
}

void data_source::input_sort(){
    
    double it_time, it2_time;
    for(vector<Input>::iterator it = command_list.begin();  it != command_list.end(); it++)
    {
        it_time = it->getTimeStamp();
        for(vector<Input>::iterator it2 = it+1; it2!= command_list.end(); it2++)
        {
            it2_time = it2->getTimeStamp();
            if(it2_time < it_time)
            {
                iter_swap(it, it2);
            }
        }
    }
}

void data_source::show(){
    for(vector<Input>::iterator it = command_list.begin(); it!=command_list.end(); it++)
    {
        printf("%lf %lf %lf\n", it->getTimeStamp(), it->getVelocity(), it->getTireAngleRate());
    }
}

vector<Input> data_source::get_command_list(){
    return command_list;
}

bool data_source::verify(){
    if(command_list[0].getTimeStamp() != 0) return false;
    for(vector<Input>::iterator it = command_list.begin(); it != command_list.end()-1; it++)
    {
        if(abs(it->getTireAngleRate()) >MAX_TIRE_ANGLE_RATE)   return false;
        if(it->getVelocity() < 0 || it->getVelocity()>30)   return false;
        if(it->getTimeStamp() < 0)  return false;
        double curr_time = it->getTimeStamp();
        double next_time = (it+1)->getTimeStamp();
        if(next_time-curr_time < 0.005 || next_time-curr_time>0.201)  return false;
    }
    return true;
}