#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    char **stack = (char**) calloc(argc/2, sizeof(char*));
    char *buffer = NULL;
    int sidx = 0;
    char curr;

    for(int i = 1; i < argc; i++)
    {
        curr = *argv[i];

        if(isdigit(curr))
        {
            stack[sidx] = malloc(sizeof(char));
            strcpy(stack[sidx], argv[i]);
            sidx++;
        }
        else if(strcmp(argv[i], "+") || strcmp(argv[i], "-") ||
                strcmp(argv[i], "*") || strcmp(argv[i], "/"))
        {
            buffer = (char*)calloc(5 + strlen(stack[sidx - 2]) + strlen(stack[sidx - 1]), sizeof(char));
            
            sprintf(buffer, "(%s %s %s)", stack[sidx - 2], argv[i], stack[sidx - 1]);
            stack[sidx - 2] = buffer;
            free(stack[sidx - 1]);
            stack--;
        }
        else
        {
            printf("Invalid argument!\n");
            return 1;
        }
    }

    printf("%s", stack[sidx - 1]);
}
