#include <cs50.h>
#include <stdio.h>

// decleration.
int get_start(void);
int get_end(int);
int get_threshold_year(int, int);

int main(void)
{
    // TODO: Prompt for start size
    int start = get_start();

    // TODO: Prompt for end size
    int end = get_end(start);

    // TODO: Calculate number of years until we reach threshold
    int threshold_year = get_threshold_year(start, end);
    // TODO: Print number of years
    printf("Years: %i\n", threshold_year);
    return(0);
}

// Function to get Starting Year
int get_start(void)
{
    int input;
    do
    {
        input = get_int("Enter Starting Population: ");
    }
    while(input < 9);
    return(input);
}

// Function to get ending year.
int get_end(int start)
{
    int input;
    do
    {
        input = get_int("Enter Ending Population: ");
    }
    while(input < start);
    return(input);
}

// Function to do caculation.
int get_threshold_year(start, end)
{
    int total, year;
    year = 0;
    total = start;
    while(total < end)
    {
        total = start + (start / 3) - (start / 4);
        year += 1;
        start = total;
    };
    return(year);
}