#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    int x = get_int("Please enter a value for x: ");
    int y = 34;

    if(x > -2 && x <= 2)
    {
        y = x*x*x;
    }
    else if(x > 2 && x < 200)
    {
        y = x*x - 13*x - 4;
    }

    printf("Y equals %i", y);
}