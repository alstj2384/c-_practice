#include <stdio.h>
#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct QueueType{
    element data[MAX_QUEUE_SIZE];
    int rear, front;
} QueueType;

// 이걸 덱으로 바꿔보자
// add front add rear
// get front get rear
// delete front delete rear;

void error(char * message){
    fprintf(stderr, "%s\n", message);
}
void init_queue(QueueType *q){
    q->rear = q->front = 0;
}

int is_empty(QueueType *q){
    return (q->rear == q->front);
}

int is_full(QueueType *q){
    return ((q->rear+1) % MAX_QUEUE_SIZE == q->front);
}

void add_rear(QueueType *q, element item){
    if(is_full(q)){
        error("스택이 꽉 찼습니다");
    }
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = item;
}

void add_front(QueueType *q, element item){
//front를 --시켜야함
    if(is_full(q)){
        error("스택이 꽉 찼습니다");
    }
    q->data[q->front] = item;
    q->front = (q->front-1+MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}

element delete_front(QueueType *q){
    if(is_empty(q)){
        error("스택이 공백입니다");
    }
    q->front = (q->front+1) % MAX_QUEUE_SIZE;
    return q->data[q->front];
}

element delete_rear(QueueType *q){
    if(is_empty(q))
        error("스택이 공백입니다");
    //rear --
    int val;
    val = q->rear;
    q->rear = (q->rear-1+MAX_QUEUE_SIZE)%MAX_QUEUE_SIZE;
    return q->data[val];
}


element get_front(QueueType *q){
    return q->data[(q->front+1) % MAX_QUEUE_SIZE];
}

element get_rear(QueueType *q){
    return q->data[q->rear];
}

int main(){
    return 0;
}