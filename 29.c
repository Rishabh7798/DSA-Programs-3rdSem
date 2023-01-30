// 29. write a program to pop in stack through linked list
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node* next;
};

struct Node* top = NULL;

void push(int data) {
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = top;
  top = newNode;
  printf("%d pushed to stack\n", data);
}

void pop() {
  if (top == NULL) {
    printf("Stack is empty\n");
    return;
  }
  printf("%d popped from stack\n", top->data);
  top = top->next;
}

int main() {
  // Adding elements to stack
  push(10);
  push(20);
  push(30);

  // Removing elements from stack
  pop();
  pop();
  pop();

  return 0;
}
