#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int input = 0;
    while(input < 1){
        input = get_double("Enter a value in dollars:\n")* 100;
    }
         
    int quarters = input/25;
    int dimes = (input%25)/10;
    int nickels = ((input%25)%10)/5;
    int pennies = ((input%25)%10)%5;
    int coins = quarters+dimes+nickels+pennies;
    printf("%i\n", coins);
}
