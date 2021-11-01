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
struct Matrix mtrx_init();

int main(void)
{
    struct Matrix mtrx = mtrx_init();
    mtrx_print(mtrx);

    free(mtrx.ptr);

    printf("21 + 45 = %.2f\n", sum(21,45));
    printf("21  45 = %.2f\n", diff(21,45));
    printf("2 * 4 = %.2f\n", prod(2,4));
    printf("5! = %i\n", factorial(5));
    printf("2 / 4 = %.2f\n", divide(2,4));
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
float divide(float a, float b)
{
    if(!b)
    {
        printf("Divisor cannot be equal to zero.");
        return 1;
    }
    return a / b;
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
struct Matrix mtrx_init()
{
    int height, width;
    printf("Enter the number of rows: \n");
    scanf("%d", &height);
    printf("Enter the number of columns: \n");
    scanf("%d", &width);

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

    printf("Matrix minimun: %i\n", mtrx_min(mtrx));
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
