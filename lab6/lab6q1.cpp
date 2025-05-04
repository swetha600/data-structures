#include <stdio.h>
#define SIZE 5
void index(){
    printf("1.push\n2.pop\n3.peek\n4.exit\n\n");
}

class stack{
    int temp;
    char arr[SIZE];
public:
    stack(){
        temp=-1;
        for(int i=0;i<=SIZE;i++){
            arr[i]=' ';
        }
    }
    void push(char);
    char pop();
    char peek();
    void display();



};

int main(){
    stack s;
    int choice;
    index();
    printf("enter choice:");
    scanf("%d",&choice);
    while(choice!=4){
        switch(choice){
            case 1:
                char elem;
                printf("enter charcter to be inserted:");
                scanf("%s",&elem);
                s.push(elem);
                printf("\n");
                s.display();
                printf("\n");
                break;
            case 2:
                char elem1;
                elem1=s.pop();
                printf("element returned:%c\n",elem1);
                s.display();
                printf("\n");
                break;
            case 3:
                char elem2;
                elem2=s.peek();
                printf("element:%c",elem2);
                //s.display();
                printf("\n");
                break;

        }
        printf("\n");
        printf("enter choice:");
        scanf("%d",&choice);
    }
    return 0;
}

void stack::push(char elem){
    if(temp+1>=SIZE){
        printf("stack full!!");
        return;
    }
    arr[temp+1]=elem;
    temp++;

}
char stack::pop(){
    if(temp==-1){
        printf("stack empty!!");
        return ' ';
    }
    char returnc;
    returnc=arr[temp];
    arr[temp]=' ';
    temp--;
    return returnc;

}
char stack::peek(){
    if(temp==-1){
        printf("stack empty!!");
        return ' ';
    }
    return arr[temp];

}
void stack::display(){
    for(int i=0;i<SIZE;i++){
        if(arr[i]==' '){
            continue;
        }
        else{
            printf("%c",arr[i]);
        }
    }

}