#include <stdio.h>
#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct QueueType{
    element data[MAX_QUEUE_SIZE];
    int rear, front;
} QueueType;

// 공백확인, 꽉참확인, 푸시, 팝, 이닛, 프린트?는 필요없을 거 같고

void error(char *message){
    fprintf(stderr, "%s\n", message);
    exit(1);
}
void init_Queue(QueueType *q){
    q->rear = q->front = 0;
}

int is_empty(QueueType *q){
    return (q->rear == q->front);
}

int is_full(QueueType *q){
    return ((q->rear+1) % MAX_QUEUE_SIZE == q->front %  MAX_QUEUE_SIZE);
}

void enqueue(QueueType *q, element item){
    if(is_full(q)){
        error("스택이 꽉 찼습니다");
    }
    q->rear = (q->rear+1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = item;
}

element dequeue(QueueType *q){
    if(is_empty(q)){
        error("스택이 공백입니다");
    }
    q->front = (q->front+1) % MAX_QUEUE_SIZE;
    return q->data[q->front];
}

element peek(QueueType *q){
    if(is_empty(q)){
        error("스택이 공백입니다");
    }
    return q->data[q->rear];
}

int main(){
    return 0;
}