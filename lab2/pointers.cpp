#include <stdio.h>
#include <stdlib.h>
#include<math.h>

void Index(){

    printf("1.Palindrome\n");
    printf("2.Armstrong Number\n");
    printf("3.Perfect Number\n");    
    printf("4.Exit\n\n");

}


int digitCount( int* num,int* count){
    int *temp=(int*)malloc(sizeof(int));
    *count=0;
    *temp=*num;
    //counting    
    while (*temp>0)
    {
        *temp=*temp/10;
        (*count)++;
    }
    
    free (temp);
    //return count value
    return *count;
}

void armstrong(int* num, int* count,int* sum){
    int *n=(int*)malloc(sizeof(int));
    int *i=(int*)malloc(sizeof(int));
    int *temp=(int*)malloc(sizeof(int));
    *sum=0;
    *temp=*num;

    int *ptrArray; 
    *n=digitCount(num,count);
    ptrArray = (int*) malloc(*(n) * sizeof(int));
    for (*i = 0; (*i) < (*n); (*i)++) {
        ptrArray[(*i)] = (*num)%10;  
        (*num)=(*num)/10;
            }
    for (*i = 0; (*i) < (*n); ++(*i)) {
        int s=pow(ptrArray[(*i)],(*n));
        
        *sum=(*sum) + pow(ptrArray[(*i)],(*n));

            }
    
    if((*temp)==(*sum)){
        printf("%d is an armstrong number\n", (*temp));
    }
    else{
        printf("%d is not armstrong number\n",(*temp));

    }
    (*num)=(*temp);
    free(temp);
    

}

int isPalindromeNum(int *ptrArray,int *ptrarray,int* n){

    int* i=(int*)malloc(sizeof(int));

    for((*i)=0;(*i)<(*n);(*i)++){
        if(*(ptrArray+(*i))==*(ptrarray+(*i))){
            return 1;
        }
    }
        
    return 0;

}

void palindromeNumber( int* num){
    int *ptrArray;
    int *ptrarray;
    int*n=(int*)malloc(sizeof(int));
    int*check=(int*)malloc(sizeof(int));
    int* temp=(int*)malloc(sizeof(int));
    int* i=(int*)malloc(sizeof(int));
    *temp=*num;

    ptrArray = (int*) malloc(*(n) * sizeof(int));
    ptrarray=(int*) malloc(*(n) * sizeof(int));
    for (*i = 0; (*i) < (*n); (*i)++) {
        ptrArray[(*i)] = (*num)%10;
        ptrarray[(*n)-1-(*i)]=(*num)%10;

        (*num)=(*num)/10;
            }
    *check=isPalindromeNum(ptrArray,ptrarray,n);
    if(*check==0){
        printf("%d is not a palindrome\n",*temp);

    }
    else{
        printf("%d is a palindrome\n",*temp);
    }

    (*num)=(*temp);
    free(temp);
    

}

void perfectNumber(int* num){
    
    int* sum=(int*)malloc(sizeof(int));
    (*sum)=0;
    int* i=(int*)malloc(sizeof(int));
    int* temp=(int*)malloc(sizeof(int));
    (*temp)=(*num);

    for((*i)=1;(*i)<(*num);(*i)++){
        if((*temp)%(*i)==0){
            (*sum)+=(*i);
            
        }
    }
    
    if((*sum)==(*num)){
        printf("%d is a perfect number",(*num));
    }   

    else{
        printf("%d is not a perfect number",(*num));
    }

    
    
}

int main() {

    int *num = (int *)malloc(sizeof(int));
    int *sum= (int *)malloc(sizeof(int));
    int *count= (int *)malloc(sizeof(int));
    int *choice=(int *)malloc(sizeof(int));

    Index();

    printf("Enter choice:");
    scanf("%d",choice);

    while((*choice)!=4){
        switch((*choice)){

            case 1:
                printf("Enter a number:");
                scanf("%d",num);
                palindromeNumber(num);
                printf("\n");

                break;
            case 2:
                printf("Enter a number:");
                scanf("%d",num);
                armstrong(num,count,sum);
                printf("\n");

                break;

                
            case 3:
                printf("Enter a number:");
                scanf("%d",num);
                perfectNumber(num);
                printf("\n");

                break;

                


        }
        Index();
        printf("enter choice:");
        scanf("%d",choice);
    }
    
 

    return 0;
}
