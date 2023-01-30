// 26. write a program to delete a node at end in circular linked list
#include <stdio.h> 
#include <stdlib.h> 

struct Node { 
    int data; 
    struct Node* next; 
}; 

struct Node* head = NULL; 

void deleteEnd() { 
    struct Node *temp = head, *prev; 
    if (head == NULL) 
        return; 
  
    if (head->next == head) { 
        head = NULL; 
        free(head); 
        return; 
    } 
  
    while (temp->next != head) { 
        prev = temp; 
        temp = temp->next; 
    } 
  
    prev->next = head; 
    free(temp); 
} 

void push(int data) { 
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node)); 
    temp->data = data; 
    temp->next = head; 
    if (head != NULL) { 
        struct Node* curr = head; 
        while (curr->next != head) 
            curr = curr->next; 
        curr->next = temp; 
    } else
        temp->next = temp; 
    head = temp; 
} 

void printList() { 
    struct Node* curr = head; 
    if (head == NULL) 
        return; 
    while (curr->next != head) { 
        printf("%d ", curr->data); 
        curr = curr->next; 
    } 
    printf("%d", curr->data); 
} 

int main() { 
    push(1); 
    push(2); 
    push(3); 
    push(4); 
    printf("\nLinked List before deleting last node: "); 
    printList(); 
    deleteEnd(); 
    printf("\nLinked List after deleting last node: "); 
    printList(); 
    return 0; 
} 
