#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *list = malloc(3 * sizeof(int));

    if (list == NULL)
    {
        return 1;
    }
    // inserting data(sort of)
    list[0] = 1;
    list[1] = 2;
    list[2] = 3;

    // Time passes - user want to increase array size

    int *tmp = realloc(list, 4 * sizeof(int));
    if (tmp == NULL)
    {
        free(list); // free the memory of list because you already allocate list and has some data while you end the program
        return 1;
    }

    // this won't be needed if we use realloc because its takes address of previous memory and just allocate are a new memory of that extra data only.
    for (int i = 0; i < 3; i++)
    {
        tmp[i] = list[i];
    }

    tmp[3] = 4;

    // free mem which is occupied by list before
    free(list);

    list = tmp;

    for (int i = 0; i < 4; i++)
    {
        printf("%d\n",list[i]);
    }

    // Time passes

    free(list);

    return 0;
}
