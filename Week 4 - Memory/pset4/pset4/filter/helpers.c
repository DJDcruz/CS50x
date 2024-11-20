#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //Average of all RGB to get the best suited gray
            int average = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0); 
            
            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtRed = average;
        }
    }
    
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //Creating copies of the original unmodified values
            int originalRed = image[i][j].rgbtRed;
            int originalBlue = image[i][j].rgbtBlue;
            int originalGreen = image[i][j].rgbtGreen;
            
            //Inserting the sepia formula
            int sepiaRed = round(.393 * originalRed + .769 * originalGreen + .189 * originalBlue);
            int sepiaGreen = round(.349 * originalRed + .686 * originalGreen + .168 * originalBlue);
            int sepiaBlue = round(.272 * originalRed + .534 * originalGreen + .131 * originalBlue);
            
            //Capping the sepiaRGB to the max & least values 
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }
            
            if (sepiaRed < 0)
            {
                sepiaRed = 0;
            }
            
            if (sepiaGreen < 0)
            {
                sepiaGreen = 0;
            }
            
            if (sepiaBlue < 0)
            {
                sepiaBlue = 0;
            }
            
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
            
        }
    }
    
    return;
}

//Swap Function to replace 2 pixels in the reflect function
void swap(RGBTRIPLE *a, RGBTRIPLE *b)
{
    RGBTRIPLE tmp = *a;
    *a = *b;
    *b = tmp;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {   
        // Since we'll be swapping two pixels at a time, we only need to iterate over half the width of the image
        for (int j = 0; j < width / 2; j++) 
        {
            swap(&image[i][j], &image[i][width - j - 1]); //Passing in the address of which to switch the two pixels
        }
    }
    
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width]; //Since we'll be blurring each pixel, We'll need to create a copy of the image that has unmodified values
    
    float red = 0;
    float green = 0;
    float blue = 0;
    int counter = 0;
    
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            
            for (int row = i - 1; row < i + 2 && row < height; row++)
            {
                for (int column = j - 1; column < j + 2 && column < width; column++)
                {   
                    red += image[row][column].rgbtRed;
                    green += image[row][column].rgbtGreen;
                    blue += image[row][column].rgbtBlue; 
                    counter++;             
                }
            }
            
            copy[i][j].rgbtRed = (int)round(red / counter);
            copy[i][j].rgbtGreen = (int)round(green / counter);
            copy[i][j].rgbtBlue = (int)round(blue / counter);
            
        }
    }
    //Changing the original image's values to the copy's values   
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = copy[i][j];
        }
    }
    return;
}
