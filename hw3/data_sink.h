//
//  data_sink.hpp
//  hw3
//
//  Created by apple on 10/21/15.
//  Copyright © 2015 apple. All rights reserved.
//

#ifndef data_sink_hpp
#define data_sink_hpp

#include <stdio.h>
#include <vector>
#include "State.h"
#include <iostream>
#include <fstream>

using namespace std;

class data_sink{
private:
    vector<State> state_list;
public:
    data_sink();
    void record_state(State sin);
    void show();
    void write_output(ofstream& fout);
};

#endif /* data_sink_hpp */
