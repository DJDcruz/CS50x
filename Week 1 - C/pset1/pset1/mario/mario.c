#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //Ask for input & declaring h for whole program to use
    int h;
    do 
    {
         h = get_int("Height: ");
    }
    while (h < 1 || h > 8);
    
    
    //No. of spaces (d) = Height (h) - hashes (j)
    
    //Printing the rows
    int i;
    int j;
    
    for (i = 1; i <= h; i++)
    {
        //Printing the spaces
        for (int d = 0; d < h - i; d++)
        {
            printf(" ");
        }
        
        //Printing the hashes
        for (j = 0; j < i; j++)
        {
            
            printf("#");
        }
        //Making spaces between first pyramid & second pyramid
        for (int s = 0; s < 2; s++)
            {
                printf(" ");
            }
        
        //Creating the second pyramid's rows
        for (j = 0; j < i; j++)
        {
            printf("#");
        }
        
        //Moving to the next line of the pyramid
        printf("\n");
        
        
    }   
    
   
}
