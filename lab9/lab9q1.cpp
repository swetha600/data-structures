#include <stdio.h>

int min(int arr[],int size){

    int min_index=arr[0];
    for(int i=1;i<size;i++){
        if(arr[i]<=min_index){
            min_index=arr[i];
        }
    }

    return min_index;
}


//players function

void players(int pos[],int players[],int no_pos,int grps){

    
    int smallest_index;
    smallest_index=min(pos,no_pos);

    printf("smallest index is:%d\n\n",smallest_index);

    printf("Remaining players after elimation:\n");

    for(int j=0;j<grps;j++){
        if(players[j]>=smallest_index){
            printf("group %d:%d\n",j+1,smallest_index-1);
        }

        else{
            
            printf("group %d:%d\n",j+1,players[j]);
        }
    }

    
}

int main(){

    int test;
    printf("Enter no of test cases:");
    scanf("%d",&test);

    while(test!=0){

        int no_pos;
        int grps;

        printf("Enter no of postions to delete:");
        scanf("%d",&no_pos);

        printf("Enter no of groups:");
        scanf("%d",&grps);

        int playersarr[grps];

        int arr[no_pos];

        for(int i=0; i<no_pos;i++){
            printf("enter position %d to delete:",i+1);
            scanf("%d",&arr[i]);
        }

        for(int i=0;i<grps;i++){
            printf("enter no of players in group %d:",i+1);
            scanf("%d",&playersarr[i]);
        }

        players(arr,playersarr,no_pos,grps);
        


        test--;
    }

    return 0;
}