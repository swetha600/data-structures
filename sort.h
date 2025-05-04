void index(){
    printf("1.Bubble sort\n");
    printf("2.Selection sort\n");
    printf("3.Insertion sort\n");
    printf("4.Exit\n");
    printf("\n\n");

}
void bubbleSort( int arr[], int size){
    for(int i=0;i<size;i++){
        for(int j=i+1;j<size;j++){
            if(arr[i]>arr[j]){
                int a=arr[i];
                int b=arr[j];
                arr[i]=b;
                arr[j]=a;
            }
        }
    }
    printf("[");
    for(int k=0;k<size;k++){
        
        printf("%d\t",arr[k]);
        
        
    }
    printf("]\n");
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
       
        printf("%d\t",arr[k]);
        
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
    
}