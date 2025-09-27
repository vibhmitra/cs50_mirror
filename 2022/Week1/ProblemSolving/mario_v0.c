// Online C compiler to run C program online
#include <stdio.h>

int main()
{
    // Write C code here

    int size = 8;
    size++;

    for(int i = 1; i < size; i++)
    {
        for(int j = size-1; j > i; j--)
        {
            printf(" "); // first dots - 1

        }

        for(int k = 0; k < i; k++)
        {
            printf("#"); // first pyramid - 1
        }

        printf("  ");

        for(int l = 0; l < i; l++)
        {
            printf("#"); // second pyramid - 2
        }

        printf("\n");
    }

    return 0;
}