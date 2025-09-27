#include <stdio.h>

void swap(int a, int b);
void swapr(int *a, int *b);

int main(void)
{
    int x = 1;
    int y = 2;

    printf("x is %d and y is %d\n", x, y);
    swapr(&x, &y);
    printf("x is %d and y is %d\n", x, y);

}

// pass by value or pass by copy
void swap(int a, int b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

// pass by reference
void swapr(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
