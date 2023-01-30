// 25. write a program to delete a node at specific position circular linked list
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

void deleteAtPosition(struct Node** head, int position) {
  struct Node* temp = *head;
  struct Node* previous = NULL;

  if (*head == NULL) {
    printf("Circular linked list is empty.\n");
    return;
  }

  int count = 0;
  while (count < position - 1 && temp->next != *head) {
    previous = temp;
    temp = temp->next;
    count++;
  }

  if (count != position - 1) {
    printf("Position is not found.\n");
  } else if (temp == *head) {
    previous = *head;
    while (previous->next != *head) {
      previous = previous->next;
    }
    previous->next = temp->next;
    *head = temp->next;
    free(temp);
  } else {
    previous->next = temp->next;
    free(temp);
  }
}
void insertAtEnd(struct Node **head, int value){
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = value;
    struct Node *temp = *head;
    if(*head == NULL){
        *head = new_node;
        new_node->next = *head;
        return;
    }
    while(temp->next != *head)
        temp = temp->next;
    temp->next = new_node;
    new_node->next = *head;
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

  printf("Circular linked list before deleting at position 3: ");
  printList(head);

  deleteAtPosition(&head, 3);

  printf("\nCircular linked list after deleting at position 3: ");
  printList(head);

  return 0;
}
