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
    FILE* input_file = fopen(fileName, "r");
    if (input_file == NULL) 
    {   
        //printf("Could not open input files!\n");
        return false;
    }
    int hour,min,ac_index=0;
    float temp;
    while(!feof(input_file))
    {
        fscanf(input_file, "%d:%d %f", &hour, &min, &temp);
        printf("Hour %d Min %d Temp %f\n", hour, min, temp);
        if(ferror(input_file)) return false;
        acTemps[ac_index].temperature = temp;
        acTemps[ac_index].status = false;
        if (temp <0  || temp>99.9) acTemps[ac_index].valid = false;
        else acTemps[ac_index].valid = true;
        acTemps[ac_index].hour = hour;
        acTemps[ac_index].min = min;
        ac_index ++;
    }
    fclose(input_file);
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
    acTemps[0].valid = 1;
    int previous = 0;
    int next = 1;
    while(acTemps[next].status != NULL)
    {
        if(acTemps[previous].status == true)
        {
            if(acTemps[next].temperature > acTemps[previous].temperature+5 || 
                    acTemps[next].temperature < acTemps[previous].temperature-5)
            {
                acTemps[next].valid = false;
                // Moving the indexes
                previous +=1;
                next +=1;
            }
        }
        else
        {
            acTemps[next].valid = true;
            next ++;
            previous++;
        }
        int hour = acTemps[next].hour;
        int min = acTemps[next].min;
        float temp = acTemps[next].temperature;
        bool status = acTemps[next].status;
        printf("Error %2d:%2d %2.3f %d", hour, min, temp, status);
    }
    
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
    int index_current = 1;
    while(acTemps[index_current+1].status!=NULL)
    {
        if(acTemps[index_current-1].status == false)
        {
            if((acTemps[index_current-1].valid == true) && 
                (acTemps[index_current].temperature < acTemps[index_current-1].temperature) &&
                    acTemps[index_current+1].temperature <acTemps[index_current].temperature)
            {
                acTemps[index_current].status = true;
            }
            else
                acTemps[index_current].status = false;
        }
        else 
        {
            if (acTemps[index_current].temperature <= acTemps[index_current-1].temperature)
                acTemps[index_current].status = true;
            else
                acTemps[index_current].status = false;
        }
        
        int hour = acTemps[index_current].hour;
        int min = acTemps[index_current].min;
        float temp = acTemps[index_current].temperature;
        bool status = acTemps[index_current].status;
        printf("Trend %2d:%2d %2.3f %d", hour, min, temp, status);
        
        
        index_current++;
    }
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
    FILE* output_file = fopen(fileName, "w");
    int index = 0;
    if (output_file == NULL) return false;
    while(acTemps[index].status!= NULL)
    {
        int hour = acTemps[index].hour;
        int min = acTemps[index].min;
        float temp = acTemps[index].temperature;
        bool status = acTemps[index].status;
        printf("%2d:%2d %2.3f %d", hour, min, temp, status);
        fprintf(output_file, "%2d:%2d %2.3f %d", hour,min,temp, status);
    }
    return true;
}

/**************************************************************************************************/

