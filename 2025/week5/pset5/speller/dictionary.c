// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// words
unsigned int words = 0;

// hashed
int hashed;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    hashed = hash(word);

    node *n = table[hashed];
    while (n != NULL)
    {
        if (strcasecmp(word, n->word) == 0)
        {
            return true;
        }
        n = n->next;
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    unsigned int hash_cal = 1;

    for (int i = 0; i < strlen(word); i++)
    {
        // printf("i=%d:c=%c\t", i, word[i]);
        // while(word[i] != '\0')

        hash_cal = hash_cal + tolower(word[i]);

        // printf("%d\t%c\n", hash_cal, word[i]);

        // return 1;
    }

    // printf("%d\n", hash_cal);
    // return toupper(word[0]) - 'A';
    return hash_cal % (N);
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO

    // Open dictionary file
    FILE *source = fopen(dictionary, "r");
    if (source == NULL)
    {
        printf("Could not open dictionary file");
        return false;
    }

    char word[LENGTH + 1];

    // read strings from file one at a time
    while (fscanf(source, "%s", word) != EOF)
    {
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }
        // create a new node for each word
        strcpy(n->word, word);
        // hash word to obtain a hash value
        hashed = hash(word);
        // insert node into hash table at that location
        n->next = table[hashed];
        table[hashed] = n;
        words += 1;
    }

    fclose(source);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    if (words > 0)
    {
        return (words);
    }
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        node *n = table[i];
        while (n)
        {
            node *tmp = n;
            n = n->next;
            free(tmp);
        }
    }
    return true;
}
