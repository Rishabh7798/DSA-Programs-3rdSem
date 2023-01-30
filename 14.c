// 14. Write a program to delete an element from the last of linked list 
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

void deleteLast(struct Node *head) {
  struct Node *temp = head;
  struct Node *prev;
  while (temp->next != NULL) {
    prev = temp;
    temp = temp->next;
  }
  prev->next = NULL;
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

  printf("Linked list before deleting the last node: ");
  printList(head);

  deleteLast(head);
  printf("\nLinked list after deleting the last node: ");
  printList(head);

  return 0;
}
