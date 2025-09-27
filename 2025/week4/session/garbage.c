#include <stdio.h>

int main(void)
{
    int x[1023];

    for (int i = 0; i < 1023; i++)
    {
        printf("%d\n", x[i]);
    }
}
