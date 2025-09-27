#include <stdio.h>

int main(void)
{

    FILE *pFile = fopen("written.txt", "w");

    char text[] = "Apple Gonna\nGoogo Gaga";

    if (pFile == NULL)
    {
        printf("Error opening file!");
        return 1;
    }

    fprintf(pFile, "%s", text);

    printf("File was written successfully!\n");

    fclose(pFile);

    // READ
    pFile = fopen("file.txt", "r");
    char buffer[1024] = {0};   // to temp store data, makes program efficient

    if (pFile == NULL)
    {
        printf("Error opening file!");
        return 1;
    }
    printf("File Contents: \n");
    while(fgets(buffer, sizeof(buffer), pFile) != NULL)
    {
        printf("%s", buffer);
    }

    fclose(pFile);
    return 0;
}
