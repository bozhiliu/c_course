/**************************************************************************************************/

/*
 * File: tempdata.c
 * Author: Your Name
 * NetID: Your NetID
 * Date:
 *
 * Description: Implementation of functions for operating on the ACTempData structure.
 *              Note that the LowPassFilter fcn has been moved to filter.{h,c}
 *
 */

/**************************************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include "bool.h"
#include "tempdata.h"

/**************************************************************************************************/

/* Reads tempertures from an input file specified by fileName line-by-line using the format:
 *
 *    HH:MM TT.T
 *
 * HH:MM represents the time at which the temperature was recorded and is specific in 24 hour
 * format.
 *
 * TT.T represents the recorded temperature reported in Fahrenheit as a double precision value.
 *
 * The time and temperature will be separated by one or more whitespace characters.
 *
 * All lines that do not exactly match this format will be ignored.
 *
 * Returns false if the specified file could not be opened, and true otherwise.
 *
 */
bool ReadTempDataFromFile(ACTempData acTemps[], char *fileName)
{
   return true;
}

/**************************************************************************************************/

/*
 * Remove any erroneous temperature readings. An error temperature reading is defined as a
 * temperature reading that is either more than 5 degrees above or 5 below the temperature
 * recorded in the previous minute. All erroneous temperature readings should be marked as invalid.
 * The first element read in from a file is always considered valid.
 */
void RemoveErroneousData(ACTempData acTemps[])
{
   
}

/**************************************************************************************************/

/*
 * Analyzes the sequence of valid temperatures to determine the state of the AC. If a non-valid
 * temperature reading is found, the trend extraction should restart at the next valid temperature
 * reading. Trend extraction analysis operate as follows:
 *
 * 1. The AC status for the first entry in a sequence of valid reading is always Off.
 *
 * 2. For a valid temperature reading that does not start a sequence:
 *
 *    A. If the previous AC status was Off, then consider the following: If (1) the previous 
 *       temperature is valid, and (2) the current temperature is less than the previous temperature, 
 *       and (3) the next temperature is valid and less than the current temperature, then the AC 
 *       status for the current temperature will be On.
 *
 *    B. If the previous AC status was On, then consider the following: If the current temperature 
 *       is less than or equal to the previous temperature, then the AC status for the current 
 *       temperature will be On
 *
 *    C. Otherwise, the AC status for the current temperature will be Off.
 *
 */
void TrendExtraction(ACTempData acTemps[])
{
   
}

/**************************************************************************************************/

/* Writes all valid tempertures readings and AC status to an output file specified by fileName
 * using the format:
 *
 *    HH:MM TT.TTT AC
 *
 * HH:MM reports the time at which the temperature was recorded specified in 24 hour format.
 *
 * TT.TTT represents the filtered temperature value in Fahrenheit as a double precision value with
 * three decimal digits of precision.
 *
 * AC reports the determined status of the air conditioner, where a 0 represents the the AC
 * was Off and a 1 represents the AC was On.
 *
 * Each entry is separated by a single tab character (\t).
 *
 * Retruns false if the specified file could not be written to, and true otherwise.
 *
 */
bool WriteTempDataToFile(ACTempData acTemps[], char *fileName)
{
   return true;
}

/**************************************************************************************************/

