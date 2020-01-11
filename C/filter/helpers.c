#include "helpers.h"
#include <math.h>

void grayscale(int height, int width, RGBTRIPLE image[height][width]);


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
                int red = round((image[i][j].rgbtRed * 0.393) + (image[i][j].rgbtGreen * 0.769) + (image[i][j].rgbtBlue * 0.189));
                int green = round((image[i][j].rgbtRed * 0.349) + (image[i][j].rgbtGreen * 0.686) + (image[i][j].rgbtBlue * 0.168));
                int blue = round((image[i][j].rgbtRed * 0.272) + (image[i][j].rgbtGreen * 0.534) + (image[i][j].rgbtBlue * 0.232));

                // check to see if the values are between 0 and 255
                // red
                if (red > 255)
                {
                    image[i][j].rgbtRed = 255;
                }
                else if (red < 0)
                {
                    image[i][j].rgbtRed = 0;
                }
                else
                {
                    image[i][j].rgbtRed = red;
                }


                // green
                if (green > 255)
                {
                    image[i][j].rgbtGreen = 255;
                }
                else if (green < 0)
                {
                    image[i][j].rgbtGreen = 0;
                }
                else
                {
                    image[i][j].rgbtGreen = green;
                }


                // blue
                if (blue > 255)
                {
                    image[i][j].rgbtBlue = 255;
                }
                else if (blue < 0)
                {
                    image[i][j].rgbtBlue = 0;
                }
                else
                {
                    image[i][j].rgbtBlue = blue;
                }

            }
        }
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