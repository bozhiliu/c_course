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
	
}

