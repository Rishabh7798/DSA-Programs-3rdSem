// 21. write a program to insert a node at beginning of the circular linked list
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

void insertAtBegin(struct Node** head, int data) {
  struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
  struct Node* temp = *head;

  newNode->data = data;
  newNode->next = *head;

  if (*head != NULL) {
    while (temp->next != *head) {
      temp = temp->next;
    }
    temp->next = newNode;
  } else {
    newNode->next = newNode;
  }

  *head = newNode;
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

  insertAtBegin(&head, 1);
  insertAtBegin(&head, 2);
  insertAtBegin(&head, 3);
  insertAtBegin(&head, 4);
  
  printf("\nCircular linked list after inserting at beginning: ");
  printList(head);

  return 0;
}
