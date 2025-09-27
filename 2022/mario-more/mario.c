// Week1 - problem 2: Mario-Pyramid-More

#include <cs50.h>
#include <stdio.h>

int     get_size(void);
void    buildit(int);

int main(void)
{
    // ask pyramid size
    int n = get_size();

    //build-pyramid
    buildit(n);
}

// Function for getting size
int get_size(void)
{
    int n;
    do
    {
        n = get_int("Enter Height > ");
    }
    while (n > 8 || n <= 0);
    return n;
}

// Function for building pyramid
void buildit(int size)
{
    size++;

    for (int i = 1; i < size; i++)
    {
        for (int j = size - 1; j > i; j--)
        {
            printf(" ");    // first dots - 1

        }

        for (int k = 0; k < i; k++)
        {
            printf("#");    // first pyramid - 1
        }

        printf("  ");       //two spaces

        for (int l = 0; l < i; l++)
        {
            printf("#");    // second pyramid - 2
        }

        printf("\n");
    }
    return;
}