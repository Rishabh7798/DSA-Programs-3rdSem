// 24. write a program to delete a node in circular linked list at beginning
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

void delete_at_beginning(struct Node **head){
    struct Node *temp = *head;
    if(*head == NULL){
        printf("Circular Linked List is Empty\n");
        return;
    }
    if((*head)->next == *head){
        *head = NULL;
        free(temp);
        return;
    }
    while(temp->next != *head)
        temp = temp->next;
    temp->next = (*head)->next;
    free(*head);
    *head = temp->next;
}

void insert_at_end(struct Node **head, int value){
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = value;
    struct Node *temp = *head;
    if(*head == NULL)
    {
        *head = new_node;
        new_node->next = *head;
        return;
    }
    while(temp->next != *head)
        temp = temp->next;
    temp->next = new_node;
    new_node->next = *head;
}

void display(struct Node *head)
{
    if(head == NULL)
    {
        printf("Circular Linked List is Empty\n");
        return;
    }
    struct Node *temp = head;
    printf("Circular Linked List: ");
    do
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }while(temp != head);
    printf("\n");
}

int main()
{
    struct Node *head = NULL;
    insert_at_end(&head,1);
    insert_at_end(&head,2);
    insert_at_end(&head,3);
    insert_at_end(&head,4);
    display(head);
    delete_at_beginning(&head);
    display(head);
    return 0;
}
