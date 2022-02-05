#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}

int *bubble_sort(int arr[]){
    int i, j, temp, len=10;
    for(i=0; i<len-1; i++){
        for(j=0; j<(len-i-1); j++){
            if(arr[j]>arr[j+1]){
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
    return arr;
}

int *insertion_sort(int arr[]){
    int i, j, temp, len=10;
    for(i=0; i<len; i++){
        temp = arr[i];
        for(j=(i-1); j>=0 && arr[j]>temp; j--){
            arr[j+1] = arr[j];
        }
        arr[j+1] = temp;
    }
    return arr;
}

int *selection_sort(int arr[]){
    int i, j, temp, len=10;
    for(i=0; i<len-1; i++){
        temp = i;
        for(j=i+1; j<len; j++){
            if(arr[j]<arr[temp]){
                temp = j;
            }
        }
        swap(&arr[i], &arr[temp]);
    }
    return arr;
}

int main(){
    //10.1
    while(1==1){
        int list[10], method;
        puts("Please enter ten numbers:");
        scanf("%d %d %d %d %d %d %d %d %d %d",&list[0],&list[1],&list[2],&list[3],&list[4],&list[5],&list[6],&list[7],&list[8],&list[9]);
        puts("Please select sorting method:");
        printf("(1)Bubble sort (2)Insertion Sort (3)Selection Sort >>");
        scanf("%d",&method);
        switch(method){
            case 1:
                bubble_sort(list);
                break;
            case 2:
                insertion_sort(list);
                break;
            case 3:
                selection_sort(list);
                break;
        }
        printf("%d %d %d %d %d %d %d %d %d %d\n\n",list[0],list[1],list[2],list[3],list[4],list[5],list[6],list[7],list[8],list[9]);
    }
    return 0;
}