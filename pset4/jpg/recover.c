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
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover filename\n");
        return 1;
    }

    // remember filenames
    char* infile = argv[1];

    // open input file 
    FILE* inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

   

    //declare vars and structs
    typedef uint8_t  BYTE;
    int filenumber = 000;
    char* filename = NULL;
    BYTE block[512];
    FILE* outptr = NULL;
    
    //read block
    for(int i = 0; i < 512; i++){
        BYTE temp;
    block[i] = fread(&temp, sizeof(BYTE), 1, inptr);
    }
    
    //TODO check if block is .jpg sig
    if (block[0] == 0xff && block[1] == 0xd8 && block[2] == 0xff && (block[3] == 0xe0 | block[3] == 0xe1 | block[3] == 0xe2 | block[3] == 0xe3 | block[3] == 0xe4 | block[3] == 0xe5 | block[3] == 0xe6 | block[3] == 0xe7 | block[3] == 0xe8 | block[3] == 0xe9 | block[3] == 0xea | block[3] == 0xeb | block[3] == 0xec | block[3] == 0xed | block[3] == 0xee | block[3] == 0xef))
    {
        printf("if fired");
    //if block is .jpg start close file and open new file
        sprintf(filename, "%03i.jpg", filenumber);
       if (filename != NULL)
       {
           fclose(outptr);
       }
    
    // open output file   
    outptr = fopen(filename, "w");
    filenumber++;
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", filename);
        return 3;
    }
    fwrite(&block, sizeof(block), 1, outptr);
    }else if (filename != NULL){
        printf("else fired");
    fwrite(&block, sizeof(block), 1, outptr);    
    }
    
    
    //TODO check if EOF
    //TODO close open file
    
}


 