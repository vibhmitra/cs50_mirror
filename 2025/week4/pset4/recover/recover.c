#include <cs50.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // Accept a single command-line argument
    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }

    // Open the memory card
    FILE *card = fopen(argv[1], "r");

    // check if file is valid
    if (card == NULL)
    {
        printf("File is invalid!");
        return 2;
    }

    // Create a buffer for a block of data
    uint8_t buffer[512];

    // While there's still data left to read from the memory card
    int image_count = 0;
    FILE *img = NULL;
    // Char filename[8]
    char *filename = malloc(8 * sizeof(char));

    while (fread(buffer, 1, 512, card) == 512)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            if (image_count > 0)
            {
                fclose(img);
            }

            // Create a JPG file using this pattern format
            sprintf(filename, "%03i.jpg", image_count);

            // open output image file
            img = fopen(filename, "w");

            // count images
            image_count++;
        }

        if (img != NULL)
        {
            fwrite(buffer, sizeof(char), 512, img);
        }
    }

    free(filename);
    fclose(img);
    fclose(card);
    return 0;
}
