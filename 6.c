// 6. Write a program to inserting a element in array
#include <stdio.h>

int main() {
    int n, pos, value, i;
    int arr[100];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements: \n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the position where you want to insert the element: ");
    scanf("%d", &pos);

    printf("Enter the value of the element: ");
    scanf("%d", &value);

    for (i = n - 1; i >= pos - 1; i--) {
        arr[i + 1] = arr[i];
    }

    arr[pos - 1] = value;

    printf("The updated array is: \n");
    for (i = 0; i < n + 1; i++) {
        printf("%d\n", arr[i]);
    }

    return 0;
}
