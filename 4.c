// 4. Write a program to find the maximum number in array
#include <stdio.h>

int main() {
    int n, i;
    int arr[100];
    int max = arr[0];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements: \n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    printf("The maximum element is %d.\n", max);
    return 0;
}