#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#pragma warning(disable:4996)

void stringLength(char *param){
    printf("%lu\n",strlen(param));
    return;
}

void equalString(char *param1, char *param2){
    if(strlen(param1) != strlen(param2)){
        puts("兩個字串不相等");
        return;
    }else{
        for(int i=0; i<strlen(param1); i++){
            if(param1[i]!=param2[i]){
                puts("兩個字串不相等");
                return;
            }
        }
        puts("兩個字串相等");
    }
    return;
}

void mergeString(char *param1, char *param2){
    printf("%s%s\n", param1, param2);
    return;
}

void reverseString(char *param1, char *param2){
    for(int i=strlen(param2); i>=0; i--){
        printf("%c", param2[i]);
    }
    for(int i=strlen(param1); i>=0; i--){
        printf("%c", param1[i]);
    }
    return;
}

int main(){
    //9.1
    char str1[10000];
    char str2[10000];
    printf("請輸入第一個字串:");
    scanf("%s",str1);
    printf("請輸入第二個字串:");
    scanf("%s",str2);
    printf("\n");
    printf("計算字串一長度:");
    stringLength(str1);
    printf("計算字串二長度:");
    stringLength(str2);
    equalString(str1,str2);
    printf("連接兩個字串:");
    mergeString(str1,str2);
    printf("顛倒連接後字串:");
    reverseString(str1,str2);
    printf("\n");
    //9.2
    while(1==1){
        char str1[1000];
        char str2[1000];
        int count1[26] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
        int count2[26] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
        fgets(str1,1000,stdin);
        fgets(str2,1000,stdin);
        for(int i=0;i<strlen(str1);i++){
            count1[str1[i]-97]=1;
        }
        for(int i=0;i<strlen(str2);i++){
            count2[str2[i]-97]=1;
        }
        for(int i=0;i<26;i++){
            if(count1[i]>0&&count2[i]>0){
                printf("%c",i+97);
            }
        }
        printf("\n");
    }
    return 0;
}