#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#pragma warning(disable:4996)

int calclevel(int num){
    int count=0, power=0;
    while(count<num-1){
        count += pow(2,power);
        power++;
    }
    return power;
}

int arrlen(int level){
    double count=0;
    for(int i=0; i<level; i++){
        count+=pow(2,level);
    }
    return (int)count;
}

int H(int seed){
    if(seed==1){
        return 0;
    }else{
        
    }
}


int main(){
    //10.1
    int input = 0;
    while(scanf("%d",&input)){
        if(input==0){
            break;
        }
        int level = calclevel(input), index=0;
        int *arr = calloc(arrlen(level), sizeof(int));
        for(int i=0; i<=level; i++){
            if(i==0){
                arr[0]==0;
            }else if(i==1){
                arr[1]==1;
            }else{
                
            }
        }
        free(arr);
    }
    return 0;
}