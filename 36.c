// 36. write a program for deletion in queue in c program
#include<stdio.h>
#define MAX 100

int front = -1, rear = -1, queue[MAX];

void insert_queue(int item){
    if (rear == MAX - 1)
        printf("Queue Overflow\n");
    else{
        if (front == -1)
            front = 0;
        rear = rear + 1;
        queue[rear] = item;
    }
}

void delete_queue(){
    if (front == -1 || front > rear){
        printf("Queue Underflow\n");
        return ;
    }
    else{
        printf("Element deleted from queue is : %d\n", queue[front]);
        front = front + 1;
    }
}

int main(){
    int item;
    insert_queue(10);
    insert_queue(20);
    insert_queue(30);
    delete_queue();
    delete_queue();
    return 0;
}

