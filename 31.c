// 31. write a program to convert infix expression to postfix expression in stack through linked list in c program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
  char data;
  struct Node* next;
};

struct Node* top = NULL;

void push(char data) {
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = top;
  top = newNode;
}

char pop() {
  if (top == NULL) {
    printf("Stack is empty\n");
    return 0;
  }
  char popped = top->data;
  top = top->next;
  return popped;
}

int priority(char c) {
  if (c == '^') return 3;
  if (c == '*' || c == '/') return 2;
  if (c == '+' || c == '-') return 1;
  return 0;
}

void infixToPostfix(char* infix, char* postfix) {
  int i = 0, j = 0;
  for (i = 0; i < strlen(infix); i++) {
    if (infix[i] >= 'a' && infix[i] <= 'z' || infix[i] >= 'A' && infix[i] <= 'Z') {
      postfix[j++] = infix[i];
    } else if (infix[i] == '(') {
      push(infix[i]);
    } else if (infix[i] == ')') {
      while (top != NULL && top->data != '(') {
        postfix[j++] = pop();
      }
      if (top == NULL) {
        printf("Invalid expression\n");
        return;
      }
      pop();
    } else {
      while (top != NULL && priority(infix[i]) <= priority(top->data)) {
        postfix[j++] = pop();
      }
      push(infix[i]);
    }
  }
  while (top != NULL) {
    postfix[j++] = pop();
  }
  postfix[j] = '\0';
}

int main() {
  char infix[100] = "a+b*c-(d/e^f)*g";
  char postfix[100];
  infixToPostfix(infix, postfix);
  printf("Infix expression: %s\n", infix);
  printf("Postfix expression: %s\n", postfix);
  return 0;
}
