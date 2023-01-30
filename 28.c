// 28. write a program to push in stack using array
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

int main() {
  // Adding elements to stack
  push(10);
  push(20);
  push(30);

  return 0;
}
