// 7. Write a program to delete an element from a linear array
#include <stdio.h>

int main() {
    int n, pos, i;
    int arr[100];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements: \n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the position of the element to be deleted: ");
    scanf("%d", &pos);

    for (i = pos - 1; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    printf("The updated array is: \n");
    for (i = 0; i < n - 1; i++) {
        printf("%d\n", arr[i]);
    }

    return 0;
}
