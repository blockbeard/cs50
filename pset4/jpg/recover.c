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
    //typedef uint8_t  BYTE;
    int filenumber = 0;
    char* filename = (char*) malloc(15);
    uint8_t block[512];
    FILE* outptr = NULL;
    bool started = false;
    
    //read block
    //for(int i = 0; i < 512; i++){
      //  BYTE* temp;
    //fread(&temp, 1, 512, inptr);
    
    
    //TODO check if block is .jpg sig
    while(fread(&block, 1, 512, inptr) == 512)
    {
        //if block is .jpg start close file and open new file
        if (block[0] == 0xff && 
            block[1] == 0xd8 && 
            block[2] == 0xff && 
            (block[3] & 0xf0) == 0xe0)
        {
            // close old outfile
            if (filename != NULL && started == true)
            {
               fclose(outptr);
            }
            started = true;
            sprintf(filename, "%03i.jpg", filenumber);
            //increment filenumber
            filenumber++;
            // open output file   
            outptr = fopen(filename, "w");
            // handle opening error
            if (outptr == NULL)
            {
                fclose(inptr);
                fprintf(stderr, "Could not create %s.\n", filename);
                return 3;
            }
            fwrite(&block, 1, 512, outptr);
        // if 
        }else if (started == true)
        {
            fwrite(&block, 1, 512, outptr);    
        }
        //TODO close open file
    }
        fclose(inptr);
        fclose(outptr);
}