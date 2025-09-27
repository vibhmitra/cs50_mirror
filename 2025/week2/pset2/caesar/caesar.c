// Week 2 - psets2 - caesor cipher.
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_key(int, string[]);
string caesar_cipher(string, int);

int main(int argc, string argv[])
{
    /* TODO:
    1. Get Key      DONE
    2. Get String   DONE
    3. Cipher it.   DONE
    4. Print It     DONE
    */

    int key = get_key(argc, argv);
    if (!(key < 0))
    {
        string plaintext = get_string("plaintext: ");
        string cipher = caesar_cipher(plaintext, key);
        printf("ciphertext: %s\n", cipher);
    }
    else
    {
        return (1); // <<<<< Returning (1) as error code back to console.
    }

    return (0);
}

/* Function to Validate and Get Key */
int get_key(int argc, string argv[])
{
    int key, length;

    if (argc == 2)
    {
        length = strlen(argv[1]);

        // Check If Strinng Contains alphabet
        for (int i = 0; i < length; i++)
        {
            if (!isdigit(argv[1][i]))
            {
                printf("Usage: ./caesar KEY\n");
                return (-1);
            }
        }

        key = (atoi(argv[1])); // Converting KEY form String to Integer.
    }
    else
    {
        printf("Usage: ./caesar KEY\n");
        return (-1);
    }
    return (key);
}

/*CAESAR CIPHER Fucntion that takes plane text, key and return ciphered text.*/
string caesar_cipher(string text, int key)
{
    int set_index, lower_caps, upper_caps;
    int cipher_index;
    int length = strlen(text); // Getting Strings Length;
    upper_caps = 65;           // <<<<< Setting lower ASCII Magic Number
    lower_caps = 97;           // <<<<< Setting upper Case ASCII Magic Number

    string cipher_text;

    // Manupulation Function;
    for (int i = 0; i < length; i++)
    {
        if (isalpha(text[i]))
        {
            // Setting Starting Index <<<<<<<<
            if (isupper(text[i]))
                set_index = upper_caps;
            if (islower(text[i]))
                set_index = lower_caps;

            // Caesor Cipher Logic <<<<<<<<
            text[i] = text[i] - set_index;
            cipher_index = (text[i] + key) % 26;
            text[i] = set_index + cipher_index;
        }
        else
            text[i] = text[i];
    }
    return (text);
}
// 20231104T23:20:20IN (dur : 07 Hrs Approx.)
