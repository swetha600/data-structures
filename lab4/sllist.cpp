#include <stdio.h>
#include<stdlib.h>

void index(){
    printf("1.Insert beginning\n");
    printf("2.Insert end\n");
    printf("3.Insert position\n");
    printf("4.Delete beginning\n");
    printf("5.Delete end\n");
    printf("6.Delete position\n");
    printf("7.Search\n");
    printf("8.Display\n");
    printf("9.Display Reverse\n");
    printf("10.Reverse Link\n");    
    printf("11.Exit\n\n");


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

    int InsertBeginning(int);
    int InsertEnd(int);
    void Display();
    int CountLength();
    void DisplayReverse();
    void deleteEnd();
    int insertPosition(int,int);
    void deleteBeginning();
    void deletePosition(int pos);
    void search(int value);
    void reverseLinks();

};
int main(){

    list l;
    int choice;

    index();
    printf("enter choice:");
    scanf("%d",&choice);
    while(choice!=11){
        switch(choice){
            case 1:
                int num;
                printf("enter the number you want to add:");
                scanf("%d",&num);
                l.InsertBeginning(num);

            break;
            case 2:
                int num1;
                printf("enter the number you want to add:");
                scanf("%d",&num1);
                l.InsertEnd(num1);

            break;

            case 3:
                int num2,pos;
                printf("enter the number you want to add:");
                scanf("%d",&num2);
                printf("enter position:");
                scanf("%d",&pos);
                l.insertPosition(num2,pos);

            break;

            case 4:
                l.deleteBeginning();
            break;

            case 5:
                l.deleteEnd();
            break;

            case 6:
                int pos1;
                printf("enter position you want to delete:");
                scanf("%d",&pos1);
                l.deletePosition(pos1);


            break;

            case 7:
                int num3;
                printf("enter number you want to search:");
                scanf("%d",&num3);
                l.search(num3);

            break;

            case 8:
                l.Display();
            break;

            case 9:
                l.DisplayReverse();

            break;

            case 10:
                l.reverseLinks();

            break;



        }
        index();
        printf("enter choice:");
        scanf("%d",&choice);
    }





    return 0;
}

//insertion in the beginning

int list::InsertBeginning(int num){

    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=num;
    newnode->next=head;
    head=newnode;

    return 0;
}

//insertion in the end

int list::InsertEnd(int num){

    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=num;
    newnode->next=NULL;
    struct node* temp;
    temp=head;

    if(head==NULL){
        head=newnode;
    }
    else{
        while(temp->next!=NULL){
            temp=temp->next;
        }

        temp->next=newnode;
    }
   
    return 0;
}

//displaying the linked list

void list::Display(){
    struct node* temp;
    temp=head;
    printf("[");
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("]\n");

}

//counting the length of the linked list
int list::CountLength(){
    int count=0;
    struct node* temp;
    temp=head;

    if(head==NULL){
        return 0;
    }
    else{
        while(temp->next!=NULL){
            temp=temp->next;
            count++;
        }        
        return (count+1);    
    }

}

//display reverse
void list::DisplayReverse(){

    int count=CountLength();
    
    struct node* temp;
    temp=head;
    printf("[");
   

    for(int i=0;i<(count);i++){
        int val=0; 
        temp=head;   
        while(val<(count-i-1)&&temp!=NULL){
            temp=temp->next;
            val++;
        }
        printf("%d ",temp->data);            
        }
        printf("]\n");    

}


//insert in position
int list::insertPosition(int value, int pos) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    if (pos == 1) {
        newNode->next = head;
        head = newNode;
        return 1;
    }
    struct node* temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;
    if (temp == NULL) {
        printf("Position out of range!\n");
        free(newNode);
        return 1;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}
//deletion in beginning;
void list::deleteBeginning() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct node* temp = head;
    head = head->next;
    free(temp);
}

//deletion in end

void list::deleteEnd() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }
    struct node* temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;
    free(temp->next);
    temp->next = NULL;
}
//deletion in position

void list::deletePosition(int pos) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct node* temp = head;
    if (pos == 1) {
        head = head->next;
        free(temp);
        return;
    }
    struct node* prev = NULL;
    for (int i = 1; i < pos && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position out of range!\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
}

//searching for a value in the linked list

void list::search(int value) {
    struct node* temp = head;
    int pos = 1;
    while (temp != NULL) {
        if (temp->data == value) {
            printf("Element found at position %d\n", pos);
            return;
        }
        temp = temp->next;
        pos++;
    }
    printf("Element not found\n");
}
//reverse link
void list::reverseLinks() {
    struct node *prev = NULL, *curr = head, *next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}


