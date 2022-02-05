#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#pragma warning(disable:4996)

//to store the number of A, T, C, G in each column of the inputted dna strings
typedef struct {
    int a;
    int t;
    int c;
    int g;
} class_dna;

char mode(class_dna dna){
    int max = 0;
    int a = dna.a;
    int t = dna.t;
    int c = dna.c;
    int g = dna.g;
    max = a;
    if(t > max){
        max = t;
    }
    if(c > max){
        max = c;
    }
    if(g > max){
        max = g;
    }
    if(a == max){
        return 'A';
    }else if(c == max){
        return 'C';
    }else if(g == max){
        return 'G';
    }else{
        return 'T';
    }
}

int main(){
    //8.1
    srand(time(NULL));
    int count = 0, random=0, num=0;
    //open file
    FILE *fp1 = fopen("/Users/ryanchang/Library/Mobile Documents/com~apple~CloudDocs/Project/c_programming/homework_8/random.txt","w+");
    while(count<1000){
        random = rand() % 58 + 65;
        if((random>=65 && random<=90) || (random>=97 && random<=122)){
            fprintf(fp1, "%c", random);
            count++;
        }
    }
    fclose(fp1);

    //reopen
    char str[1001];
    FILE *fp2 = fopen("/Users/ryanchang/Library/Mobile Documents/com~apple~CloudDocs/Project/c_programming/homework_8/random.txt","r+");
    fgets(str, sizeof(str), fp2);
    char input;
    printf("請輸入要尋找的字元: ");
    while(scanf("%c", &input)){
        //input * to stop looping;
        if(input == '*'){
            break;
        }
        //when pressing enter
        if(input != '\n'){
            num=0;
            //counting
            for(int i=0; i<1000; i++){
                if(input == str[i]){
                    num++;
                }
            }
            printf("字元'%c'一共找到: %d\n",input,num);
            printf("請輸入要尋找的字元: ");
        }
    }
    fclose(fp2);
    //8.2
    //case number
    int case_num = 0;
    scanf("%d", &case_num);

    for(int i=0; i < case_num; i++){
        //create an unit*length array
        int unit=0, length=0;
        scanf("%d %d", &unit, &length);
        char **arr = calloc(unit, sizeof(char*));
        for(int j=0; j<unit; j++){
            arr[j] = calloc((length+1), sizeof(char));
            scanf("%s",arr[j]);
        }
        class_dna *dna = calloc(length, sizeof(class_dna));
        char *output = calloc(length+1, sizeof(char));
        int diff_num = 0;
        for(int j=0; j<length; j++){
            for(int k=0; k<unit; k++){
                if(arr[k][j]=='A'){
                    dna[j].a++;
                }else if(arr[k][j]=='T'){
                    dna[j].t++;
                }else if(arr[k][j]=='C'){
                    dna[j].c++;
                }else if(arr[k][j]=='G'){
                    dna[j].g++;
                }
            }
            output[j] = mode(dna[j]);
            printf("%c",output[j]);
            for(int k=0; k<unit; k++){
                if(arr[k][j]!=output[j]){
                    diff_num++;
                }
            }
        }
        printf("\n%d\n",diff_num);
        //release memory
        for(int j=0; j<unit; j++){
            free(arr[j]);
        }
        free(arr);
    }
    return 0;
}