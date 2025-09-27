#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string name = get_string("Name > ");
    string number = get_string("Number > ");
    int age = get_int("Age > ");

    printf("User data-:\n");
    printf("Age is %i.\nName is %s.\nNumber is %s.\n", age, name, number);
}
