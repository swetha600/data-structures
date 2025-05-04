#include <stdio.h>
#include <stdlib.h>

class queue {
    struct node {
        int data;
        struct node* next;
    } *front, *rear;

public:
    queue() {
        front = NULL;
        rear = NULL;
    }

    void Enqueue(int);
    int Dequeue();
    int peek();
};

int main() {
    int choice;
    queue q;
    do {
        printf("\n  Menu\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Exit\n");

        printf("Enter a number from 1-4: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                int val;
                printf("Enter the element you want to Enqueue: ");
                scanf("%d", &val);
                q.Enqueue(val);
                break;
            }
            case 2: {
                int dequeued = q.Dequeue();
                if (dequeued != -1) {
                    printf("The Dequeued Element is: %d\n", dequeued);
                } else {
                    printf("Queue is Empty!\n");
                }
                break;
            }
            case 3: {
                int top = q.peek();
                if (top != -1) {
                    printf("The front element in the queue is: %d\n", top);
                } else {
                    printf("Queue is Empty!\n");
                }
                break;
            }
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please enter a number between 1-4.\n");
        }

    } while (choice != 4);
    return 0;
}

void queue::Enqueue(int val) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if (!newnode) {
        printf("Memory allocation failed!\n");
        return;
    }
    newnode->data = val;
    newnode->next = NULL;

    if (rear == NULL) { // If queue is empty
        front = rear = newnode;
    } else {
        rear->next = newnode;
        rear = newnode;
    }
}

int queue::Dequeue() {
    if (front == NULL) { // If queue is empty
        return -1;
    }
    struct node* temp = front;
    int val = temp->data;
    front = front->next;

    if (front == NULL) { // If queue becomes empty after dequeue
        rear = NULL;
    }
    free(temp);
    return val;
}

int queue::peek() {
    if (front == NULL) {
        return -1;
    }
    return front->data;
}
