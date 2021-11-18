#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int isoper(int);
int main(int argc, char *argv[])
{
    char **stack = malloc(sizeof(char *) * argc/2);
    char **buffer = malloc(sizeof(char *) * 2);

    int sidx = 0;
    int this = 0;
    int that = 1;
    char curr;

    for(int i = 1; i < argc; i++)
    {
        curr = *argv[i];

        if(isdigit(curr))
        {
            stack[sidx] = argv[i];
            sidx++;
        }
        else if(strcmp(argv[i], "+") || strcmp(argv[i], "-") ||
                strcmp(argv[i], "*") || strcmp(argv[i], "/"))
        {
            this = this % 2;
            that = (this ? 0 : 1);

            if(buffer[that] != NULL)
            {
                buffer[this] = malloc(sizeof(char) * (5 + strlen(stack[sidx - 2]) + strlen(stack[sidx - 1])));
            }
            else
            {
                buffer[this] = malloc(sizeof(char) * 7);
            }

            if(strcmp(argv[i], "+") || strcmp(argv[i], "-"))
            {
                sprintf(buffer[this], "(%s %s %s)", stack[sidx - 2], argv[i], stack[sidx - 1]);
            }
            else
            {
                sprintf(buffer[this], "%s %s %s", stack[sidx - 2], argv[i], stack[sidx - 1]);
            }
            
            stack[sidx - 2] = buffer[this];
                
            stack--;
            this++;
        }
        else
        {
            printf("Invalid argument!");
            return 1;
        }
    }

    printf("%s", buffer[this]);
}
