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
#include "Vehicle.h"




int main(int argc, const char * argv[]) {
    // insert code here...
    
    FILE * fin  = fopen(argv[1], "r");
    data_source d_source;
    
    while(!feof(fin))
    {
        d_source.data_source_parse(fin);
    }
    d_source.input_sort();

    
    return 0;
}
