#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // User Input
    string name = get_string("Enter your name >> ");

    // Greetings!
    printf("hello, %s\n", name);
    return (0);
}
