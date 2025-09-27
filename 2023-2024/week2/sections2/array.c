/* Excercise CS50 2023 -- Section2 Powers of Two*/
// 2023-10-30 22:13 IN

/*
Create a program that prompts the user for a size, n.
Dynamically create an array of that size, where each
element is 2 times the previous one.
Start the array at 1.
Print the array, integer by integer. */

#include <cs50.h>
#include <stdio.h>

int get_size(void);

int main(void)
{
    // Get the length
    int length = get_size();

    // Declare our array
    int twice[length];

    // Set the first value
    twice[0] = 1;
    printf("%i\n", twice[0]);

    for (int i = 1; i < length; i++)
    {
        // Make the current element twice the previous element
        twice[i] = 2 * twice[i - 1];
        // Print the current element
        printf("%i\n", twice[i]);
    }
}

int get_size(void)
{
    int length;
    do
    {
        length = get_int("Length: ");
    }
    while (length < 1);
    return (length);
}
