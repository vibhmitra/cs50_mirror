/*CS50 Section 2: Exercise 2: 2023-10-30
Check if a lowercase string's characters are
in alphabetical order. If yes, print "Yes". If no, print "No".

a = 97
b = 98
c = 99
....

 */
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string word = get_string("Word: ");
    int length = strlen(word);

    for(int i = 0; i < length - 1 ; i++)
    {
        if(word[i] > word[i+1])
        {
            printf("No\n");
            return 0;
        }
    }

    printf("Yes\n");
    return 0;
}
