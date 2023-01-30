// 32. write a program to perform infix expression to prefix expression in stack through linked list in c program
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define MAX 100

struct node {
    char data;
    struct node *next;
};
struct node *top = NULL;

void push(char symbol) {
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = symbol;
    if(top == NULL)
        newnode->next = NULL;
    else
        newnode->next = top;
    top = newnode;
}

char pop() {
    char item;
    struct node *temp;
    if(top == NULL)
        return 0;
    temp = top;
    item = temp->data;
    top = top->next;
    free(temp);
    return item;
}

int priority(char symbol) {
    if(symbol == '^')
        return 3;
    else if(symbol == '*' || symbol == '/')
        return 2;
    else if(symbol == '+' || symbol == '-')
        return 1;
    else
        return 0;
}

void infix_to_prefix(char infix[], char prefix[]) {
    int i, j=0, length;
    char symbol, temp;
    length = strlen(infix);
    push('#');
    for(i=length-1; i>=0; i--) {
        symbol = infix[i];
        if(isalnum(symbol))
            prefix[j++] = symbol;
        else {
            while(priority(top->data) >= priority(symbol)) {
                temp = pop();
                prefix[j++] = temp;
            }
            push(symbol);
        }
    }
    while(top->data != '#') {
        temp = pop();
        prefix[j++] = temp;
    }
    prefix[j] = '\0';
    strrev(prefix);
}

int main() {
    char infix[MAX], prefix[MAX];
    printf("Enter the Infix expression: "); //a / b + c
    scanf("%s", infix);
    infix_to_prefix(infix, prefix);
    printf("The Prefix expression is: %s\n", prefix); //+ / a b c
    return 0;
}