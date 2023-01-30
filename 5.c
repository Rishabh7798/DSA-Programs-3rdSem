// 5. Write a program to concatenate two strings, calculate length and reverse it using function value
#include <stdio.h>
#include <string.h>

void concatenate(char str1[], char str2[], char result[]){
    int i, j;
    for (i = 0; str1[i] != '\0'; i++) {
        result[i] = str1[i];
    }
    for (j = 0; str2[j] != '\0'; j++) {
        result[i + j] = str2[j];
    }
    result[i + j] = '\0';
}

int length(char str[]) {
    int i, count = 0;
    for (i = 0; str[i] != '\0'; i++) {
        count++;
    }
    return count;
}

void reverse(char str[]) {
    int i, j, len;
    char temp;
    len = length(str);
    for (i = 0, j = len - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

int main() {
    char str1[100], str2[100], result[200];
    
    printf("Enter first string: ");
    scanf("%s", str1);

    printf("Enter second string: ");
    scanf("%s", str2);

    concatenate(str1, str2, result);
    printf("The concatenated string is %s.\n", result);

    printf("The length of the concatenated string is %d.\n", length(result));

    reverse(result);
    printf("The reversed string is %s.\n", result);

    return 0;
}
