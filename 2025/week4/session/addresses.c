#include <stdio.h>

int main(void)
{
    int n = 50;
    int *p = &n;    // this is just for declaring pointers
    printf("%p\n", &n);
    printf("%p\n", p);

    printf("%i\n", *p); // here *p represents dereferencing or go there

    char *s = "HI!"; // typedef char *string; <- this is what is in the CS50.h
    printf("%s\n", s);

    printf("%c\n", s);      // similar to printf("%c", s[0]);
    printf("%c\n", *(s+1)); // similar to printf("%c", s[1]);
    printf("%c\n", *(s+2)); // similar to printf("%c", s[2]);
}
