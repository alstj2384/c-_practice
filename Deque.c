#include <stdio.h>
#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct QueueType{
    element data[MAX_QUEUE_SIZE];
    int rear, front;
} QueueType;

// ��ť ��ť�� �Ȱ���. ���ؾ��� �� 
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
        error("������ �� á���ϴ�");
    }
    q->rear = (q->rear+1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = item;
}

void add_front(QueueType *q, element item){
    if(is_full(q)){
        error("������ �� á���ϴ�");
    }
    // front�� �� �߰��ϴ� �Ŵϱ� (front-1) % max.. 
    // ���� �ڸ��� ��������� �ű⿡�߰��ϰ� --�ϸ� �Ǵ°Ű�����..
    // �ٵ� ������ front ���� ��Ҵ� �׻� �������.
    // �׸��� front�ڸ��� ���� �ֵ� ������ ������ ��������
    q->data[q->front] = item;
    q->front = (q->front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}

element delete_front(QueueType *q){
    if(is_empty(q)){
        error("������ �����Դϴ�");
    }
    q->front = (q->front+1) % MAX_QUEUE_SIZE;
    return q->data[q->front];
}

element delete_rear(QueueType *q){
    int prev = q->rear;
    if(is_empty(q)){
        error("������ �����Դϴ�");
    }
    q->rear = (q->rear-1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
    return q->data[prev];
}


element get_rear(QueueType *q){
    if(is_empty(q)){
        error("������ �����Դϴ�");
    }
    return q->data[q->rear];
}

element get_front(QueueType *q){
    if(is_empty(q)){
        error("������ �����Դϴ�");
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