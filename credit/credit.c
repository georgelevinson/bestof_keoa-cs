#include <cs50.h>
#include <stdio.h>
#include <math.h>

bool luhn_check(long input, int dcount);
int get_digits(long input);

int main(void){
    long input = get_long("Please enter your card number: ");
    int dcount = get_digits(input);

    if(dcount == 0){
        printf("INVALID\n");
        return 1;
    }

    int fdig = input/pow(10,dcount-2);
    bool luhn = luhn_check(input,dcount);

    if(!luhn){
        printf("INVALID\n");
        return 1;
    }

    if(dcount == 15 && (fdig == 34 || fdig == 37) && luhn){
        printf("AMEX\n");
        return 0;
    }
    if(dcount == 16 && (fdig > 50 && fdig < 56) && luhn){
        printf("MASTERCARD\n");
        return 0;
    }
    if((dcount == 16 || dcount == 13) && (fdig > 39 && fdig < 50) && luhn){
        printf("VISA\n");
        return 0;
    }

    printf("INVALID\n");
    return 1;
}

bool luhn_check(long input, int dcount){
    int sumun = 0;
    int sumev = 0;

    for(int i = 0; i < dcount; i++){
        if(i%2 > 0){
            int value = (input/(long)pow(10, i) % 10) * 2;
            if(value >= 10){
                value = value%10 + value/10;
            }
            sumev += value;
        }
        else{
            sumun += (input/(long)pow(10, i) % 10);
        }
    }
    int result = (sumev + sumun)%10;

    if(result == 0)
    {
        return true;
    }
    else{
        return false;
    }
}
int get_digits(long input){
    // returns 0 for invalid get_digits() values (get_digits(input) > 16 || get_digits(input) < 13)
    for(int i = 13; i <= 16; i++){
        if(input/(long)pow(10,i) < 1){
            return i;
        }
    }
    return 0;
}