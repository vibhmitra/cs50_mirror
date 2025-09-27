#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(void)
{
    char *s = get_string("s: ");
    if (s == NULL)
    {
        return 1;
    }

    // Hey! OS Give me memory of this size at call that location as a t
    char *t = malloc(strlen(s) + 1);       //
    if (t == NULL)
    {
        return 1;
    }

    // now copy all th data inside that location until you find null character
    for (int i = 0, n = strlen(s); i <= n; i++)
    {
        t[i] = s[i];
    }


    /// All above things can be fixed by using
    // strcpy(s, t);

    if (strlen(t) > 0)
    {
        t[0] = toupper(t[0]);
    }

    printf("%s\n", s);
    printf("%s\n", t);

    free(t);    // It is a good practice to free up the memory time to time

    return 0;
}
