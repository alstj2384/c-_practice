//덱

#include <stdio.h>
#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct QueueType{
    element data[MAX_QUEUE_SIZE];
    int rear, front;
} QueueType;
//add_front add raer 
void error(char * message){
    fprintf(stderr, "%s\n", message);
}

void init(QueueType *q){
    q->rear = q->front = 0;
}

int is_empty(QueueType *q){
    return q->rear == q->front;
}

int is_full(QueueType *q){
    return q->rear +1 % MAX_QUEUE_SIZE == q->front;
}

void add_front(QueueType *q, element item){
    if(is_full(q)){
        error("큐가 포화상태입니다");
    }
    // front 가 --되어야함 그러니까 원래 있던 자리에 추가하고 --시키면됨
    q->data[q->front] = item;
    q->front = ((q->front -1) + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}

void add_rear(QueueType *q, element item){
    if(is_full(q)){
        error("큐가 포화상태입니다");
    }
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = item;
}

element delete_front(QueueType *q){
    if(is_empty(q)){
        error;
    }
    //front를 증가시키고, 그 자리에 있는 값을 반환하는거이낚
    q->front = (q->front +1 )  % MAX_QUEUE_SIZE;
    return q->data[q->front];
}

element delete_rear(QueueType *q){
    int prev = q->rear;
    if(is_empty(q)){
        error;
    }
    //front를 증가시키고, 그 자리에 있는 값을 반환하는거이낚
    q->rear = (q->rear -1 +MAX_QUEUE_SIZE)  % MAX_QUEUE_SIZE;
    return q->data[prev];
}

element get_front(QueueType *q){
    if(is_empty(q)){
        error;
    }
    return q->data[(q->front+1)%MAX_QUEUE_SIZE];
}

element get_rear(QueueType *q){
    if(is_empty(q)){
        error;
    }
    return q->data[(q->rear)];
}


int main(){
    return 0;
}
// 기본 사이즈가 정해져있다(동적할당 교재에서는 하지않는다.) 무한으로 사용할 순 있어도 (크기에맞게)
// 선형큐와 원형큐 원형큐에서 확장된 덱(double ended queue)
// 선형큐의 adt
/*
선형큐
create
init
in_empty
is_full
enqueue
dequeue
peek

원형큐
craete
init
is_empty
is_full
enqueue
dequeue
peek
선형큐와는 구현방식에 차이가 있음 동작방식이나

덱
원형큐와 같고, 
add_front, add_rear
get_front  get_reawr
delete front, delete rear

원형큐의 요소 최대 개수는 n-1개이다
그리고 원형큐의 front가 가르키고 있는 부분은 공백임.

*/