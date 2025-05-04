#include<stdio.h>

void index(){
    printf("1.Bubble sort\n");
    printf("2.Selection sort\n");
    printf("3.Insertion sort\n");
    printf("4.Exit\n");
    printf("\n\n");

}

void selectionSort(int arr[],int size){
    for(int i=0;i<size-1;i++){
        int id=i;
        for(int j=i+1;j<size;j++){
            if(arr[id]>arr[j]){   
                id=j;
            }
            int a=arr[i];
            arr[i]=arr[id];
            arr[id]=a;
        }
    }
    printf("[");
    for(int k=0;k<size;k++){
        
        printf("%d ",arr[k]);
    }
    printf("]\n");
}

void insertionSort(int arr[],int size){
    for(int i=1;i<size;i++){
        int key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;
    }
    printf("[");
    for(int k=0;k<size;k++){        
        printf("%d ",arr[k]);
    }
    printf("]\n");
}

int main(){
    int c=0;
    int size=0;

    //creating the array
    printf("enter the size of the array");
    scanf("%d",&size);
    int ar[size];

    //inserting values in the array
    for(int i=0;i<size;i++){
        printf("enter value at index %d: ",i);
        scanf("%d",ar+i);
    }
    printf("[");
    for(int k=0;k<size;k++){
        
        printf("%d ",ar[k]);
    }
    printf("]\n");
    
    //menu driven
    index();
    printf("enter the number you want to choose");
    scanf("%d",&c);
    while( c!=4){
        switch(c){
        case 1:
            
            break;
        case 2:
            selectionSort(ar,size);
            break;
        case 3:
            insertionSort(ar,size);
            break;
        
    }
        index();
        printf("enter the number you want to choose");
        scanf("%d",&c);
    }
    
    return 0;
}