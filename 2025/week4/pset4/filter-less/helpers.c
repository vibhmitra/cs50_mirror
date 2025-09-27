#include "helpers.h"
#include <math.h>
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float avgColor;
    // Loop over all pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Take average of red, green, and blue
            avgColor =
                round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);
            // Update pixel values
            image[i][j].rgbtRed = avgColor;
            image[i][j].rgbtGreen = avgColor;
            image[i][j].rgbtBlue = avgColor;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop over all pixels
    float sepiaRed, sepiaBlue, sepiaGreen;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Compute sepia values
            sepiaRed = (int) round(0.393 * image[i][j].rgbtRed + 0.769 * image[i][j].rgbtGreen +
                                   0.189 * image[i][j].rgbtBlue);
            sepiaGreen = (int) round(0.349 * image[i][j].rgbtRed + 0.686 * image[i][j].rgbtGreen +
                                     0.168 * image[i][j].rgbtBlue);
            sepiaBlue = (int) round(0.272 * image[i][j].rgbtRed + 0.534 * image[i][j].rgbtGreen +
                                    0.131 * image[i][j].rgbtBlue);

            // Update pixel with sepia values

            // checking if threshold limit is crossed
            if (sepiaBlue > 255)
                sepiaBlue = 255.0;
            if (sepiaGreen > 255)
                sepiaGreen = 255.0;
            if (sepiaRed > 255)
                sepiaRed = 255.0;

            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp;
    // Loop over all pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            // Swap pixels
            temp = image[i][j];
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Create a copy of image
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    // Blur
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int red_sum = 0;
            int green_sum = 0;
            int blue_sum = 0;
            int count = 0;

            // Calculate average color values within 3x3 neighborhood
            for (int x = i - 1; x <= i + 1; x++)
            {
                for (int y = j - 1; y <= j + 1; y++)
                {
                    if (x >= 0 && x < height && y >= 0 && y < width)
                    {
                        red_sum += copy[x][y].rgbtRed;
                        green_sum += copy[x][y].rgbtGreen;
                        blue_sum += copy[x][y].rgbtBlue;
                        count++;
                    }
                }
            }

            image[i][j].rgbtRed = round(red_sum / (float) count);
            image[i][j].rgbtGreen = round(green_sum / (float) count);
            image[i][j].rgbtBlue = round(blue_sum / (float) count);
        }
    }
    return;
}
