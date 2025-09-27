# Queue

enqueue
dequeue

FIFO

const CAPACITY = 50;

type struct
{
    person people[CAPACITY];
    int size;
} queue;


# stacks
a
push
pop

FILO

const int CAPACITY = 5-;

typedef struct
{
    person people[CAPACITY];
    int size;
} stack;


---

struct
(.) dot
(*) astrisk
(->) arrow

----

Linked Lists
useing pointer to link part of memory

Kinda like this
[2]  []  [3]
[]  [1]  []

- we are taking twice a space since we are storing in linked list
- but is giving flexibility so thats okay :)

Linked list is like making
- like making a rectangle
- it makes stuff efficiencent
- we are trading off space but we are saving time by not copying everother stuffs to new chunk of memory

               👇 this is just for so that we can use it in making those nodes
typedef struct node
{
    int number;
    node *next;

} node;


---

# Trees
- on list we can not do binary search
- thats why we use binary search tree to easily search.

typedef struct node
{
    int number;
    struct node *left;
    struct node *right;
} node;


bool search(node *tree, int number)
{
    if (tree == NULL)
    {
        return false;
    }
    else if (number < tree->number)
    {
        return search(tree->left, number);
    }
        else if (number > tree->number)
    {
        return search(tree->right, number);
    }
}

- catch with bstree is the balance

// insering O(n) linear
// O(logn)

# Dictionary

word | defination
    or
key  |  value

# Hashing
- takes input produces output

- Hash function
  - Bucket Tie means break the big problem into smaller problem
  - Hash table kinda like array and linked list
  - Think if as of Phonebook A, B, C .. Z division, then each bucket has like multiple names
  - but collision can happen
    typedef struct node
    {
        char *name;
        char *number;
        struct node next;
    } node;

    node *table[26]

    I/P  -> [HASH FN]  -> O/P
    mario -> [HASH FN] -> 12

    int simple_hash(char *word)
    {
        return toupper(Word[0]) - 'A';
    }

    - But if this table becomes big and bigger space will be wasted

    - like we check first few letter to avoid collision but it will become complecated sort of.
    unsigned int hash(const char *word)
    {
        return toupper(Word[0]) - 'A';
    }
    // O(n/k)

    - Ideal Hash function do not have collosion, all hash function tries to approcah O(1) constant time that is.

# Tries
- tree of array
- represent a-z alpha.
- used for large data handling
- we compromise space to get constant o(1) time complexity


typedef struct node
{
    struct node *children[26];
    char *number;
} node;

// tries are fast, hard to implement tho
