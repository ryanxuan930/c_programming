#include <stdio.h>
#include <stdlib.h>

typedef struct stu{
    int id;
    int chn;
    int eng;
    int mat;
    double ave;
} Object;

Object *ave(Object *obj){
    obj->ave = (obj->chn+obj->eng+obj->mat)/3;
    return obj;
}

int main() {
    int n = 0;
    printf("Input n:");
    scanf("%d", &n);
    Object *arr = calloc(n, sizeof(Object));
    for(int i=0; i<n; i++){
        printf("Student ID: ");
        scanf("%d", &arr[i].id);
        printf("Chinese: ");
        scanf("%d", &arr[i].chn);
        printf("English: ");
        scanf("%d", &arr[i].eng);
        printf("Math: ");
        scanf("%d", &arr[i].mat);
    }
    for(int i=0; i<n; i++){
        printf("Student ID: %d\n", arr[i].id);
        printf("Average: %.2f\n",ave(&arr[i])->ave);
    }
    return 0;
}