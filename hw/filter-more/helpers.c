#include "helpers.h"
#include <math.h>

#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int avg;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            avg = (int) round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) /
                              3.0);
            image[i][j].rgbtBlue = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtRed = avg;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE current_row[width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            current_row[j].rgbtBlue = image[i][width - j - 1].rgbtBlue;
            current_row[j].rgbtGreen = image[i][width - j - 1].rgbtGreen;
            current_row[j].rgbtRed = image[i][width - j - 1].rgbtRed;
        }
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtBlue = current_row[j].rgbtBlue;
            image[i][j].rgbtGreen = current_row[j].rgbtGreen;
            image[i][j].rgbtRed = current_row[j].rgbtRed;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE new_image[height][width];
    int blue = 0;
    int green = 0;
    int red = 0;
    float count = 0.0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            for (int h_incr = -1; h_incr < 2; h_incr++)
            {
                for (int w_incr = -1; w_incr < 2; w_incr++)
                {
                    if (i + h_incr < 0 || i + h_incr >= height || j + w_incr < 0 ||
                        j + w_incr >= width)
                    {
                        continue;
                    }
                    blue += image[i + h_incr][j + w_incr].rgbtBlue;
                    green += image[i + h_incr][j + w_incr].rgbtGreen;
                    red += image[i + h_incr][j + w_incr].rgbtRed;
                    count++;
                }
            }
            new_image[i][j].rgbtBlue = (int) round(blue / count);
            new_image[i][j].rgbtGreen = (int) round(green / count);
            new_image[i][j].rgbtRed = (int) round(red / count);
            blue = 0;
            green = 0;
            red = 0;
            count = 0.0;
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtBlue = new_image[i][j].rgbtBlue;
            image[i][j].rgbtGreen = new_image[i][j].rgbtGreen;
            image[i][j].rgbtRed = new_image[i][j].rgbtRed;
        }
    }

    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE new_image[height][width];
    int gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    int blue;
    int green;
    int red;

    int gxblue = 0;
    int gyblue = 0;
    int gxgreen = 0;
    int gygreen = 0;
    int gxred = 0;
    int gyred = 0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            for (int h_incr = -1; h_incr < 2; h_incr++)
            {
                for (int w_incr = -1; w_incr < 2; w_incr++)
                {
                    if (i + h_incr < 0 || i + h_incr >= height || j + w_incr < 0 ||
                        j + w_incr >= width)
                    {
                        continue;
                    }
                    gxblue += gx[1 + h_incr][1 + w_incr] * image[i + h_incr][j + w_incr].rgbtBlue;
                    gyblue += gy[1 + h_incr][1 + w_incr] * image[i + h_incr][j + w_incr].rgbtBlue;

                    gxgreen += gx[1 + h_incr][1 + w_incr] * image[i + h_incr][j + w_incr].rgbtGreen;
                    gygreen += gy[1 + h_incr][1 + w_incr] * image[i + h_incr][j + w_incr].rgbtGreen;

                    gxred += gx[1 + h_incr][1 + w_incr] * image[i + h_incr][j + w_incr].rgbtRed;
                    gyred += gy[1 + h_incr][1 + w_incr] * image[i + h_incr][j + w_incr].rgbtRed;
                }
            }
            new_image[i][j].rgbtBlue = MIN((int) round(sqrt(pow(gxblue, 2) + pow(gyblue, 2))), 255);
            new_image[i][j].rgbtGreen =
                MIN((int) round(sqrt(pow(gxgreen, 2) + pow(gygreen, 2))), 255);
            new_image[i][j].rgbtRed = MIN((int) round(sqrt(pow(gxred, 2) + pow(gyred, 2))), 255);
            gxblue = 0;
            gyblue = 0;
            gxgreen = 0;
            gygreen = 0;
            gxred = 0;
            gyred = 0;
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtBlue = new_image[i][j].rgbtBlue;
            image[i][j].rgbtGreen = new_image[i][j].rgbtGreen;
            image[i][j].rgbtRed = new_image[i][j].rgbtRed;
        }
    }

    return;
}
