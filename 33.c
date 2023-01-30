// 33. write a program to perform postfix expression to prefix expression in stack through linked list in c program
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct node {
    char data;
    struct node *next;
}Node;

Node* createNode(char value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

int isOperand(char ch) {
    return (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z');
}

void push(Node **stack, char value) {
    Node *newNode = createNode(value);
    newNode->next = *stack;
    *stack = newNode;
}

char pop(Node **stack) {
    if (*stack == NULL)
        return '#';
    Node *temp = *stack;
    char value = temp->data;
    *stack = temp->next;
    free(temp);
    return value;
}

int getPriority(char ch) {
    switch (ch) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}

char * postfixToPrefix(char postfix[]) {
    int length = strlen(postfix);
    Node *stack = NULL;
    char *prefix = (char *)malloc(sizeof(char) * (length + 1));
    int i, j = 0;
    for (i = length - 1; i >= 0; i--) {
        if (isOperand(postfix[i])) {
            prefix[j++] = postfix[i];
        } else if (isOperator(postfix[i])) {
            while (stack != NULL && getPriority(stack->data) >= getPriority(postfix[i])) {
                prefix[j++] = pop(&stack);
            }
            push(&stack, postfix[i]);
        }
    }
    while (stack != NULL) {
        prefix[j++] = pop(&stack);
    }
    prefix[j] = '\0';
    strrev(prefix);
    return prefix;
}

int main() {
    char postfix[] = "ABC/-AK/L-*";
    char *prefix = postfixToPrefix(postfix);
    printf("Prefix: %s\n", prefix);
    return 0;
}
