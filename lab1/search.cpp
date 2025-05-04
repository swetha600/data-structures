#include<stdio.h>
#include "sort.h"
void indexSearch(){
    printf("1.Linear search\n");
    printf("2.Binary search\n");
    printf("3.Exit\n");
}


int LinearSearchIndex(int arr[],int size){

    int search;
    printf("enter the number you want to search:-");
    scanf("%d",&search);
    for(int i=0;i<size;i++){
        if(arr[i]==search){
            return i;
            

        }
     
    }
    return -1;  
}


void linearSearch(int arr[], int size){
    int lsearch=0;
    lsearch=LinearSearchIndex(arr,size);
    if(lsearch==-1){
        printf("index not found");

    }
    else{
        printf("the number %d is found at index %d",arr[lsearch],lsearch);
    }

}


int searchIndex(int arr[],int high){
    insertionSort(arr,high);
    
    int search;
    printf("enter the number you want to search");
    scanf("%d",&search);

    int low=0;
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (search == arr[mid]){

             return mid;
        }
           
        if (search > arr[mid]){
            low = mid + 1;
        }
            
        else{
                high = mid - 1;
        }
            
  }

  return -1;

  
}


void binarySearch(int arr[], int size){
    insertionSort(arr,size);
    int c=0;
    c=searchIndex(arr,size);
    if(c==-1){
        printf("index not found");

    }
    else{
        printf("the number %d is found at index in the sorted array %d",arr[c],c);
    }

}

int main(){
    int size=0;
    int choice=0;

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

    indexSearch();
    printf("enter the choice:");
    scanf("%d",&choice);

    while(choice!=3){
        switch(choice){

            case 1:
                linearSearch(ar,size);
                printf("\n");
                break;
            case 2:
                binarySearch(ar,size);
                printf("\n");
                break;


        }
        indexSearch();
        printf("enter the number you want to choose");
        scanf("%d",&choice);
    }    

    return 0;
}    