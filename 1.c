// 1. write a program to print and reverse an array
#include <stdio.h>
#define MAX_SIZE 100   // max array size

int main(){
    int arr[MAX_SIZE];
    int n, i;
    // Input size of the array
    printf("Enter size of the array: ");
    scanf("%d", &n);
    // Input elements in the array
    printf("Enter elements in the array:\n");
    for(i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }
    // Print the original array
    printf("Original array: ");
    for(i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    // Reverse the array
    int start = 0, end = n-1;
    while(start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
    // Print the reversed array
    printf("Reversed array: ");
    for(i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
