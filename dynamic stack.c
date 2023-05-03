/*
stack adt
create
init
is_empty()
is_full(0-)
push
pop
peek

1. 정적 스택(사이즈 고정)
2. 동적 스택(사이즈 그때그때 늘어남)
*/
// 전역으로 만든다는 거는 그냥 스택 배열 자체가 전역변수로 선언되어있는거임

#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct StackType{
    element* data;
    int capacity;
    int top;
}StackType;

void error(char * message){
    fprintf(stderr, "%s\n", message);
}
void init(StackType *s){
    s->top == -1;
    s->capacity == 1;

    s->data = (element *)malloc(sizeof(element) * s->capacity);
}

int is_empty(StackType *s){
    return s->top == -1;
}

int is_full(StackType *s){
    return s->top == s->capacity-1;
}

void push(StackType *s, element item){
    if(is_full(s)){
        s->capacity *= 2;
        s->data = (element *)realloc(s->data, sizeof(element)*s->capacity);
    }
    s->data[++(s->top)] = item;
}

element pop(StackType *s){
    if(is_empty(s)){
        error;
    }
    return s->data[(s->top)--];
}

element peek(StackType *s){
    if(is_empty(s)){
        error;
    }
    return s->data[s->top];
}

int main(){

    return 0;
}