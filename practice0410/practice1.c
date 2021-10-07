#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void){
    float a = get_float("Please enter the value for a: ");
    float b = get_float("Please enter the value for b: ");
    float c = get_float("Please enter the value for c: ");
    float d = get_float("Please enter the value for d: ");
    float e = get_float("Please enter the value for e: ");
    float h = get_float("Please enter the value for h: ");
    float f = 0;
    while (f == 0)
    {
        f = get_float("Please enter the value for f: ");
    }
    
    float result = 3*h+2*b-e*(a+4*c+d)/f;
    printf("Calculation returns %f, value after decimal point is equal to %f", result, fmod(result,1));
}