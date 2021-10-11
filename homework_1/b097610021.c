#include <stdio.h>
#pragma warning(disable:4996)

int main(){
    //1.1
    //set 2 variables
    float cel, fah;
    printf("請輸入攝氏溫度：");
    //input celcius
    scanf("%f", &cel);
    //calculate
    fah = (cel*9)/5+32;
    //output fahrenheit
    printf("\n華氏溫度為：%f\n",fah);

    //1.2
    //set 2 variables
    float x, y;
    printf("請輸入兩個數：\n");
    scanf("%f", &x);
    scanf("%f", &y);
    //add
    printf("\n相加為：%f",x+y);
    //sub
    printf("\n相減為：%f",x-y);
    //multi
    printf("\n相乘為：%f",x*y);
    //div
    if(y==0){
        //y==0
        printf("\n除數為零，無法計算");
    }else{
        //y!=0
        printf("\n相除為：%f",x/y);
    }
    printf("\n");
    return 0;
}