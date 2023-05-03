#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct StackType{
    element* data;
    int top;
    int capacity;
} StackType;

void init(StackType *s){
    s->top = -1;
    s->capacity = 1;

    s->data = (element *)malloc(sizeof(element)*s->capacity);
}

//init 

int is_full(StackType *s){
    return s->top == s->capacity-1
}

int is_empty(StackType *s){
    return s->top == -1;
}

void push(StackType *s, element item){
    if(is_full(s)){
        s->capacity *= 2;
        s->data = (element *)realloc(s->data, sizeof(element) * s->capacity);
    }
    s->data[++s->top] = item; 
}

element pop(StackType *s){
    if(is_empty(s)){
        //error
    }
    return s->data[s->top--];
}

element peek(StackType *s){
    if(is_empty(s)){
        //error
    }
    return s->data[s->top];
}