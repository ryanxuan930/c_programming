#include <stdio.h>
#pragma warning(disable:4996)

int is_prime(int x){
    if(x < 2){
        return 0;
    }
    for(int i = 2; i * i <= x; ++i){
        if(x % i == 0){
            return 0;
        }
    }
    return 1;  
}

int main(){
    //1.1
    //set 2 variables
    int input=0, sum=0;
    printf("Input the number of terms : ");
    //input number
    scanf("%d", &input);
    //calculate
    for(int i = 1; i <= input; i++){
        printf("%d ",i*i);
        sum += i*i;
    }
    printf("\nThe Sum of Square Natural Number upto %d terms = %d\n",input, sum);
    //1.2
    input = 0;
    printf("input the number: ");
    //input number
    scanf("%d", &input);
    for(int i=1;i<=input/2;i++){
        if(is_prime(i) && is_prime(input-i)){
            printf("%d can be written as %d + %d\n",input, i, input-i);
        }
    }
    return 0;
}