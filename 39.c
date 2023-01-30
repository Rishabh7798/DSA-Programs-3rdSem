//39. Radix sort
#include<stdio.h>
#include<math.h>
#define MAX 20

int getMax(int arr[], int n)
{
    int max = arr[0];
    for(int i=1; i<n; i++)
        if(arr[i] > max)
            max = arr[i];
    return max;
}

void countSort(int arr[], int n, int exp)
{
    int output[n];
    int count[10] = {0};

    for(int i=0; i<n; i++)
        count[ (arr[i]/exp)%10 ]++;

    for(int i=1; i<10; i++)
        count[i] += count[i-1];

    for(int i=n-1; i>=0; i--)
    {
        output[count[ (arr[i]/exp)%10 ] - 1] = arr[i];
        count[ (arr[i]/exp)%10 ]--;
    }

    for(int i=0; i<n; i++)
        arr[i] = output[i];
}

void radixSort(int arr[], int n)
{
    int m = getMax(arr, n);
    for(int exp=1; m/exp > 0; exp *= 10)
        countSort(arr, n, exp);
}

void printArray(int arr[], int n)
{
    for(int i=0; i<n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int arr[MAX], n;
    printf("Enter number of elements in array: ");
    scanf("%d", &n);
    printf("Enter elements of array: \n");
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);

    radixSort(arr, n);
    printf("Sorted array: ");
    printArray(arr, n);
    return 0;
}
