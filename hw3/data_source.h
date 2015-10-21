//
//  data_source.hpp
//  hw3
//
//  Created by apple on 10/21/15.
//  Copyright © 2015 apple. All rights reserved.
//

#ifndef data_source_hpp
#define data_source_hpp

#include <stdio.h>
#include "Input.h"
#include <stdlib.h>
#include <vector>

using namespace std;

class data_source{
private:
    vector<Input> command_list;
public:
    data_source();
    void data_source_parse(FILE* fin);
    void input_sort();
};



#endif /* data_source_hpp */
