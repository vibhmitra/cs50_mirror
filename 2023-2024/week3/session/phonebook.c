#include <cs50.h>
#include <stdio.h>
#include <string.h>

// define a structure to resolve problem of scalability
typedef struct
{
    string name;
    string number;
} person;

int main(void)
{

    person people[3];

    people[0].name = "Kim";
    people[0].number = "+1-654-765-2543";
    people[1].name = "Minhye";
    people[1].number = "+1-643-543-8753";
    people[2].name = "Zu";
    people[2].number = "+1-243-453-3670";

    string name = get_string("Name: ");
    for (int i =0; i < 3; i++)
    {
        if (strcmp(people[i].name, name) == 0)
        {
            printf("Found %s\n", people[i].number);
            return 0;
        }
    }
    printf("Not Found!");
    return 1;
}
