#include <cs50.h>
#include <stdint.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    // TODO: Check first four bytes in given file
    string filename = argv[1];
    FILE *f = fopen(filename, "r");
    uint8_t buffer[4];      // 8 bits , and positive int only and this makes a single byte big-thing
    int blocks = fread(buffer, 1, 4, f); // (where to put, how much long, how many, from where)

    int pdfdna[4] = {37, 80, 68, 70}; // dna of pdf lol
    bool isPDF = false;               // flag

    for (int i = 0; i < 4; i++)
    {
        printf(" %i", buffer[i]);
        if (buffer[i] == pdfdna[i])
            isPDF = true;
        else
            isPDF = false;
    }

    printf("\nBlocks read: %i", blocks);

    (isPDF == true) ? printf("\nYep! that's a pdf mate!\n") : printf("\nNope! not a pdf!\n");

    fclose(f);
    // trying
    return 0;
}
