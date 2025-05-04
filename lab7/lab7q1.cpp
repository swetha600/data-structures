//A menu driven program to perform queue operations
#include <stdio.h>
# define SIZE 5

class queue{
    int arr[SIZE];
    int front =-1;
    int rear =-1;

    public:
    queue(){
        front=-1;
        rear=-1;
    }

    void Enqueue(int);
    int Dequeue();
    int peek();
};

int main(){
    int choice;
    queue q;
    do{
        printf("  Menu\n");
        printf("1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("3.Peek\n");
        printf("4.Exit\n");

        printf("Enter a number from 1-4:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                int val;
                printf("Enter the element you want to Enqueue:");
                scanf("%d",&val);
                q.Enqueue(val);
                break;
            case 2:
                printf("The Dequeued Element is:%d",q.Dequeue());
                break;
            case 3:
                break;
            case 4:
                printf("EXiting.....\n");
                break;            
        }

    }while(choice !=4);
    return 0;
}

void queue :: Enqueue(int val){
    if(rear==SIZE-1){
        printf("Overflow!");
    }
    else if (front=rear=-1){
        arr[rear]=val;
    }
    else{
        rear++;
        arr[rear]=val;
    }
}

int queue :: Dequeue(){
    int temp;
    if(front ==-1 && rear==-1){
        printf("Empty!");
    }
    else if(front==rear){
        front=rear=-1;
    }
    else{
        temp=arr[front];
        front++;
    }
    return temp;
}


