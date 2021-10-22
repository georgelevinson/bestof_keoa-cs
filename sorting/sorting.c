#include <stdio.h>

void print_intarr(int[], int, char[]);
void selection(int[], int);
void insertion(int[], int);
void bubble(int[], int);
void merge(int[], int);

int main(void)
{
    // int list[] = { 2, 5, 6, 3, 1, 9, 4, 8, 7 };
    // int list[] = { 1, 2, 6, 3, 1, 9, 4, 8, 7 };
    int list[] = { 9, 2, 1, 3, 1, 9, 4, 8, 7 };
    
    int length = sizeof(list)/sizeof(list[0]);

    print_intarr(list, length, "Here's your array \n");
    insertion(list, length);
    print_intarr(list, length, "Here's your sorted array \n");
}

void insertion(int arr[], int length)
{
    for(int i = 1; i < length; i++)
    {
        int j = i - 1;
        int curr = arr[i];
        int insrt = arr[j];
        
        if(curr < insrt)
        {
            while(j > 0)
            {
                if(curr < insrt)
                {
                    insrt = arr[--j];
                }
                else
                {
                    break;
                }
            }
            
            for(int k = i; k > j; k--)
            {
                arr[k] = arr[k - 1];
            }
            
            if(!j && curr > insrt)
            {
                int idx = j + 1;
                arr[idx] = curr;
            }
            else if(!j)
            {
                arr[j] = curr;
            }
            else
            {
                int idx = j + 1;
                arr[idx] = curr;
            }
        }
    }
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
void print_intarr(int arr[], int length, char msg[])
{
    printf("%s", msg);

    for(int i = 0; i < length; i++)
    {
        printf("%i\n", arr[i]);
    }
}