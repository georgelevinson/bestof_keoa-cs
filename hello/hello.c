#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string input = get_string("Please, enter your name:");
    printf("Hello, %s!\n", input);
}
