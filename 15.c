// 15. Write a program to insert a node in doubly linked list at beginning
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
  struct Node *prev;
};

void insertAtBeginning(struct Node** head, int data) {
  struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = *head;
  newNode->prev = NULL;

  if (*head != NULL)
    (*head)->prev = newNode;

  *head = newNode;
}

void printList(struct Node *node) {
  while (node != NULL) {
    printf("%d ", node->data);
    node = node->next;
  }
}

int main() {
  struct Node* head = NULL;
  struct Node* second = NULL;
  struct Node* third = NULL;

  head = (struct Node*) malloc(sizeof(struct Node));
  second = (struct Node*) malloc(sizeof(struct Node));
  third = (struct Node*) malloc(sizeof(struct Node));

  head->data = 1;
  head->next = second;
  head->prev = NULL;

  second->data = 2;
  second->next = third;
  second->prev = head;

  third->data = 3;
  third->next = NULL;
  third->prev = second;
  
  printf("Linked list after inserting at beginning: ");
  printList(head);

  insertAtBeginning(&head, 0);
  printf("\nLinked list after inserting at beginning: ");
  printList(head);

  return 0;
}
