//Caesar cipher implementation for CS50 pset2

#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{
    //check for single command line input
    if (argc != 2)
    {
        printf("ERROR: You should have exactly one command line argument!");
        return 1;
    }
    //initialise k
    int k = atoi(argv[1]);
    
    //prompt for plaintext
    //printf("Please enter your plaintext:");
    string plaintext = GetString();
    
    //output cyphertext
    string cyphertext = plaintext;
    for (int i = 0; i < strlen(plaintext); i++)
    {
        if (islower(plaintext[i]))
        {
            int plaincharint = plaintext[i];
            int cyphercharint = ((plaincharint - 97 + k) % 26) + 97;
            char cyphercharchar = cyphercharint;
            cyphertext[i] = cyphercharchar;
        }
        else if (isupper(plaintext[i]))
        {
            int plaincharint = plaintext[i];
            int cyphercharint = ((plaincharint - 65 + k) % 26) + 65;
            char cyphercharchar = cyphercharint;
            cyphertext[i] = cyphercharchar;
        }
        else
        {
            cyphertext[i] = plaintext[i];
        }
        
    }
    printf("%s\n", cyphertext);

    //return 0
    return 0;
}