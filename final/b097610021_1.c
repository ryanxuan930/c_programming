#include <stdio.h>
#include <stdlib.h>

int main(){
    char input;
    size_t MAX_SIZE = 1000;
    size_t capacity = MAX_SIZE;
    char *array = calloc(MAX_SIZE, sizeof(char));
    size_t i = 0;
    printf("s = ");
    while(scanf("%c",&input)){
        if(input != '\n'){
            if(capacity>0){
                array[i] = input;
                i++;
            }else{
                MAX_SIZE *= 2;
                capacity = MAX_SIZE;
                char *new_array = calloc(MAX_SIZE, sizeof(char));
                for(size_t j=0; j<capacity; j++){
                    new_array[j] = array[j];
                }
                free(array);
                array = new_array;
            }
        }else{
            int status = 1;
            for(size_t j=0; j<capacity; j++){
                if(j==0){
                    if(((array[j]=='(' && array[j+1]==')') || (array[j]=='[' && array[j+1]==']') || (array[j]=='{' && array[j+1]=='}'))){
                        j++;
                    }else{
                        status = 0;
                        break;
                    }
                }else{
                    if(array[j] == '('){
                        if(array[j+1] != ')'){
                            status = 0;
                            break;
                        }else{
                            j++;
                        }
                    }
                    if(array[j] == '['){
                        if(array[j+1] != ']'){
                            status = 0;
                            break;
                        }else{
                            j++;
                        }
                    }
                    if(array[j] == '{'){
                        if(array[j+1] != '}'){
                            status = 0;
                            break;
                        }else{
                            j++;
                        }
                    }
                }
            }
            puts(status==1 ? "true": "false");
            i=0;
            MAX_SIZE = 1000;
            capacity = MAX_SIZE;
            free(array);
            array = calloc(MAX_SIZE, sizeof(char));
            printf("s = ");
        }
    }
    return 0;
}