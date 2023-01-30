// 3. Write a program to perform linear search on an array 
#include <stdio.h>

int main(){
    int n, i, search, flag = 0;
    int arr[100];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements: \n", n);
    for (i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    printf("Enter a number to search: ");
    scanf("%d", &search);

    for (i = 0; i < n; i++) {
        if (arr[i] == search) {
            printf("%d is present at index %d.\n", search, i);
            flag = 1;
            break;
        }
    }
    
    if (flag == 0) {
        printf("%d is not present in the array.\n", search);
    }
    
    return 0;
}
