#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // get the required height
    printf("How big should mario's pyramid be?\n");
        int height;
    do 
    {
        printf("Please enter a height (between 0 and 23)\n");
        height = GetInt();
    }
    while((height <0) || (height >23));
    
    // loop to put # on lines
    int rowcount = 0;
    if (height >0){ 
    do 
    {
        // nested loop to add spaces and #
        int spaces = height - rowcount - 2;
        int n = 0;
        do
        {
            if (n <= spaces)
            {
                printf(" ");
            }
            else {
                printf("#");
            }
        
            n = n + 1;
        }
        while (n <= height);
        
        printf("\n");
        rowcount = rowcount + 1;
    }
    
    while (rowcount < height);
    }
}