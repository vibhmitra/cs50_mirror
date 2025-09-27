// Operators and Integer Size | Interger overflow |Y2K Problem |
// Memory OVERFLOW
#include <stdio.h>
#include <cs50.h>

int main(void)
{
    float x = get_float("What's x? ");
    float y = get_float("What's y? ");

    printf("%.20f\n", x/y);
}
