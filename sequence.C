#include <stdlib.h>
#include <stdio.h>

using namespace std;

void Select_Sort(long arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                long temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void Bubble_Sort(long arr[], int n)
{

    for (int i = n - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {

            if (arr[j] < arr[j + 1])
            {
                long temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// int particiant(long arr[], int low, int high)
// {
//     int pivot = high;
//     int i = low - 1;
//     for (int j = low; j < high; j++)
//     {
//         if (arr[j] < arr[pivot])
//         {
//             i++;
//             long temp = arr[j];
//             arr[j] = arr[i];
//             arr[i] = temp;
//         }
//     }

//     i++;
//     long temp = arr[i];
//     arr[i] = arr[pivot];
//     arr[pivot] = temp;

//     return i;
// }

// void QuickSort(long arr[], int low, int high)
// {
//     if (low < high)
//     {
//         int pivot = particiant(arr, low, high);
//         QuickSort(arr, low, pivot - 1);
//         QuickSort(arr, pivot + 1, high);
//     }
// }

int participant_(long arr[], int low, int high)
{
    int pivot = high;
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] < arr[pivot])
        {
            i++;
            long temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    i++;
    long temp = arr[pivot];
    arr[pivot] = arr[i];
    arr[i] = temp;

    return i;
}

void QuickSort_(long arr[], int low, int high)
{
    if (low < high)
    {
        int pivot = participant_(arr, low, high);
        QuickSort_(arr, low, pivot - 1);
        QuickSort_(arr, pivot + 1, high);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    long arr[n];

    for (long i = 0; i < n; i++)
    {
        scanf("%ld", &arr[i]);
    }

    QuickSort_(arr, 0, n - 1);

    if (n < 3)
    {
        for (int i = 0; i < n; i++)
        {
            printf("%ld ", arr[i]);
        }
    }
    else
    {
        for (int i = n - 1; i >= n - 3; i--)
        {
            printf("%ld ", arr[i]);
        }
    }

    return 0;
}