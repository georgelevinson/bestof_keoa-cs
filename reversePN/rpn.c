// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <ctype.h>

// int main(int argc, char *argv[])
// {
//     char **stack = (char**) calloc(argc/2, sizeof(char*));
//     char *buffer = NULL;
//     int sidx = 0;
//     char curr;

//     for(int i = 1; i < argc; i++)
//     {
//         curr = *argv[i];

//         if(isdigit(curr))
//         {
//             stack[sidx] = malloc(sizeof(char));
//             strcpy(stack[sidx], argv[i]);
//             sidx++;
//         }
//         else if(strcmp(argv[i], "+") || strcmp(argv[i], "-") ||
//                 strcmp(argv[i], "*") || strcmp(argv[i], "/"))
//         {
//             buffer = (char*)calloc(5 + strlen(stack[sidx - 2]) + strlen(stack[sidx - 1]), sizeof(char));
            
//             sprintf(buffer, "(%s %s %s)", stack[sidx - 2], argv[i], stack[sidx - 1]);
//             stack[sidx - 2] = buffer;
//             free(stack[sidx - 1]);
//             stack--;
//         }
//         else
//         {
//             printf("Invalid argument!\n");
//             return 1;
//         }
//     }

//     printf("%s", stack[sidx - 1]);
// }

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char stack[50][200];
    int sLayer = 1;
    char *BUFF = (char*)calloc(200, sizeof(char));
    if(argc < 4)
    {
        printf("Syntax: \n\t./expr [a] [b] [Operator]\n");
    }
    else
    {
        for (int i = 0; i < argc - 1; i++)
        {
            char* c = argv[i+1];

            if (isdigit(c[0]))
            {
                strcpy(stack[sLayer], c);
                sLayer++;
            }
            else
            {
                sLayer--;
                char *p1 = stack[sLayer];
                sLayer--;
                char *p2 = stack[sLayer];
                sprintf(BUFF, "(%s %s %s)", p2, c, p1);
                strcpy(stack[sLayer], BUFF);
                sLayer++;
            }
        }

        free(BUFF);
        printf("%s", stack[--sLayer]);
        printf("\n");
    }
   return 0;
}