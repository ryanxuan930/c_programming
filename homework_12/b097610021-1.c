#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

struct node {
    char value;
    struct node *next;
};

typedef struct node Node;

Node *push(Node *stack, char value){
    Node *new_node = malloc(sizeof(Node));
    new_node->value = value;
    new_node->next = stack;
    return new_node;
}

Node *pop(Node *stack){
    Node *temp_node;
    temp_node = stack;
    printf("%c\n",temp_node->value);
    stack = stack->next;
    free(temp_node);
    return stack;
}

int is_empty(Node *stack){
    return stack->next == NULL;
}

int main(){
    // 12.1
    Node *stack;
    char input;
    while(scanf("%c",&input)){
        if(input != '\n'){
            if(input == '0'){
                stack = pop(stack);
            }else{
                stack = push(stack, input);
            }
        }
        
    }
    return 0;
}