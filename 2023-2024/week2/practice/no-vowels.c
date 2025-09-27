// Problem 2
// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

string replace(string);

int main(int argc, string argv[])
{
    const int cli_argument = 1;

    if (cli_argument == (argc - 1))
    {
        string word;

        word = replace(argv[cli_argument]);

        printf("%s\n", word);

        return (0);
    }
    else
    {
        printf("Program Only Accepts 1 Command-Line Argument\n");
        return (1);
    }
}

string replace(string word)
{
    int size = strlen(word);

    for (int i = 0; i < size; i++)
    {
        switch (word[i])
        {
            case ('a'):
                word[i] = '4';
                break;

            case ('A'):
                word[i] = '4';
                break;

            case ('e'):
                word[i] = '3';
                break;

            case 'E':
                word[i] = '3';
                break;

            case 'i':
                word[i] = '1';
                break;

            case 'I':
                word[i] = '1';
                break;

            case 'o':
                word[i] = '0';
                break;

            case 'O':
                word[i] = '0';
                break;

            case 'u':
                word[i] = 'u';
                break;

            case 'U':
                word[i] = 'U';
                break;
            default:
                word[i] = word[i];
                break;
        }
    }
    return (word);
}
/// 01:21:50
