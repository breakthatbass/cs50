#include "helpers.h"
#include <math.h>
#include <stdio.h>


// prototypes...
void grayscale(int height, int width, RGBTRIPLE image[height][width]);
void sepia(int height, int width, RGBTRIPLE image[height][width]);
void reflect(int height, int width, RGBTRIPLE image[height][width]);
void blur(int height, int width, RGBTRIPLE image[height][width]);


int main (void)
{
    // this file wouldn't compile without the main function...even an empty one!  
} 
    // Convert image to grayscale
    void grayscale(int height, int width, RGBTRIPLE image[height][width])
    {

        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                int avg = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);
                image[i][j].rgbtRed = avg;
                image[i][j].rgbtGreen = avg;
                image[i][j].rgbtBlue = avg;
            }
        }
    }

    // Convert image to sepia
    void sepia(int height, int width, RGBTRIPLE image[height][width])
    {
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                // make the calculations and if the ints go above 255, cap them at 255;
                int rounded_red = round((image[i][j].rgbtRed * 0.393) + (image[i][j].rgbtGreen * 0.769) + (image[i][j].rgbtBlue * 0.189));
                int red = fmin(255, rounded_red);
                int rounded_green = round((image[i][j].rgbtRed * 0.349) + (image[i][j].rgbtGreen * 0.686) + (image[i][j].rgbtBlue * 0.168));
                int green = fmin(255, rounded_green);
                int rounded_blue = round((image[i][j].rgbtRed * 0.272) + (image[i][j].rgbtGreen * 0.534) + (image[i][j].rgbtBlue * 0.131));
                int blue = fmin(255, rounded_blue);

                // assign pixels
                image[i][j].rgbtRed = red;
                image[i][j].rgbtGreen = green;
                image[i][j].rgbtBlue = blue;
            }
        }
    }

    // Reflect image horizontally
    void reflect(int height, int width, RGBTRIPLE image[height][width])
    {
        // get the half of width int
        int half_width = width / 2;
        
        // loop through each pixel
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < half_width; j++)
            {
                RGBTRIPLE temp = image[i][j];
                image[i][j] = image[i][width - 1 - j];
                image[i][width - 1 - j] = temp;
            }
        }
    }

    // Blur image
    void blur(int height, int width, RGBTRIPLE image[height][width])
    {
    return;
    }