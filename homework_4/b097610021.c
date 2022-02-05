#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#pragma warning(disable:4996)

//bubble sort
void sort(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[j] > arr[i]) {
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
}

int main(){
    //1.1
    //set an array
    int array[10], len = 0;
    for(int i=0; i<10; i++){
        array[i] = (rand() % 1000) +1;
    }
    srand(time(NULL));
    //sort
    sort(array, 10);
    //calculate length of array
    len = (rand() % 9) +2;
    printf("The array given is:\n");
    for(int i=0; i<len; i++){
        printf("%d ",array[i]);
    }
    //print rearranged of array
    printf("\nThe new array after rearranging:\n");
    for(int i=0; i<len; i++){
        if(i==0){
            printf("%d ",array[0]);
        }else if(i==len-1){
            printf("%d ",array[i]);
        }else{
            if(i%2==1){
                printf("%d ",array[i+1]);
            }else{
                printf("%d ",array[i-1]);
            }
        }
    }
    //1.2
    //initial array
    for(int i=0; i<10; i++){
        array[i] = (rand() % 1000) +1;
    }
    //calculate length of array
    len = (rand() % 9) +2;
    printf("\nThe array given is:\n");
    for(int i=0; i<len; i++){
        printf("%d ",array[i]);
    }
    //get length of subarray
    int sub, temp=0;
    printf("\nThe length of each subarray is: ");
    scanf("%d", &sub);
    //calculate
    printf("The contigious subarray of length %d and their maximum value are:\n", sub);
    for(int i=0; i<(len-sub+1); i++){
        temp=array[i];
        for(int j=0; j<sub; j++){
            printf("%d ",array[i+j]);
            if(temp<array[i+j]){
                temp = array[i+j];
            }
        }
        printf("----> %d\n",temp);
    }
    return 0;
}