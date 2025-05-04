#include <stdio.h>
#include <stdlib.h>

// Function to display menu options
void index(){
    printf("1. Push\n2. Pop\n3. Peek\n4. Exit\n\n");
}

class stack{
    struct node {
        char elem;
        struct node* next;
    }* head;

public:
    stack(){
        head=NULL;

    }
    void push(char);
    char pop();
    char peek();
    void display();

};

int main() {
    stack s;
   
    
    int choice;
    char elem;
    
    index();
    
    while (1) {
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter character to be inserted: ");
                scanf(" %c", &elem);
                s.push(elem);
                s.display();
                break;
            
            case 2:
                printf("Element popped: %c\n", s.pop());
                s.display();
                
                break;
                
            case 3:
                printf("Top element: %c\n",s.peek());
                break;
            
            case 4:
                printf("Exiting program...\n");
                return 0;
            
            default:
                printf("Invalid choice! Try again.\n");
        }
        
        printf("\n");
    }
    
    return 0;
}

// Push function (inserts at the head)
void stack::push(char elem) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if (!newnode) {
        printf("Memory allocation failed\n");
        return;
    }
    newnode->elem = elem;
    newnode->next = head;
    head = newnode;
}

// Pop function (removes from the head)
char stack::pop() {
    if (head == NULL) {
        return '\0'; // Stack is empty
    }
    
    struct node* temp = head;
    char popped = temp->elem;
    head = temp->next;
    
    free(temp);
    return popped;
}

// Peek function (returns top element)
char stack::peek() {
    if (head == NULL) {
        return '\0';
    }
    return head->elem;
}

// Display function
void stack::display() {
    struct node* temp = head;
    if (temp == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    
    printf("Stack: ");
    while (temp != NULL) {
        printf("%c ", temp->elem);
        temp = temp->next;
    }
    printf("\n");
}
