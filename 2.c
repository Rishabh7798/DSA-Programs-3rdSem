// 2. Write a program to print matrix and its transpose
#include <stdio.h>
#define MAX_ROWS 100
#define MAX_COLS 100

int main(){
    int matrix[MAX_ROWS][MAX_COLS];
    int rows, cols, i, j;
    // Input number of rows and columns
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);
    // Input elements in the matrix
    printf("Enter elements in the matrix:\n");
    for(i=0; i<rows; i++) {
        for(j=0; j<cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    // Print the original matrix
    printf("Original matrix:\n");
    for(i=0; i<rows; i++) {
        for(j=0; j<cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    // Transpose the matrix
    int transpose[MAX_COLS][MAX_ROWS];
    for(i=0; i<rows; i++) {
        for(j=0; j<cols; j++) {
            transpose[j][i] = matrix[i][j];
        }
    }
    // Print the transposed matrix
    printf("Transposed matrix:\n");
    for(i=0; i<cols; i++) {
        for(j=0; j<rows; j++) {
            printf("%d ", transpose[i][j]);
        }
        printf("\n");
    }
    return 0;
}
