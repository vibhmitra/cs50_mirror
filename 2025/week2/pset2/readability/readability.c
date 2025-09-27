/*
    Week2-PSET2: Readability:
    start time: 2023-11-01T13:11:48IN
*/

#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int readability(string);

int main(void)
{
    string text;

    // User Input
    do
    {
        text = get_string("Text: ");
    }
    while (!(isalpha(text[0])));

    // Getting Grade / Index
    int grade = readability(text);

    // Comparing Grades
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }

    return (0);
}

/* Function to calculate readability */
int readability(string text)
{
    // Initializing Variables
    int length = strlen(text);
    int letters, words, sentences;
    float L, S;

    // Setting Pre-values
    letters = sentences = L = S = 0;
    words = 1;

    // Counting Letters, Words & Senentces
    for (int i = 0; i < length; i++)
    {
        if (isalpha(text[i]))
        {
            letters += 1;
        }

        if (text[i] == ' ')
        {
            words += 1;
        }

        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences += 1;
        }
    }

    /* Coleman-Liau Index Logic*/

    // Calculation L and S.
    L = ((float) letters / (float) words) * (100.0);
    S = ((float) sentences / (float) words) * (100.0);

    // formula implimentation
    float index = (0.0588 * L) - (0.296 * S) - 15.8;

    return (round(index));
}

// dur-03:08:41
