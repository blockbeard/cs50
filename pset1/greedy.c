#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    // initialise output
    int numberofcoins = 0;
    float changerequired;
    int pennies;

    // get changerequired
    do
    {
        printf("How much change is required?\n");
    changerequired = GetFloat();
    }
    while(changerequired <= 0);
    pennies = round(changerequired * 100);
    
    numberofcoins = numberofcoins + pennies/25;
    pennies = pennies%25;
    
    numberofcoins = numberofcoins + pennies/10;
    pennies = pennies%10;
    
    numberofcoins = numberofcoins + pennies/5;
    pennies = pennies%5;
    
    numberofcoins = numberofcoins + pennies/1;
    
    printf("%i\n", numberofcoins);
}
