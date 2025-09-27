/* Week 2- pset2 : Bulbs*/
#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{
    string text = get_string("Message:  "); /// <<<< INPUT

    int length = strlen(text);
    int binary[length][BITS_IN_BYTE];

    for (int i = 0; i < length; i++)
    {
        ////// Binanry Conversion
        for (int j = 0; j < BITS_IN_BYTE; j++)
        {
            binary[i][j] = text[i] % 2;
            text[i] = text[i] / 2;
        }

        ////// Printing the Bulbs 🟡
        for (int k = BITS_IN_BYTE - 1; k >= 0; k--)
        {
            print_bulb(binary[i][k]);
        }
        printf("\n");
    }

    return (0);
}

// <<<<< Fuction to Print Bulbs >>>>>
void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
// 2023-11-06T09:28:27 (dur: 2 Hrs)
