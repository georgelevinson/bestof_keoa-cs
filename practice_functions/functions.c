#include <stdio.h>
#include <stdlib.h>

struct Matrix
{
    int width;
    int height;
    int *ptr;
};
float sum(float a, float b);
float diff(float a, float b);
float prod(float a, float b);
int factorial(int a);
float divide(float a, float b);
void mtrx_print(struct Matrix mtrx);
int mtrx_min(struct Matrix mtrx);
struct Matrix mtrx_init(int width, int height);

int main(void)
{
    struct Matrix mtrx = mtrx_init(3, 3);
    mtrx_print(mtrx);
    printf("Matrix minimun: %i", mtrx_min(mtrx));

    free(mtrx.ptr);
}

float sum(float a, float b)
{
    return a + b;
}
float diff(float a, float b)
{
    return a - b;
}
float prod(float a, float b)
{
    return a * b;
}
int factorial(int a)
{
    int counter = 1;
    int result = 1;

    while(counter < a)
    {
        counter++;
        result *= counter;
    }

    return result;
}
float divide(float a, float b)
{
    if(!b)
    {
        printf("Divisor cannot be equal to zero.");
        return 1;
    }
    return a / b;
}
struct Matrix mtrx_init(int width, int height)
{
    struct Matrix mtrx;
    mtrx.ptr = malloc(sizeof(int) * width * height);
    mtrx.height = height;
    mtrx.width = width;

    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            int val = 0;
            printf("Enter value for the %ith column in the %ith row: ", j + 1, i + 1);
            scanf("%d", &val);

            mtrx.ptr[j + i * width] = val;
        }
    }
    return mtrx;
}
void mtrx_print(struct Matrix mtrx)
{
    printf("Here's your matrix: \n");

    for(int i = 0; i < mtrx.height; i++)
    {
        for(int j = 0; j < mtrx.width; j++)
        {
            printf("%i ", mtrx.ptr[j + i * mtrx.width]);
        }
        printf("\n");
    }
}
int mtrx_min(struct Matrix mtrx)
{
    int min = mtrx.ptr[0];
    int i = 1;

    while(i < mtrx.width * mtrx.height)
    {
        if(mtrx.ptr[i] < min)
        {
            min = mtrx.ptr[i];
        }
        i++;
    }

    return min;
}
