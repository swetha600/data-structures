//menu driven program for circular linked list
#include<stdio.h>
#include<stdlib.h>

void IndexMenu(){
    printf("1.Insert Beginning\n");
    printf("2.Insert End\n");
    printf("3.Insert position\n");
    printf("4.Delete Beginning\n");
    printf("5.Delete End\n");
    printf("6.Delete Position\n");
    printf("7.Search\n");
    printf("8.Display\n");
    printf("9.Exit\n\n");
}

class list{
    struct node{
        int data;
        struct node* next;    
    }*head;

public:
    list(){
        head=NULL;
    } 
    void InsertAtBeginning(int);
    void InsertAtEnd(int);
    void InsertAtPosition(int, int);
    int DeleteAtEnd();
    int DeleteAtPosition(int);
    int DeleteAtBeginning();
    void Display();
    int Search(int);
};

int main(){

    list l;
    int index;    
    int returnnum;
    int choice;
    IndexMenu();
    
    printf("enter choice:");
    scanf("%d",&choice);
    while(choice!=9){
        switch(choice){
            case 1:
                int num;
                printf("enter number to insert:");
                scanf("%d",&num);
                l.InsertAtBeginning(num);
                break;
            case 2:
                int num1;
                printf("enter number to insert:");
                scanf("%d",&num1);
                l.InsertAtEnd(num1);
                break;
            case 3:
                int num2;
                int pos;
                printf("enter number to insert:");
                scanf("%d",&num2);
                printf("enter position:");
                scanf("%d",&pos);
                l.InsertAtPosition(num2,pos);

                break;
            case 4:
                returnnum=l.DeleteAtBeginning();
                if (returnnum==-1){
                    break;
                }
                else{
                    printf("%d is deleted",returnnum);
                }     
                break;
            case 5:
                returnnum=l.DeleteAtEnd();
                if (returnnum==-1){
                    break;
                }
                else{
                    printf("%d is deleted",returnnum);
                }
                break;
            case 6:
                int pos1;
                printf("enter position to delete:");
                scanf("%d",&pos1);
                returnnum=l.DeleteAtPosition(pos1);
                if (returnnum==-1){
                    break;
                }
                else{
                    printf("%d is deleted",returnnum);
                }
                break;
            case 7:
                int num3;
                printf("enter number to Search:");
                scanf("%d",&num3);
                index=l.Search(num3);
                if(index==-1){
                    printf("element not found!");
                }
                else{
                    printf("found at %d position",index);
                }
                break;
            case 8:
                l.Display();
                break;
        }
        IndexMenu();
        printf("enter choice:");
        scanf("%d",&choice);
    }
    
    


    return 0;
}
//Insertion In The Beginning
void list::InsertAtBeginning(int num){


    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=num;
    if (head==NULL){
        head=newnode;
        newnode->next=head;
    }

    else{
        struct node* temp;
        temp=head;
        
        while(temp->next!=head){
            temp=temp->next;

        }

        temp->next=newnode;
        newnode->next=head;
        head=newnode;
    }

}


//display the circular linked list
void list::Display(){

    if (head==NULL){
        printf("list is empty!\n");
        return;
    }

    else{
        struct node* temp;
        temp=head;
        printf("[");

        while(temp->next!=head){
            printf("%d ",temp->data);
            temp=temp->next;
        }

        printf("%d ",temp->data);
        printf("]\n");

    }

    return;
}


//Insertion In The End
void list::InsertAtEnd(int num){

        struct node* newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data=num;
        struct node* temp;
        temp=head;
    
        if(head==NULL){
            head=newnode;
            newnode->next=head;
        }
        else{
            while(temp->next!=head){
                temp=temp->next;
            }
    
            temp->next=newnode;
            newnode->next=head;
        }
       
        
}
//Insertion Of An Element At A Specific Position
void list::InsertAtPosition(int num,int pos){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = num;
    if (pos == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }
    struct node* temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;
    if (temp == NULL) {
        printf("Position out of range!\n");
        free(newNode);
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}



// Delete from beginning
int list::DeleteAtBeginning() {
    if (head == NULL) {
        printf("List is empty!\n");
        return -1;
    }

    struct node* temp = head;
    int num = temp->data;

    if (head->next == head) { // Only one node
        free(head);
        head = NULL;
        return num;
    }

    struct node* last = head;
    while (last->next !=head) {
        last = last->next;
    }

    last->next = head->next;
    head = head->next;
    free(temp);

    return num;
}

// Deletion from end
int list::DeleteAtEnd() {
    if (head == NULL) {
        printf("List is empty!\n");
        return -1;
    }

    if (head->next == head) { 
        int num = head->data;
        free(head);
        head = NULL;
        return num;
    }

    struct node* temp = head;
    struct node* prev = NULL;
    while (temp->next->next != head) {
        temp = temp->next;
    }

    prev = temp;
    int num = temp->next->data;
    free(temp->next);
    prev->next = head;

    return num;
}

// Deleting an element of a specific position
int list::DeleteAtPosition(int pos) {
    if (head == NULL) {
        printf("List is empty!\n");
        return -1;
    }

    if (pos == 1) {
        return DeleteAtBeginning();
    }

    struct node* temp = head;
    struct node* prev = NULL;
    for (int i = 1; i < pos && temp->next != head; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp->next == head && pos > 1) {
        printf("Position out of range!\n");
        return -1;
    }

    int num = temp->data;
    prev->next = temp->next;
    free(temp);

    return num;
}

//Searching for an eelement in the list

int list::Search(int num){
    struct node* temp;
    int count=1;
    temp=head;
    if(head->data==num){
        return 1;
    }
    while(temp->next!=head){
        if(temp->data==num){
            return count;
        }
        temp=temp->next;
        count++;
    }

    if(temp->data==num){
        return count++;
    }

    return -1;

}
