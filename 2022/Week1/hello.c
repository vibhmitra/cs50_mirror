#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string answer = get_string("Name: ");
    printf("hello, %s!\n", answer);
}