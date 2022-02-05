#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> 

typedef struct cup{
    int capacity;
    char cup_name[100];
} Cup;

Cup *setName(Cup *obj,char *name){
    size_t len = strlen(name);
    for(size_t i = 0; i < len; i++){
        obj->cup_name[i] = name[i];
    }
    return obj;
}

Cup *setCapacity(Cup *obj,int capacity){
    obj->capacity = capacity;
    return obj;
}

Cup *pour(Cup*obj){
    int volume;
    if(obj->capacity>=10){
        volume = rand()%(10-1+1)+10;
    }else if(obj->capacity>0){
        volume = rand()%(obj->capacity-1+1)+obj->capacity;
    }else{
        setCapacity(obj, 0);
        volume = 0;
        puts("No water");
    }
    setCapacity(obj, obj->capacity-volume);
    return obj;
}

Cup *new(Cup *obj, char *name){
    setCapacity(setName(obj, name),rand()%(50-30+1)+30);
    return obj;
}

int main() {
    srand(time(NULL));
    Cup *instance = malloc(sizeof(Cup));
    int option=0;
    while(1){
        puts("1. Initialization");
        puts("2. Pour the water");
        puts("3. Rename");
        printf("Options:");
        scanf("%d", &option);
        if(option==1){
            instance = malloc(sizeof(Cup));
            char name[100];
            printf("Input the cup name: ");
            scanf("%s", name);
            printf("Cup name: %s\n", new(instance, name)->cup_name);
            printf("Capacity: %d ml\n",instance->capacity);
        }else if(option==2){
            pour(instance);
            printf("Cup name: %s\n", instance->cup_name);
            printf("Capacity: %i\n", instance->capacity);
        }else{
            char name[100];
            printf("Input the cup name: ");
            scanf("%s", name);
            printf("Cup name: %s\n", setName(instance, name)->cup_name);
            printf("Capacity: %d ml\n",instance->capacity);
        }
    }
    return 0;
}