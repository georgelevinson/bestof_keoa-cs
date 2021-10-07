#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height = 0;
    while(height < 1 || height > 8){
        height = get_int("Enter Height:\n");
    }
    for(int length = 1; length <= height; length++){
        for(int space = 1; space <= height - length; space++){
            printf(" ");
        }
        for(int brick = 1; brick <= length; brick++){
            printf("#");
        }
        printf(" ");
        for(int brick = 1; brick <= length; brick++){
            printf("#");
        }
        printf("\n");
    }  
}
