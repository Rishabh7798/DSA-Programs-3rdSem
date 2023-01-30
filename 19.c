// 19. Write a program to delete a node at kth position in doubly linked list 
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
  struct Node *prev;
};

void deleteAtPosition(struct Node** head, int position) {
  if (*head == NULL) {
    printf("List is empty, cannot delete.\n");
    return;
  }

  struct Node* temp = *head;

  // if position is head
  if (position == 0) {
    *head = temp->next;
    (*head)->prev = NULL;
    free(temp);
    return;
  }

  // find previous node of the node to be deleted
  for (int i=0; temp != NULL && i<position-1; i++) {
    temp = temp->next;
  }

  // if position is more than number of nodes
  if (temp == NULL || temp->next == NULL) {
    printf("Position not found.\n");
    return;
  }

  // node temp->next is the node to be deleted
  struct Node *next = temp->next->next;
  free(temp->next);
  temp->next = next;

  if (next != NULL)
    next->prev = temp;
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
  
  printf("Linked list after deleting at position: ");
  printList(head);

  int position = 1;
  deleteAtPosition(&head, position);

  printf("\nLinked list after deleting at position: ", position);
  printList(head);

  return 0;
}
