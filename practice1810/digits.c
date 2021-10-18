#include <stdio.h>
#include <cs50.h>
#include <math.h>

int get_digits(long input);

int main(void)
{
    long input = get_long("Please enter your number: ");
    int length = get_digits(input);
    int digits[19];
    int trg;

    for(int i = 0; i < length; i++)
    {
        int digit = (input/(long)pow(10, i) % 10);
        digits[i] = digit;

        // remove (trg == 0) condition to prioritize left-most combination
        if(i != 0 && trg == 0 && digit == 7 && digits[i - 1] == 7)
        {
            trg = i;
        }
    }

    if(trg + 1 == length)
    {
        printf("Input length equals %i, calculation result is %f", length, digits[trg - 2]/2.0);
    }
    else if(trg != 0)
    {
        printf("Input length equals %i, calculation result is %i", length, digits[trg + 1] * 10);
    }
    else
    {
        printf("Input length equals %i", length);
    }

    return 0;
}

int get_digits(long input)
{
    for(int i = 1; i <= 19; i++)
    {
        if(input/(long)pow(10,i) < 1)
        {
            return i;
        }
    }
    return 0;
}