/**************************************************************************************************/

/*
 * File: filter.c
 * Author: Your Name
 * NetID: Your NetID
 * Date:
 *
 * Description: Implementation of low-pass filter. This file is the only file that need by submitted
 * as part of the "alpha" for this assignment.
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include "filter.h"

/*
 * Applies a low-pass filter to sequences of valid temperature readings for consecutive times.
 * If a non-valid temperature reading is found, the filter should restart at the next valid
 * temperature reading. The following describes the low-pass filter used:
 *
 *    filtered_output(0) = unfiltered_input(0)
 *    filtered_output(n) = 0.9250 * filtered_output(n-1) + 0.0750 * unfiltered_input(n)
 *
 */
void LowPassFilter(ACTempData acTemps[])
{
    double filtered_output_previous = acTemps[0].temperature;
    double filtered_output_current = 0;
    const double coe1 = 0.9250;
    const double coe2 = 0.0750;
    int index=1;
    while(Struct_condition(acTemps[index])==true)
    {
        if(acTemps[index].valid == false)
        {
            filtered_output_previous = acTemps[index+1].temperature;
            index++;
            continue;
        }
	if(acTemps[index].valid == true && acTemps[index-1].valid == true)
	  {
	    if((acTemps[index].min == (acTemps[index-1].min+1)) || (acTemps[index].min ==0 && acTemps[index-1].min == 59 && acTemps[index].hour == acTemps[index-1].hour+1)) 
	      {
		printf("Filtered %02d:%02d\n",acTemps[index].hour, acTemps[index].min);
		filtered_output_current = acTemps[index].temperature * coe2 + filtered_output_previous*coe1;
		acTemps[index].temperature = filtered_output_current;
		filtered_output_previous = filtered_output_current;
		index++;
		continue;
	      }
	    else
	      {
		printf("Wait1 %d\n", index);
	        filtered_output_previous = acTemps[index].temperature;
		index++;
		continue;
	      }
	  }
	else
	  {
	    printf("Wait2 %d\n", index);
	    filtered_output_previous = acTemps[index].temperature;
	    index++;
	    continue;
	  }
    }
}

