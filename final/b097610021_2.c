#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}

int *sort(int arr[]){
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

int main(){
    int buff[100000], index=0;
    char temp;
    while(scanf("%c", &temp)){
        if(temp=='\n'){
            int *array = calloc(index, sizeof(int));
            for(int i=0; i<index; i++){
                array[i] = buff[i];
            }
            sort(array);
            for(int i=0; i<index; i++){
                printf("%d\t",array[i]);
            }
            index=0;
            int buff[100000];
        }else{
            buff[index] = (int) temp;
            index++;
        }
    }
}