#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int age, a;
    a = 0;
    do
    {   printf("Count: %i \n",a++);
        age = get_int("Age : " );
    } while (age > 32);

}