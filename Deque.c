#include <stdio.h>
#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct QueueType{
    element data[MAX_QUEUE_SIZE];
    int rear, front;
} QueueType;

// 인큐 디큐는 똑같음. 더해야할 건 
// add front add rear
// get front get rear
// delete front delete rear


void error(char *message){
    fprintf(stderr, "%s\n", message);
}
void init_Queue(QueueType *q){
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
    q->rear = (q->rear+1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = item;
}

void add_front(QueueType *q, element item){
    if(is_full(q)){
        error("스택이 꽉 찼습니다");
    }
    // front에 뭘 추가하는 거니까 (front-1) % max.. 
    // 원래 자리는 비어있으니 거기에추가하고 --하면 되는거같은데..
    // 근데 어차피 front 뒤의 요소는 항상 비어있음.
    // 그리고 front자리에 뭐가 있든 어차피 참조를 하지않음
    q->data[q->front] = item;
    q->front = (q->front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}

element delete_front(QueueType *q){
    if(is_empty(q)){
        error("스택이 공백입니다");
    }
    q->front = (q->front+1) % MAX_QUEUE_SIZE;
    return q->data[q->front];
}

element delete_rear(QueueType *q){
    int prev = q->rear;
    if(is_empty(q)){
        error("스택이 공백입니다");
    }
    q->rear = (q->rear-1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
    return q->data[prev];
}


element get_rear(QueueType *q){
    if(is_empty(q)){
        error("스택이 공백입니다");
    }
    return q->data[q->rear];
}

element get_front(QueueType *q){
    if(is_empty(q)){
        error("스택이 공백입니다");
    }
    return q->data[(q->front+1) % MAX_QUEUE_SIZE];
}

void deque_print(QueueType *q){
    printf("DEQUE(front=%d rear=%d) = ", q->front, q->rear);
    if(!is_empty(q)){
        int i = q->front;
        do{
            i = (i + 1) % (MAX_QUEUE_SIZE);
            printf("%d | ", q->data[i]);
            if(i == q->rear)
                break;
        }while( i != q->front);
    }printf("\n");
}
int main(){
    QueueType q;

    init_Queue(&q);
    add_rear(&q, 1);
    add_rear(&q, 2);
    add_rear(&q, 3);
    add_rear(&q, 4);
    deque_print(&q);
    delete_rear(&q);
    deque_print(&q);
    
    delete_front(&q);
    deque_print(&q);
    add_rear(&q, 2);
    add_rear(&q, 3);
    deque_print(&q);
    delete_front(&q);
    deque_print(&q);
    delete_front(&q);
    deque_print(&q);
    add_rear(&q, 2);
    deque_print(&q);
    add_rear(&q, 3);
    deque_print(&q);
    return 0;
}