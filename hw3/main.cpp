//
//  main.cpp
//  hw3
//
//  Created by apple on 10/21/15.
//  Copyright © 2015 apple. All rights reserved.
//

#include <iostream>
#include "data_source.h"
#include "State.h"
#include "Input.h"
#include "Vehicle.h"
#include "data_sink.h"
#include <iostream>
#include <fstream>


int main(int argc, const char * argv[]) {
    // insert code here...
    
    FILE * fin  = fopen(argv[1], "r");
///    FILE * fout = fopen(argv[2], "w");
    ofstream fout;
    fout.open(argv[2]);
    data_source d_source;
    while(!feof(fin))
    {
        d_source.data_source_parse(fin);
    }
    d_source.input_sort();
    bool input_valid = d_source.verify();
    d_source.show();
    printf("###################################\n");
    
    if(input_valid == true)
    {
        data_sink d_sink;
        Vehicle car;
        vector<Input> c_list = d_source.get_command_list();
        for (vector<Input>::iterator it = c_list.begin(); it != c_list.end(); it++)
        {
            double curr_time = it->getTimeStamp();
            double next_time = (it+1)->getTimeStamp();
            double duration = -curr_time + next_time;
            if (it != c_list.end()-1)
                car.stateUpdate(*(it), duration);
            else    
                car.stateUpdate(*it, 0.2);
            d_sink.record_state(car.getState());
            cout << "## " << curr_time << endl; 
        }
        d_sink.show();
     //   fout << "test" << endl;
        d_sink.write_output(fout);
    }
    fclose(fin);
    fout.close();
 
 
 
    return 0;
}
