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
    state_list.push_back(sin);
}