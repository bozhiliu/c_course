//
//  data_source.cpp
//  hw3
//
//  Created by apple on 10/21/15.
//  Copyright © 2015 apple. All rights reserved.
//

#include "data_source.h"


void data_source::data_source_parse(FILE* fin)
{
    
    double time;
    double vel;
    double angle;
    fscanf(fin, "%lf %lf %lf",&time, &vel, &angle);
    Input i(vel, angle, time);
    command_list.push_back(i);
    
}

void data_source::input_sort(){
    float it_time, it2_time;
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