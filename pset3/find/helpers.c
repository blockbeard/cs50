/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
 
#include <stdio.h>
bool search(int value, int values[], int n)
{
    //binary search
    int length = n;
    int startpos = 0; 
    int endpos = n - 1;
    
    while (length > 0)
    {
        printf("\nStartpos = %i, endpos = %i\n", startpos, endpos);
        for(int i = startpos; i < endpos; i++)
        {
            printf("%i ", values[i]);
        }

        if (values[startpos + ((endpos - startpos)/2)] == value)
            {
                return true;
            }
        
        
        else if(values[startpos + ((endpos-startpos)/2)] > value)
        {
            endpos = (endpos-startpos)/2;
        }
        else if(values[startpos + ((endpos-startpos)/2)] < value)
        {
            startpos = n/2;
        }
        length = endpos - startpos;
    }
    return false;
    }
    /*
    // linear search
    for (int i = 0; i < n; i++)
    {
        if (value == values[i])
        return true;
    }
    return false;
    */


/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // bubble sort
    int sortlength = n-1;
    for (int j = 0; j < n-1; j++){
        for (int i = 0; i < sortlength; i++)
        {
           if (values[i] > values[i + 1])
           {
              int temp = values[i];
              values[i] = values[i+1];
             values[i+1] = temp;
            }
            
        }
        sortlength--;
    }
    return;
}