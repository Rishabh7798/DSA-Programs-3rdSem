//35. write a program for Insertion in queue
#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void insert_element(int element) {
  if (rear == MAX - 1)
    printf("Queue is full\n");
  else {
    if (front == -1)
      front = 0;
    rear = rear + 1;
    queue[rear] = element;
  }
}

void display() {
  int i;
  if (front == -1)
    printf("Queue is empty\n");
  else {
    for (i = front; i <= rear; i++)
      printf("%d ", queue[i]);
    printf("\n");
  }
}

int main() {
  int choice, element;
  while (1) {
    printf("1.Insert element to queue\n");
    printf("2.Display all elements of queue\n");
    printf("3.Quit\n");
    printf("Enter your choice : ");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      printf("Enter the element to be inserted : ");
      scanf("%d", &element);
      insert_element(element);
      break;
    case 2:
      display();
      break;
    case 3:
      exit(0);
    default:
      printf("Wrong choice\n");
    }
  }
  return 0;
}
