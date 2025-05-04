#include <stdio.h>
#include <stdlib.h>

struct Node {
    char data;
    struct Node* next;
};

struct Node* top = NULL;

void push(char value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Heap Overflow!\n");
        return;
    }
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

char pop() {
    if (top == NULL) {
        printf("Stack Underflow!\n");
        return '\0';
    }
    struct Node* temp = top;
    char value = temp->data;
    top = top->next;
    free(temp);
    return value;
}

char peek() {
    if (top == NULL) {
        printf("Stack is empty!\n");
        return '\0';
    }
    return top->data;
}

int isEmpty() {
    return top == NULL;
}

void freeStack() {
    while (!isEmpty()) pop();
}



