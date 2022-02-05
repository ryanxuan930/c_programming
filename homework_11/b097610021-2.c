#include <stdio.h>

int main() {
    int test=0;
    scanf("%d",&test);
    for(int i=0; i<test; i++){
        char *arr = calloc(80, sizeof(char));
        int j=0;
        char temp;
        while(scanf("%c", &temp)){
            if(temp=='\n'){
                break;
            }else{
                arr[j]=temp;
                j++;
            }
        }
        char str[80];
        for(int k=1; k<=j; k++){
            if(j%k==0){
                int m=0;
            }
        }
    }
    return 0;
}