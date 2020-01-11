#include "helpers.h"
#include <math.h>

void grayscale(int height, int width, RGBTRIPLE image[height][width]);

// Convert image to grayscale
int main (void)
{

    
}

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
    return;
    }

    // Reflect image horizontally
    void reflect(int height, int width, RGBTRIPLE image[height][width])
    {
    return;
    }

    // Blur image
    void blur(int height, int width, RGBTRIPLE image[height][width])
    {
    return;
    }