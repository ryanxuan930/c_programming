#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#pragma warning(disable:4996)

int main(){
    //7.1
    //I use the absolute path because my computer cannot find the text file when using the relative path.
    char str1[33], str2[33], str3[33];
    FILE *fp1 = fopen("/Users/ryanchang/Library/Mobile Documents/com~apple~CloudDocs/Project/c_programming/homework_7/final.txt","r");
    fgets(str1, sizeof(str1), fp1);
    FILE *fp2 = fopen("/Users/ryanchang/Library/Mobile Documents/com~apple~CloudDocs/Project/c_programming/homework_7/key.txt","r");
    fgets(str2, sizeof(str2), fp2);
    int i=0, j=0;
    for(i=0; i<32; i++){
        if(str2[i]=='@'){
            str3[j] = str1[i];
            j++;
        }
    }
    FILE *fp3 = fopen("/Users/ryanchang/Library/Mobile Documents/com~apple~CloudDocs/Project/c_programming/homework_7/content.txt","w+");
    
    for(i=0; i<=j; i++){
        fputc(str3[i], fp3);
    }
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    //7.2
    int num=0;
    scanf("%d\n", &num);
    for(i=0; i<num; i++){
        int j=0, k=0, arr1[1000];
        float arr2[1000], output[1000];
        char temp;
        j=0;
        do { 
            scanf("%d%c", &arr1[j], &temp); 
            j++; 
        } while(temp != '\n');  
        j=0;
        do { 
            scanf("%f%c", &arr2[j], &temp); 
            j++; 
        } while(temp != '\n'); 
        for(k=0; k<j; k++){
            output[arr1[k]-1] = arr2[k];
        }
        FILE *fp4 = fopen("/Users/ryanchang/Library/Mobile Documents/com~apple~CloudDocs/Project/c_programming/homework_7/output.txt","w+");
        for(k=(j-1); k>=0; k--){
            fprintf(fp4, "%.1f\n", output[k]);
        }
        fclose(fp4);
        putchar('\n');
    }
    return 0;
}