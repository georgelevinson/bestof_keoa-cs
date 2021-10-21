#include <stdio.h>

void print_intarr(int[], int);
void selection(int[], int);
void insertion(int[]);
void bubble(int[], int);
int* merge(int[]);

int main(void)
{
    int list[] = { 2, 5, 6, 3, 1, 9, 4, 8, 7 };
    int length = sizeof(list)/sizeof(list[0]);

    print_intarr(list, length);
    bubble(list, length);
    print_intarr(list, length);
}

void bubble(int arr[], int length)
{
    int swaps = 0;
    for(int i = 1; i < length; i++)
    {
        for(int j = 0; j < length - i; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                int swap = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = swap;
                swaps++;
            }
        }
        if(swaps == 0)
        {
            break;
        }
    }
}
void selection(int arr[], int length)
{
    for(int i = 0; i < length - 1; i++)
    {
        int current = arr[i];
        int index = i;

        for(int j = i + 1; j < length; j++)
        {
            if(arr[j] < current)
            {
                current = arr[j];
                index = j;
            }
        }

        arr[index] = arr[i];
        arr[i] = current;
    }
}
void print_intarr(int arr[], int length)
{
    printf("Here's your array \n");

    for(int i = 0; i < length; i++)
    {
        printf("%i\n", arr[i]);
    }
}