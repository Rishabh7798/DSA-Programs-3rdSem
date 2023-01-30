// 27. write a program to pop in stack using array
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
int stack[MAX_SIZE];
int top = -1;

void push(int item) {
  if (top >= MAX_SIZE - 1) {
    printf("Stack Overflow\n");
    return;
  }
  top = top + 1;
  stack[top] = item;
  printf("%d pushed to stack\n", item);
}

void pop() {
  if (top < 0) {
    printf("Stack Underflow\n");
    return;
  }
  printf("%d popped from stack\n", stack[top]);
  top = top - 1;
}

int main() {
  // Adding elements to stack
  push(10);
  push(20);
  push(30);

  // Popping elements from stack
  pop();
  pop();
  pop();

  return 0;
}
