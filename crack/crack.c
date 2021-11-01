#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <crypt.h>
#include <string.h>

char* decrypt(char* hash);
char* brute_force(char* hash);

int main(void)
{
    char* static_storage = crypt("aaabc", "50");
    char* hash = malloc(13 * sizeof(char));
    
    for(int i = 0; i < 13; i++)
    {
        hash[i] = static_storage[i];
    }

    char* password = brute_force(hash);

    printf("%s", password);
}

char* brute_force(char* hash)
{
    int counter = 0;
    char *word = malloc(5 * sizeof(char));
    char *salt = malloc(2 * sizeof(char));
    char alph[52];

    salt[0] = hash[0];
    salt[1] = hash[1];
    
    for(int i = 0; i < 26; i++)
    {
        alph[i + 26] = 65 + i;
        alph[i] = 97 + i;
    }
    printf("Alphabet array created\n");

    for(int i = 0; i < 26; i++)
    {
        word[0] = alph[i];

        for(int j = 0; j < 26; j++)
        {
            word[1] = alph[j];

            for(int k = 0; k < 26; k++)
            {
                word[2] = alph[k];

                for(int f = 0; f < 26; f++)
                {
                    word[3] = alph[f];

                    for(int h = 0; h < 26; h++)
                    {
                        word[4] = alph[h];
                        counter++;
                        
                        if(!strcmp(crypt(word, salt), hash))
                        {
                            goto EXIT;
                        }
                        printf("%i keys bf'ed, current attempt is : %s, salt: %s\n", counter, word, salt);
                    }
                }
            }
        }
    }

    EXIT: return word;
}
// typedef struct{
//     char* hash;
//     char *word;
//     int curr;
//     int prev;
//     int depth; 
//     char *alph; 
//     char *salt;
//     int count;
// } brute_args;

// char* brute_rec(brute_args a)
// {
//     for(int i = a.curr; i < 26; i++)
//     {
//         a.word[a.depth] = a.alph[a.curr];
//         a.count++;

//         if(!strcmp(crypt(a.word, a.salt), a.hash))
//         {
//             return a.word;
//         }
//         printf("%i keys bf'ed, current attempt is : %s, salt: %s\n", a.count, a.word, a.salt);

//         a.curr++;
//         a.depth++;
//         return brute_rec(a);
//     }
// }