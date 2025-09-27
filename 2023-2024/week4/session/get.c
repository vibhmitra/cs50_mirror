#include <stdio.h>

int main(void)
{
    // int n;
    // printf("n: ");
    // scanf("%i", &n);
    // printf("n: %d\n", n);

    // char *s; <- segment fault
    // char s[4]; <- segment fault after 4 mem
    printf("s: ");
    scanf("%s", s);
    printf("s: %s\n", s);
}
