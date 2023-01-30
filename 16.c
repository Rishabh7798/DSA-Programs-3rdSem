// 16. Write a program to insert a node after an index in doubly linked list 
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
  struct Node *prev;
};

void insertAfterIndex(struct Node* head, int index, int data) {
  struct Node* temp = head;
  struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
  newNode->data = data;

  for (int i = 0; i < index && temp != NULL; i++)
    temp = temp->next;

  if (temp == NULL)
    return;

  newNode->next = temp->next;
  temp->next = newNode;
  newNode->prev = temp;

  if (newNode->next != NULL)
    newNode->next->prev = newNode;
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
  
  printf("Linked list after inserting after index: ");
  printList(head);

  insertAfterIndex(head, 1, 1.5);
  printf("\nLinked list after inserting after index: ");
  printList(head);

  return 0;
}
