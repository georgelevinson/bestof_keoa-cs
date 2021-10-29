#include <stdio.h>

int boxes(int, int);
int fulfillment(int, int);
void numbers(int);

int main(void)
{
    printf("We need %i boxes of size 3 to hold 7 items \n", boxes(3, 7));
    printf("We need %i boxes of size 1 to hold 4 items \n", boxes(1, 4));
    printf("We need %i boxes of size 5 to hold 22 items  \n", boxes(5, 22));
    printf("7 items will completely fill %i boxes of size 3 \n", fulfillment(3, 7));
    printf("4 items will completely fill %i boxes of size 1 \n", fulfillment(1, 4));
    printf("22 items will completely fill %i boxes of size 5 \n", fulfillment(5, 22));
    numbers(123);
    numbers(846);
    numbers(590);
}

int boxes(int volume, int objects)
{
    // retruns the amount of boxes needed to containd a given amount of objects based on box volume
    int mod = objects%volume;
    int div = objects/volume;

    if(!mod)
    {
        return div;
    }
    else
    {
        return div + 1;
    }
}

int fulfillment(int volume, int objects)
{
    // returns the amount of boxes af given volume that can be 
    // completely filled with a given amount of objects
    return objects/volume;
}

void numbers(int input)
{
    int a = input / 100;
    int b = (input / 10) % 10;
    int c = input % 10;

    printf("Given: %i, a: %i, b: %i, c: %i \n", input, a, b, c);
}