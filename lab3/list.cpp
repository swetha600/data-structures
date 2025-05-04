//Program to  implement List ADT using an array of SIZE 5
#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

void index(){
    printf("1.Insert beginning\n");
    printf("2.Insert End\n");
    printf("3.Insert Position\n");
    printf("4.Delete Beginning\n");
    printf("5.Delete End\n");
    printf("6.Delete Position\n");
    printf("7.Search\n");
    printf("8.Display\n");
    printf("9.Rotate\n");
    printf("10.Exit\n\n");
}

class list{

    int cur;

private:    
    int arr[SIZE];
    
    public:

        list(){
            cur=-1;
            for(int i=0;i<SIZE;i++){
                arr[i]=-1;
            }
        }    
        int insertbeginning(int);
        int insertend(int);
        int insertposition(int,int);
        int deletebeginning();
        int deleteend();
        int deleteposition(int);
        int search(int);
        void rotatelist(int);
        void displayarr();
        
};
  
int main(){
    list L1;
    
    int choice;

    index();
    printf("Enter choice:");
    scanf("%d",&choice);

    while (choice!=10){

        switch(choice){
            case 1:
            //inserting in the begining
                 int num;
                 printf("Enter the element you want to insert:");
                 scanf("%d",&num);
                 L1.insertbeginning(num);
                 break;
            case 2:
            //insertion in the end
                 int num1;
                 printf("Enter the element you want to insert:");
                 scanf("%d",&num1);
                 L1.insertend(num1);
                 break;
            case 3:
            //insertion in the position
                 int num2;
                 int pos;
                 printf("Enter the element you want to insert:");
                 scanf("%d",&num2);
                 printf("Enter the position:");
                 scanf("%d",&pos);
                 L1.insertposition(num2,pos);
                 break;
            case 4:
            //deletion in the begining
                 L1.deletebeginning();
                 break;
            case 5:
            //deletion in the end
                 L1.deleteend();
                 break;
            case 6:
            //deletion in position   
                 int pos1;
                 printf("Enter the position:");
                 scanf("%d",&pos1);
                 L1.deleteposition(pos1);
                 break;
            case 7:
            //searchinh
                 int num6;
                 printf("Enter element to be searched:");
                 scanf("%d",&num6);
                 if (L1.search(num6)!=-1){
                    printf("The element is in the position %d\n",L1.search(num6));
                 }
                 else{
                    printf("element not found\n");
                 }
                 break;
            case 8:
            //display
                 printf("Elements in the array");
                 L1.displayarr();
                 break;
            case 9:
            //rotation
                 int num7;
                 printf("Enter the no of times you want to rotate:");
                 scanf("%d",&num7);
                 L1.rotatelist(num7);
                 break;  


        }

        index();
        printf("enter choice:");
        scanf("%d",&choice);


     
    }

    return 0;

}
//inserting at beginning
int list :: insertbeginning(int val){
    if(cur+1>=SIZE){
        printf("list is completely filled\n");
        return -1;
    }
    rotatelist(1);
    arr[0]=val;
    cur=cur+1;
    
    return 1;
}
//inserting at the end
int list :: insertend(int val){
    if(cur+1>=SIZE){
        printf("list is full\n");
        return -1;
    }
    arr[cur+1]=val;
    cur++;
    
    return 1;

}
//inserting at a particular position
int list :: insertposition(int val,int pos){
    if(cur+1>=SIZE){
        printf("list is full\n");
        return -1;
    }
    for(int i=cur+1;i>pos;i--){
        arr[i]=arr[i-1];
        cur++;   
    }
    arr[pos]=val;
    
    return 1;

}
//deleting at the beginning
int list :: deletebeginning(){
    if(cur==-1){
        printf("list is empty\n");
        return -1;
    }
    int temp;
    for(int i =0;i<cur;i++){
        if(arr[i]==-1){
            continue;
        }

        else{
            temp=arr[i];
            arr[i]=-1;
            break;
        }
    }
    cur--;
    
    return temp;
}


int list::deleteend() {
        if (cur == -1) {
            printf("List is empty\n");
            return -1;
        }
        int temp;
        for(int i =0;i<cur;i++){
            if(arr[SIZE-1-i]==-1){
                continue;
            }
    
            else{
                temp=arr[SIZE-1-i];
                arr[SIZE-1-i]=-1;
                break;
            }
        }    

        cur--;
        return temp;
    }

//deleting at a particular position
int list :: deleteposition(int pos){
    if(cur==-1){
        printf("list is empty\n");
        return -1;
    }
    int temp=arr[pos];
    arr[pos]=-1;
    cur--;
    return temp;
    

}
//searching for a particular value
int list :: search(int val){
    for(int i=0;i<SIZE;i++){
        if (arr[i]==val){
            return (i+1);
        }
    }
    return -1;
}

//rotate the list
void list :: rotatelist(int val){
    int temp=0;
    int count=0;
    while(count<val){
        temp=arr[SIZE-1];
        for(int i=1;i<SIZE;i++){
            arr[SIZE-i]=arr[SIZE-(i+1)];
        }
        arr[0]=temp;
        count++;
    }
}

void list :: displayarr(){
    printf("[");
    for(int i=0;i<SIZE;i++){
        if(arr[i]==-1){
            continue;
        }
        else{
            printf("%d  ",arr[i]);

        }
        
    }
    printf("]");
    printf("\n");

}