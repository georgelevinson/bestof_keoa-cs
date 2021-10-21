#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{
    // reads the last key from argv, converts to int
    // calculates mod 26 (n is supposed to yeild equivalen results to n*(26*m) where m is any int)
    int key = atoi(argv[argc - 1]) % 26;

    // validate the inputs
    if(argc != 2 || !key)
    {
        printf("Usage: ./caesar key");
        return 1;
    }

    // gets the plain text to encrypt and calculates its length
    string ptext = get_string("plain text: ");
    int ptlen = strlen(ptext);
    // cypher text array
    char ctext[ptlen + 1];
    ctext[ptlen] = '\0';

    for(int i = 0; i < ptlen; i++)
    {
        char c = ptext[i];
        // checks if c represents a lowercase letter
        if(islower(c))
        {
            // shifts by key and corrects if it overflows
            c += key;
            if(!islower(c))
            {
                c -= 26;
            }
        }
        // checks if c represents an uppercase letter
        if(isupper(c))
        {
            // shifts by key and corrects if it overflows
            c += key;
            if(!isupper(c))
            {
                c -= 26;
            }
        }

        ctext[i] = c;
    }

    printf("ciphertext: %s\n", ctext);
}