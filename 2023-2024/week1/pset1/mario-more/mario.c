#include <cs50.h>
#include <stdio.h>

// Declaration
int get_size(void);
void print_pyramid(int);

int main(void)
{
    // Get Size
    int size = get_size();

    // Print Pyramid
    print_pyramid(size);
}

/// Function to get size of pyramid
int get_size(void)
{
    int size;
    do
    {
        size = get_int("Height: ");
    }
    while(size < 1 || size > 8 );
    return(size);
}

// Function to print  Pyramid
void print_pyramid(int size)
{
    for(int i = 0; i < size; i++)
    {

        // loop building invisble spaces block.
        for(int j = size-1; j > i; j--)
        {
            printf(" ");
        }
        // loop for building the first block.
        for(int k = 0; k <= i; k++)
        {
            printf("#");
        }
        printf("  ");  // adding two space between two blocks.

        // loop for building the second block.
        for(int l = 0; l <= i; l++)
        {
            printf("#");
        }
        printf("\n");
    }
    return;
}