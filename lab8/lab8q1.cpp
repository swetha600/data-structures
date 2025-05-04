#include<stdio.h>

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

}



//finding the maximum number in the tower
void solve(){
    int size;
    scanf("%d",&size);
    int arr[size];
    for(int i=0;i<=size-1;i++){
        scanf("%d",&arr[i]);

    }

    bubbleSort(arr,size);


    int first;
    int sec;
    first=arr[0];
    for(int i=1;i<=size-1;i*2){
        sec=arr[i];
        while(first<=sec){
            first++;
            sec--;
        }

        int last;
        last=arr[size-1];
        while(first<=last){
            first++;
            last--;
        }


    }
    printf("output:");
    printf("%d\n",first);
}

int main(){

    int loop;
    printf("enter no.of loops:");
    scanf("%d",&loop);

    while(loop!=0){
        solve();
        loop--;
    }


    return 0;
}