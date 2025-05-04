#include <stdio.h>
#define SIZE 5

class queue {
    int arr[SIZE];
    int front, rear;

public:
    queue() {
        front = -1;
        rear = -1;
    }

    void Enqueue(int);
    int Dequeue();
    int peek();
    void display();
};

int main() {
    int choice;
    queue q;
    do {
        printf("\n  Menu\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");

        printf("Enter a number from 1-5: ");
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
                }
                break;
            }
            case 3: {
                int top = q.peek();
                if (top != -1) {
                    printf("The front element in the queue is: %d\n", top);
                }
                break;
            }
            case 4:
                q.display();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please enter a number between 1-5.\n");
        }

    } while (choice != 5);
    return 0;
}

void queue::Enqueue(int val) {
    if ((rear + 1) % SIZE == front) {
        printf("Queue is Full!\n");
        return;
    }
    if (front == -1 && rear == -1) {
        front = 0;
        rear = 0;
    } else {
        rear = (rear + 1) % SIZE;
    }
    arr[rear] = val;
}

int queue::Dequeue() {
    if (front == -1) {
        printf("Queue is Empty!\n");
        return -1;
    }
    int temp = arr[front];
    if (front == rear) { // Only one element present
        front = rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }
    return temp;
}

int queue::peek() {
    if (front == -1) {
        printf("Queue is Empty!\n");
        return -1;
    }
    return arr[front];
}

void queue::display() {
    if (front == -1) {
        printf("Queue is Empty!\n");
        return;
    }
    printf("Queue elements: ");
    if (front <= rear) {
        for (int i = front; i <= rear; i++) {
            printf("%d ", arr[i]);
        }
    } else {
        for (int i = front; i < SIZE; i++) {
            printf("%d ", arr[i]);
        }
        for (int i = 0; i <= rear; i++) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}
