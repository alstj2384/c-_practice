#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100

typedef int element;
typedef struct {
    element data[MAX_STACK_SIZE];
    int top;
} StackType;

void init_stack(StackType *s){
    s->top = -1;
}

int is_empty(StackType *s){
    return (s->top == -1);
}

int is_full(StackType *s) {
    return (s->top == (MAX_STACK_SIZE - 1));
}

void push(StackType *s, element item){
    if(is_full(s)){
        fprintf(stderr, "스택 포화 에러\n");
        return;
    }
    else s->data[++(s->top)] = item;
}

element pop(StackType *s){
    if(is_empty(s)){
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    else return s->data[(s->top)--];
}

element peek(StackType *s){
    if(is_empty(s)){
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    else return s->data[s->top];
}

typedef struct {
    StackType s1, s2;
} QueueType;

void Queue_init(QueueType *q){
    init_stack(&q->s1);
    init_stack(&q->s2);
}

void Queue_push(QueueType *q, int item){
    push(&(q->s1), item);
    return;
}

int Queue_pop(QueueType *q){
    if(is_empty(&(q->s2))){
        while(!is_empty(&(q->s1))){
            push(&(q->s2), pop(&(q->s1))); 
        }
    }
    return pop(&(q->s2));
}
int main(){
	QueueType q;
	Queue_init(&q);
	Queue_push(&q, 5);
	Queue_push(&q, 4);
	Queue_push(&q, 3);
	printf("%d\n", Queue_pop(&q));
	printf("%d\n", Queue_pop(&q));
	printf("%d\n", Queue_pop(&q));

    return 0;

}