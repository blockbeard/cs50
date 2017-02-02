/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */
 
#include <stdio.h>
#include <stdint.h>
#include <cs50.h>

int main(int argc, char* argv[])
{
     // ensure proper usage
    if (argc != 1)
    {
        fprintf(stderr, "Usage: ./recover filename\n");
        return 1;
    }

    // remember filenames
    char* infile = argv[0];

    // open input file 
    FILE* inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

   

    //TODO declare vars and structs
    typedef uint8_t  BYTE;
    int filenumber = 000;
    char* filename = NULL;
    BYTE block[512];
    
    //TODO read block
    for(int i = 0; i < 512; i++){
        BYTE temp;
    block[i] = fread(&temp, sizeof(BYTE), 1, inptr);
    }
    //TODO check if block is .jpg sig
    //TODO if block is .jpg start close file and open new file
    // open output file
    
    sprintf(filename, "%03i.jpg", filenumber);
    FILE* outptr = fopen(filename, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", filename);
        return 3;
    }
    //TODO write block to open file
    //TODO check if EOF
    //TODO close open file
    
}


 