#include <stdio.h>

void swap(int *a, int *b);

int main(void)
{
    int x = 1;
    int y = 2;

    printf("x is %d and y is %d\n", x, y);
    swap(&x, &y);
    printf("x is %d and y is %d\n", x, y);

}


// pass by reference
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
