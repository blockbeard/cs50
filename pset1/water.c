#include <cs50.h>
#include <stdio.h>

int main(void)
{
    printf("How long was your shower?\n");
    int length = GetInt();
    printf("Wow! Your %i minute shower used the equivelent of %i bottles of water!\n", length, length*12);
}