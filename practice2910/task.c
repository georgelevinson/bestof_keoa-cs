#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int digits[10];
    long input = get_long("Please enter your number: ");
    int sum = 0;

    if(input > 9999999999 || input < 1000000000)
    {
        printf("Invlaid input, must be a 10 digit number\n");
        return 1;
    }

    for(int i = 0; i < 10; i++)
    {
        int curr = (input / (long)pow(10, i)) % 10;

        if(curr % 2 && i != 9)
        {
            sum -= curr;
        }

        digits[i] = curr;
    }

    sum += digits[9];

    if(sum < 0)
    {
        for(int i = 0; i < 10; i++)
        {
            if(!(digits[i] % 3))
            {
                digits[i] = 4;
            }
        }

        long result = 0;

        for(int i = 0; i < 10; i++)
        {
            result += digits[i] * pow(10,i);
        }

        printf("Digits divisible by 3 substituted: %ld\n", result);
    }
    else
    {
        printf("Here are the values that exceed 3: ");

        for(int i = 0; i < 10; i++)
        {
            if(digits[i] > 3)
            {
                printf("%i ", digits[i]);
            }
        }
    }
}