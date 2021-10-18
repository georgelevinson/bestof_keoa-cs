#include <stdio.h>
#include <cs50.h>

int main(void)
{
    float sum = 0;
    float min;
    float max;

    for(int i = 0; i < 4; i++)
    {
        float input = get_float("Please enter the value #%i: ", i + 1);
        sum += input;

        if(i == 0 || input > max)
        {
            max = input;
        }
        if(i == 0 || input < min)
        {
            min = input;
        }
    }

    printf("Min value = %f, max value = %f, avg = %f, ", min, max, sum/4);
}