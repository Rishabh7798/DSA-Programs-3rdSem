// 12. Write a program to delete first element in linked list 
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

void deleteFirst(struct Node** head_ref) {
  struct Node *temp = *head_ref;
  *head_ref = temp->next;
  free(temp);
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

  second->data = 2;
  second->next = third;

  third->data = 3;
  third->next = NULL;

  printf("Linked list before deleting the first node: ");
  printList(head);

  deleteFirst(&head);
  printf("\nLinked list after deleting the first node: ");
  printList(head);

  return 0;
}
