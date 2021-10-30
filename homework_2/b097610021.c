#include <stdio.h>
#pragma warning(disable:4996)

int main(){
    //1.1
    //set 2 variables
    int a, b, c, temp;
    printf("請隨意輸入三不同整數 a n c:\n");
    //input a b c
    printf("a為 ");
    scanf("%d", &a);
    printf("b為 ");
    scanf("%d", &b);
    printf("c為 ");
    scanf("%d", &c);
    //calculate
    if(a>b){
        temp = a;
    }else{
        temp = b;
    }
    if(temp<c){
        temp = c;
    }
    //print
    if(temp==a){
        printf("a is the largest");
    }else if(temp==b){
        printf("b is the largest");
    }else{
        printf("c is the largest");
    }
    printf("\n");
    //1.2
    int array[12] = {31,28,31,30,31,30,31,31,30,31,30,31}, month;
    //input month
    printf("請輸入月份\n");
    scanf("%d", &month);
    //print
    printf("%d 月有 %d 天\n",month, array[month-1]);
    return 0;
}