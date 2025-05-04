#include <stdio.h>
#include <stdlib.h>

class list{
    struct node{
        int data;
        struct node *next;
    }*head;
    private:
        node *gethead() {return head;}
    public:
       list(){
           head =NULL;
       }
    void insertascending(int);
    void display();
    list merge(list &other);
};


void list :: insertascending(int value){
    node* newNode = (node*)malloc(sizeof(node)); 
    newNode->data = value;
    newNode->next = NULL;
    if (!head || head->data >= value) { 
            newNode->next = head;
            head = newNode;
            return;
        }

    node* current = head;
    while (current->next && current->next->data < value) {
            current = current->next;
        }

    newNode->next = current->next;
    current->next = newNode;

}

void list :: display(){
    struct node* temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}


list list::merge(list &other) {
    list mergedList;
    node *head1 = this->gethead();
    node *head2 = other.gethead();
    node **tail = &(mergedList.head); 

    while (head1 && head2) {
        if (head1->data < head2->data) {
            *tail = head1;
            head1 = head1->next;
        } else {
            *tail = head2;
            head2 = head2->next;
        }
        tail = &((*tail)->next);
    }

    *tail = (head1) ? head1 : head2;

    return mergedList;
}