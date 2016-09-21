#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    //get the name
    string name = GetString();
    
    //print the initials
    //first initial is first letter
    printf("%c", toupper(name[0]));
 
    //then letters after spaces
    for(int i = 0; i < strlen(name); i++)
    {
        if (isspace(name[i]) && (i+1) < strlen(name))
        {
          printf("%c", toupper(name[i + 1]));
        }
    }
    //newline
    printf("\n");
}