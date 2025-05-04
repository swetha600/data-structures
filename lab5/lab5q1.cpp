#include <stdio.h>
#include <stdlib.h>

// Menu Display
void indexMenu() {
    printf("1. Insert at Beginning\n");
    printf("2. Insert at End\n");
    printf("3. Insert at Position\n");
    printf("4. Delete at Beginning\n");
    printf("5. Delete at End\n");
    printf("6. Delete at Position\n");
    printf("7. Search\n");
    printf("8. Display\n");
    printf("9. Exit\n\n");
}

class list {
private:
    struct Node {
        struct Node* prev;
        int data;
        struct Node* next;
    }*tail;  // Only using tail pointer

public:
    list() {
        tail = NULL;
    }

    void insertAtEnd(int);
    void insertAtBeginning(int);
    void insertAtPosition(int,int);
    int countLength();
    void deleteBeginning();
    void deleteEnd();
    void deleteAtPosition(int);
    int search(int);
    void display();
};




int main() {
    list l;
    int choice, num, pos;
    indexMenu();
    printf("Enter choice: ");
    scanf("%d", &choice);

    while (choice!=9) {
        
        

        switch (choice) {
            case 1:
                printf("Enter a number: ");
                scanf("%d", &num);
                l.insertAtBeginning(num);
                break;
            case 2:
                printf("Enter a number: ");
                scanf("%d", &num);
                l.insertAtEnd(num);
                break;
            case 3:
                printf("Enter a number: ");
                scanf("%d", &num);
                printf("Enter position: ");
                scanf("%d", &pos);
                l.insertAtPosition(num, pos);
                break;
            case 4:
                l.deleteBeginning();
                break;
            case 5:
                l.deleteEnd();
                break;
            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                l.deleteAtPosition(pos);
                break;
            case 7:
                printf("Enter the number to search: ");
                scanf("%d", &num);
                pos = l.search(num);
                if (pos == -1)
                    printf("Number not found!\n");
                else
                    printf("Number found at position %d\n", pos);
                break;
            case 8:
                l.display();
                break;
        }
        indexMenu();
        printf("Enter choice: ");
        scanf("%d", &choice);
    } 
    

    return 0;
}
// Count Length of the List
int list::countLength() {
    int count = 0;
    Node* temp = tail;
    
    while (temp != NULL) {
        count++;
        temp = temp->prev;
    }
    
    return count;
}

// Insert at the End
void list::insertAtEnd(int num) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = num;
    newNode->next = NULL;
    
    if (tail == NULL) {  // Empty list
        newNode->prev = NULL;
        tail = newNode;
    } else {
        Node* temp = tail;
        while (temp->prev != NULL) {
            temp = temp->prev;
        }
        temp->prev = newNode;
        newNode->next = temp;
    }
}

// Insert at the Beginning
void list::insertAtBeginning(int num) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = num;

    if (tail == NULL) {  // Empty list
        newNode->next = NULL;
        newNode->prev = NULL;
        tail = newNode;
    } else {
        Node* temp = tail;
        while (temp->prev != NULL) {
            temp = temp->prev;
        }
        newNode->next = temp;
        newNode->prev = NULL;
        temp->prev = newNode;
    }
}

// Insert at a Specific Position
void list::insertAtPosition(int num, int pos) {
    if (pos < 1 || pos > countLength() + 1) {
        printf("Invalid position!\n");
        return;
    }

    if (pos == 1) {
        insertAtBeginning(num);
        return;
    }

    if (pos == countLength() + 1) {
        insertAtEnd(num);
        return;
    }

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = num;

    Node* temp = tail;
    int curr = countLength();

    while (curr != pos) {
        temp = temp->prev;
        curr--;
    }

    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
}

// Delete from Beginning
void list::deleteBeginning() {
    if (tail == NULL) {
        printf("List is empty!\n");
        return;
    }

    Node* temp = tail;
    while (temp->prev != NULL) {
        temp = temp->prev;
    }

    if (temp == tail) {  // Only one node
        tail = NULL;
    } else {
        temp->next->prev = NULL;
    }

    free(temp);
}

// Delete from End
void list::deleteEnd() {
    if (tail == NULL) {
        printf("List is empty!\n");
        return;
    }

    Node* temp = tail;
    tail = tail->prev;

    if (tail != NULL) {
        tail->next = NULL;
    }

    free(temp);
}

// Delete at a Specific Position
void list::deleteAtPosition(int pos) {
    if (pos < 1 || pos > countLength()) {
        printf("Invalid position!\n");
        return;
    }

    if (pos == 1) {
        deleteBeginning();
        return;
    }

    if (pos == countLength()) {
        deleteEnd();
        return;
    }

    Node* temp = tail;
    int curr = countLength();

    while (curr != pos) {
        temp = temp->prev;
        curr--;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    free(temp);
}

// Search for an Element
int list::search(int num) {
    Node* temp = tail;
    int index = countLength();

    while (temp != NULL) {
        if (temp->data == num) {
            return index;
        }
        temp = temp->prev;
        index--;
    }

    return -1;
}

// Display the List
void list::display() {
    if (tail == NULL) {
        printf("List is empty!\n");
        return;
    }

    // Reverse list
    printf("Reverse list: [ ");
    Node* temp = tail;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("]\n");

    // Forward list
    printf("Forward list: [ ");
    temp = tail;
    while (temp->prev != NULL) {
        temp = temp->prev;
    }
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("]\n");
}
