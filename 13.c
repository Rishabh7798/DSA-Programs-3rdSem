// 13. Write a program to delete element at a specific index from linked list 
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

void deleteNode(struct Node **head_ref, int position) {
  if (*head_ref == NULL) return;
  struct Node *temp = *head_ref;
  if (position == 0) {
    *head_ref = temp->next;
    free(temp);
    return;
  }
  for (int i=0; temp != NULL && i<position-1; i++)
    temp = temp->next;
  if (temp == NULL || temp->next == NULL) return;
  struct Node *next = temp->next->next;
  free(temp->next);
  temp->next = next;
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

  int position;
  printf("Enter the index to be deleted: ");
  scanf("%d", &position);

  printf("Linked list after deleting the node at index: ");
  printList(head);

  deleteNode(&head, position);

  printf("\nLinked list after deleting the node at index: ", position);
  printList(head);

  return 0;
}
