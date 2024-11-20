#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{   
    //Incorrect syntax
    if (argc != 2)
    {
        printf("Usage ./recover <image>");
        return 1;
    }
    
    //Opening the specified file from command-line 
    FILE *input = fopen(argv[1], "r");
    if (!input)
    {
        printf("Error occured opening file");
        return 1;
    }
    
    int file_number = 0;
    char file_name[50];
    BYTE buffer[512]; //We will check in blocks of 512 bytes since this card uses the FAT system
    int counter = 0;
    FILE *output = NULL;  
    
    while (fread(&buffer, sizeof(BYTE), 512, input)) //Reading the memory card's blocks on loop
    {
        //If the signatures for a jpeg is found
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && ((buffer[3] & 0xf0) == 0xe0)) 
        {
            if (output != NULL) //If the output file is open while the jpeg is found, close output file
            {
                fclose(output);
            }
            //If a new jpeg file is found, open it
            sprintf(file_name, "%03i.jpg", counter);
            output = fopen(file_name, "w");
            counter++;
        }
    
        if (output != NULL) //If The output file is open, starting writing the data to the output file from the memory card
        {
            fwrite(&buffer, sizeof(buffer), 1, output);
        }
    }
}