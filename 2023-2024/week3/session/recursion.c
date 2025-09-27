#include <cs50.h>
#include <stdio.h>

void draw(int);

int main(void)
{
    int height = get_int("Height: ");
    draw(height);
}


void draw(int n)
{
    // base case if nothing to draw
    if (n <= 0)
    {
        return;
    }

    // print pyramid of heright n - 1
    draw(n - 1);

    // print one more row
    for (int i = 0; i < n; i ++)
    {
        printf("#");
    }
    printf("\n");
}
