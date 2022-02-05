#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct node {
    int value;
    struct node *prev;
    struct node *next;
} Node;

typedef struct queue {
    Node *head;
    Node *tail;
} Queue;

static Node *create_node(int value){
    Node *node = malloc(sizeof(Node));
    node->value = value;
    node->prev = NULL;
    node->next = NULL; 
    return node;
}

void push(Queue *this, int value){
    Node *new_node = create_node(value);
    if(!(this->head)){
        this->head = new_node;
        this->tail = new_node;
        return;
    }
    this->tail->next = new_node;
    new_node->prev = this->tail;
    this->tail = new_node;
}

void pop(Queue *this){
    Node *temp_node;
    temp_node = this->head;
    printf("%i\n",temp_node->value);
    this->head = temp_node->next;
    free(temp_node);
}

int is_empty(Queue *this){
    return this->head == NULL;
}

int main(){
    // 13.1
    Queue *q = malloc(sizeof(Queue));
    int input;
    q->head = NULL;
    q->tail = NULL;
    while(scanf("%i",&input)){
        if(input != '\n'){
            if(input == 0){
                pop(q);
            }else{
                push(q, input);
            }
        }
        
    }
    return 0;
}