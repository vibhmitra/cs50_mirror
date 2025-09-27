/* Credit Card Problem: */
/*
    Luhn's Algorithm
        1.  Multiply every other digit by 2,
            starting with the number’s second-to-last digit,
            and then add those products’ digits together.
        2.  Add the sum to the sum of the digits that weren’t
            multiplied by 2.
        3.  If the total’s last digit is 0 (or, put more formally,
            if the total modulo 10 is congruent to 0), the number is
            valid!

            David’s Visa: 4003600000000014
            Starting from the Second Last:
                1•2 + 0•2 + 0•2 + 0•2 + 0•2 +   6•2  + 0•2 + 4•2
                 2  +  0  +  0  +  0  +  0  +  1 + 2 +  0  +  8   = 13
            Add This (13) to those number which aren't multiplied by 2:
                13 + 4 + 0 + 0 + 0 + 0 + 0 + 3 + 0 = 20
            The last digit in that sum (20) is a 0, so David’s card is legit!

    Additional Conditions:-
    AMEX    -   Card Length = 15 Digits long.
                Starts with 34 or 37.
    MASTER  -   Card Length = 16 Digits long.
                First two digits 51, 52, 53, 54, 55 or 56.
    VISA    -   Card Length = 15 or 16 Digits long.
                First digits should be 4.
    **Note:- I strictly followed the Week 1 of CS50 (Introduction Class 2023).
*/

#include <cs50.h>
#include <stdio.h>

int get_size(long);
int checksum(long);
void show_card_type(long, int);

int main(void)
{
    /* USER INPUT */
    long card_number = get_long("Number: ");

    /* Checking if Card Size is okay */
    int size = get_size(card_number);
    if (size >= 13 && size <= 16)
    {
        /* calculate checksum */
        int chksum = checksum(card_number);

        /* Check Validity */
        if (chksum % 10 == 0)
        {
            show_card_type(card_number, size);
        }
        else
            printf("INVALID\n");
    }
    else
    {
        printf("INVALID\n");
    }
    return (0);
}

// Get Size of the Card
int get_size(long card)
{
    int size = 0;
    do
    {
        card /= 10;
        size += 1;
    }
    while (card > 0);
    return (size);
}

//  function checksum (uses a modified version of Luhn's Algo)
int checksum(long card)
{
    long alt_card = card / 10;
    int last, mul, sum;

    sum = 0;
    do
    {
        last = card % 10;
        card = card / 100;
        sum += last;

        last = alt_card % 10;
        alt_card = alt_card / 100;
        mul = last * 2; // multiplying the second last digit from 2
        /* Checking if Multiplied digit becomes more than one digit */
        if (mul / 10 != 0)
        {
            last = mul % 10;
            mul /= 10;
            last += (mul % 10);
            sum += last;
        }
        else
            sum += mul;
    }
    while (card > 0 || alt_card > 0);

    return (sum);
}

// funtion to show card type
void show_card_type(long card, int size)
{
    int start;

    // Caculates Starting Two-Digits
    do
    {
        card /= 10;
    }
    while (card > 100);
    start = card;

    // Check for AmericanExpress Cards
    if ((start == 34 || start == 37) && (size == 15))
    {
        printf("AMEX\n");
        return;
    }

    // Check for MasterCard Cards
    if ((start >= 51 && start <= 55) && (size == 16))
    {
        printf("%d", size);
        printf("MASTERCARD\n");
        return;
    }

    // Check for VISA Cards
    if (((start / 10) == 4) && (size == 13 || size == 16))
    {
        printf("VISA\n");
        return;
    }
    else
    {
        printf("INVALID\n");
        return;
    }
}
