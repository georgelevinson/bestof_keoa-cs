#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    // reads the last key from argv
    string keystr = argv[argc - 1];
    int keylen = strlen(keystr);

    // validate the inputs
    if(argc != 2)
    {
        printf("Usage: ./caesar key");
        return 1;
    }
    for(int i = 0; i < keylen; i++)
    {
        if(!isalpha(keystr[i]))
        {
            printf("Usage: ./caesar key");
            return 1;
        }
        if(islower(keystr[i]))
        {
            keystr[i] -= 97;
        }
        if(isupper(keystr[i]))
        {
            keystr[i] -= 65;
        }
    }

    // gets the plain text to encrypt and calculates its length
    string ptext = get_string("plain text: ");
    int ptlen = strlen(ptext);
    // cypher text array
    char ctext[ptlen + 1];
    ctext[ptlen] = '\0';

        int j = 0;
    for(int i = 0; i < ptlen; i++)
    {
        char c = ptext[i];
        int key = keystr[j % keylen];
        
        // checks if c represents a lowercase letter
        if(islower(c))
        {
            // shifts by key and corrects if it overflows
            c += key;
            if(!islower(c))
            {
                c -= 26;
            }
            j++;
        }
        else if(isupper(c))
        {
            // shifts by key and corrects if it overflows
            c += key;
            if(!isupper(c))
            {
                c -= 26;
            }
            j++;
        }

        ctext[i] = c;
    }

    printf("ciphertext: %s\n", ctext);
}