//Vignere's cipher implementation for CS50 pset2

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
    //check for alpha command line input only
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (!isalpha(argv[1][i]))
        {
            printf("ERROR: You have entered a non alphabetic character in your keyword");
            return 1;
        }
    }
    //initialise k[]
    int k[strlen(argv[1])];
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (islower(argv[1][i]))
        {
            int keychar = argv[1][i] - 97;
            k[i] = keychar;
            
        }
        else if (isupper(argv[1][i]))
        {
            int keychar = argv[1][i] - 65;
            k[i] = keychar;
        }
    }
    
    //prompt for plaintext
    //printf("Please enter your plaintext:");
    string plaintext = GetString();
    
    //output cyphertext
    string cyphertext = plaintext;
    int j = 0;
    for (int i = 0; i < strlen(plaintext); i++)
    {
        if (islower(plaintext[i]))
        {
            int plaincharint = plaintext[i];
            int cyphercharint = ((plaincharint - 97 + k[j]) % 26) + 97;
            char cyphercharchar = cyphercharint;
            cyphertext[i] = cyphercharchar;
            j++;
            if (j == strlen(argv[1]))
            {
                j = 0;
            }
        }
        else if (isupper(plaintext[i]))
        {
            int plaincharint = plaintext[i];
            int cyphercharint = ((plaincharint - 65 + k[j]) % 26) + 65;
            char cyphercharchar = cyphercharint;
            cyphertext[i] = cyphercharchar;
            j++;
            if (j == strlen(argv[1]))
            {
                j = 0;
            }
            
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