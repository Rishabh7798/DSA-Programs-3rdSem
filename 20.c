// 20. Write a program to delete a node at end in doubly linked list 
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
  struct Node *prev;
};

void deleteAtEnd(struct Node** head) {
  if (*head == NULL) {
    printf("List is empty, cannot delete.\n");
    return;
  }

  struct Node* temp = *head;

  // if only one node
  if (temp->next == NULL) {
    *head = NULL;
    free(temp);
    return;
  }

  // find second last node
  while (temp->next->next != NULL) {
    temp = temp->next;
  }

  // node temp->next is the node to be deleted
  free(temp->next);
  temp->next = NULL;
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

  printf("Linked list after deleting at end: ");
  printList(head);
  
  deleteAtEnd(&head);

  printf("\nLinked list after deleting at end: ");
  printList(head);

  return 0;
}
