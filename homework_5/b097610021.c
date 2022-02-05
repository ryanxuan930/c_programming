#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

const char *makestr(size_t len, const char str[]){
    char temp[1000001]={0};
    for(size_t i=0; i<len; i++){
        strcat(temp,str);
    }
    return temp;
}

int numlen(long long n){
    int len=0;
    while(n!=0){
        n /= 10;
        ++len;
    }
    return len;
}

long long sumup(int len,long long n){
    long long temp=0;
    for(int i=0;i<len;i++){
        temp += n%10;
        n /= 10;
    }
    return temp;
}

int main(){
    //5.1
    char input[1000001]={0};
    while(scanf("%s",input)){
        if(input[0]=='.'){
            break;
        }
        for(size_t i=1; i<=strlen(input); i++){
            if(strlen(input)%i>0){
                continue;
            }else{
                char str[1000001]={0};
                size_t times = strlen(input)/i;
                for(int j=0; j<(strlen(input)-(i-1)); j++){
                    strncpy(str, &input[j],i);
                    if(strcmp(input,makestr(times, str))==0){
                        printf("%lu",times);
                        goto END;
                    }
                }
            }
        }
        END:
        printf("\n");
    }
    //5.2
    int num_len = 0;
    long long num = 0, target=0;;
    while(scanf("%lld",&num)){
        if(num==0){
            break;
        }
        target = num;
        num_len = numlen(target);
        while(num_len>1){
            target = sumup(numlen(target), target);
            num_len = numlen(target);
        }
        printf("%lld\n", target);
    }
    return 0;
}