#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            float avg = (image[i][j].rgbtRed + image[i][j].rgbtBlue + image[i][j].rgbtGreen)/3.0;
            image[i][j].rgbtRed = round(avg);
            image[i][j].rgbtBlue = round(avg);
            image[i][j].rgbtGreen = round(avg);
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width]) {
    for (int i = 0; i < height; i++)
{
    for (int j = 0; j < width; j++)
    {
        //gets the values of each color in the image
        int red = image[i][j].rgbtRed;
        int blue = image[i][j].rgbtBlue;
        int green = image[i][j].rgbtGreen;

        // gets the sepia value of the pixels
        int sepiaRed = round(0.393 * red + 0.769 * green + 0.189 * blue);
        if (sepiaRed>255) {
            sepiaRed = 255;
        }
        int sepiaGreen = round(0.349 * red + 0.686 * green + 0.168 * blue);
        if (sepiaGreen>255) {
            sepiaGreen = 255;
        }

        int sepiaBlue = round(0.272 * red + 0.534 * green + 0.131 * blue);
        if (sepiaBlue>255) {
            sepiaBlue = 255;
        }

        image[i][j].rgbtRed = sepiaRed;
        image[i][j].rgbtBlue = sepiaBlue;
        image[i][j].rgbtGreen = sepiaGreen;


    }

}
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width/2; j++) {
            int new_j = width - j - 1;


            RGBTRIPLE tmp = image[i][j];
            *&image[i][j] = *&image[i][new_j];
            *&image[i][new_j] = tmp;

        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE tmpImage[height][width];
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            tmpImage[h][w] = image[h][w];
        }
    }
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            // now we are on a current pixel of image[h][w]
            int reds = 0;
            int blues = 0;
            int greens = 0;
            int availablePixels = 0;
            for (int i = -1; i < 2; i++)
            {
                for (int j = -1; j < 2; j++)
                {
                    // checks the boxes around the pixel by using [-1][-1], [-1][0], [-1][1], ... etc
                    // makes sure we don't go past width/height and 0
                    if ((h + i >= 0 && h + i < height) && (w + j >= 0 && w + j < width))
                    {
                        availablePixels++;
                        reds += tmpImage[h + i][w + j].rgbtRed;
                        greens +=  tmpImage[h + i][w + j].rgbtGreen;
                        blues +=  tmpImage[h + i][w + j].rgbtBlue;
                    }
                }
            }
            // set the current pixel we are on to the avg of the block
            image[h][w].rgbtRed = round(reds / (float) availablePixels);
            image[h][w].rgbtGreen = round(greens / (float)  availablePixels);
            image[h][w].rgbtBlue = round(blues / (float) availablePixels);
        }
    }
}