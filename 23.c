// 23. write a program to insert a node at end in circular linked list
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

void insertAtEnd(struct Node** head, int data) {
  struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
  struct Node* temp = *head;

  newNode->data = data;
  newNode->next = *head;

  if (*head == NULL) {
    newNode->next = newNode;
    *head = newNode;
  } else {
    while (temp->next != *head) {
      temp = temp->next;
    }
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

  insertAtEnd(&head, 1);
  insertAtEnd(&head, 2);
  insertAtEnd(&head, 3);
  insertAtEnd(&head, 4);
  insertAtEnd(&head, 5);

  printf("Circular linked list after inserting at end: ");
  printList(head);

  return 0;
}
