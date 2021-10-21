#include <stdio.h>

void print_intarr(int[], int);
void selection(int[], int);
int* insertion(int[]);
int* bubble(int[]);
int* merge(int[]);

int main(void)
{
    int list[] = { 2, 5, 6, 3, 1, 9, 4, 8, 7 };
    int length = sizeof(list)/sizeof(list[0]);

    print_intarr(list, length);
    selection(list, length);
    print_intarr(list, length);
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