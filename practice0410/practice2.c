#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void){
    float v1 = 0;
    float v2 = 0;
    float t1 = 0;
    float t2 = 0;

    while(v1 <= 0){
        v1 = get_float("Please enter value for V1: ");
    }
    while(t1 <= 0 || t1 >= 100){
        t1 = get_float("Please enter value for V1 water temperature between 0 and 100 degrees Celsius: ");
    }
    while(v2 <= 0){
        v2 = get_float("Please enter value for V2: ");
    }
    while(t2 <= 0 || t2 >= 100){
        t2 = get_float("Please enter value for V2 water temperature between 0 and 100 degrees Celsius: ");
    }

    printf("Temperature of the mixture is %f degrees, volume is %f", (t1*v1 + t2*v2)/(v1+v2), v1+v2);
}