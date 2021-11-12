#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int isoper(int);
int main(int argc, char *argv[])
{
    char **stack = malloc(sizeof(char *) * argc);
    char *etree = malloc(sizeof(char) * (argc - 1));

    int sidx = 0;
    int eidx = 0;

    for(int i = 1; i < argc; i++)
    {
        char c = *argv[i];

        if(isdigit(c))
        {
            stack[sidx] = argv[i];
            sidx++;
        }
        else if(isoper(c))
        {
            if(eidx)
            {
                // etree[eidx] = malloc(sizeof(char) * 7 + strlen(etree[eidx - 1]));
                sprintf(etree, "(%s %s %s)", etree, argv[i], stack[sidx - 1]);
            }
            else
            {
                // etree[eidx] = malloc(sizeof(char) * 7);
                sprintf(etree, "(%s %s %s)", stack[sidx - 2], argv[i], stack[sidx - 1]);
                eidx++;
            }
        }
        else
        {
            printf("Invalid argument!");
            return 1;
        }
    }

    printf("%s", etree);
}

int isoper(int c)
{
    if(c == 42 || c == 43 ||
       c == 45 || c == 47)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
