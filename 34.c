// 34. write a program to solve arithmetic expression by stack through linked list in c program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Structure for linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* newNode(int data){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// Function to push a node to stack
void push(struct Node** top, int data){
    struct Node* temp = newNode(data);
    temp->next = *top;
    *top = temp;
}

// Function to pop a node from stack
int pop(struct Node** top){
    if (*top == NULL)
        return -1;

    struct Node* temp = *top;
    int popped = temp->data;
    *top = (*top)->next;
    free(temp);
    return popped;
}

// Function to check if operator or not
int isOperator(char ch){
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

// Function to perform operation and return result
int performOperation(int a, int b, char operator){
    switch (operator) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
    }
    return -1;
}

// Function to evaluate an expression
int evaluateExpression(char* expression){
    struct Node* stack = NULL;
    for (int i = 0; i < strlen(expression); i++) {
        if (isdigit(expression[i])) {
            int num = 0;
            while (i < strlen(expression) && isdigit(expression[i])) {
                num = (num * 10) + (expression[i] - '0');
                i++;
            }
            i--;
            push(&stack, num);
        }
        else if (isOperator(expression[i])) {
            int a = pop(&stack);
            int b = pop(&stack);
            int result = performOperation(b, a, expression[i]);
            push(&stack, result);
        }
    }
    return pop(&stack);
}

// Main function
int main(){
    char expression[100];
    printf("Enter an expression: "); //5*(6+2)-12/4
    scanf("%s", expression);
    int result = evaluateExpression(expression);
    printf("Result: %d\n", result);
    return 0;
}
