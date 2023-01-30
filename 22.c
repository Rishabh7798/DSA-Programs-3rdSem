// 22. write a program to insert a node at kth position in the circular linked list
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

void insertAtKth(struct Node** head, int data, int k) {
  struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
  struct Node* temp = *head;
  int count = 0;

  newNode->data = data;
  newNode->next = *head;

  if (*head == NULL) {
    newNode->next = newNode;
    *head = newNode;
  } else {
    while (count < k-2 && temp->next != *head) {
      temp = temp->next;
      count++;
    }
    newNode->next = temp->next;
    temp->next = newNode;
  }
}

void printList(struct Node *head) {
  struct Node *temp = head;

  if (head != NULL) {
    do {
      printf("%d ", temp->data);
      temp = temp->next;
    } while (temp != head);
  }
}

int main() {
  struct Node* head = NULL;

  insertAtKth(&head, 1, 1);
  insertAtKth(&head, 2, 2);
  insertAtKth(&head, 3, 3);
  insertAtKth(&head, 4, 4);
  insertAtKth(&head, 5, 2);

  printf("Circular linked list after inserting at kth position: ");
  printList(head);

  return 0;
}
