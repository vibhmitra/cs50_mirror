#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

typedef struct node
{
    int number;
    struct node *next;
} node;


int main(void)
{
    node *list = NULL;

    for (int i = 0; i < 3; i++)
    {
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            // TODO: free any memory already malloc'd
            return 1;
        }

        n->number = get_int("Number: ");
        // n->next = NULL;
        // n->next = list;

        // list = n;

        n->next = NULL;

        // if list is empty
        if (list == NULL)
        {
            list = n;
        }

        // if list has number already
        else
        {
            for (node *ptr = list; ptr != NULL; ptr = ptr->next)
            {
                // if at end of list
                if (ptr->next == NULL)
                {
                    ptr->next = n;
                    break;
                }
            }
        }

    }

    // TIme passes
    // OLD PRINT
    // node *ptr = list;
    // while (ptr != NULL)
    // {
    //     printf("%i\n", ptr->number);
    //     ptr = ptr->next;
    // }


    for (node *ptr = list; ptr != NULL; ptr = ptr->next)
    {
        printf("%i\n", ptr->number);
    }

    // SinglyLinkedList
    // O(n) search doin one by one and could be like all steps
    // O(1) insertion just one step
    //

    // Time passes

    node *ptr = list;
    while (ptr != NULL)
    {
        node *next = ptr->next;
        free(ptr);
        ptr = ptr->next;
    }
    return 0;
}

