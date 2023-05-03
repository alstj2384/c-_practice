//��

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
        error("ť�� ��ȭ�����Դϴ�");
    }
    // front �� --�Ǿ���� �׷��ϱ� ���� �ִ� �ڸ��� �߰��ϰ� --��Ű���
    q->data[q->front] = item;
    q->front = ((q->front -1) + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}

void add_rear(QueueType *q, element item){
    if(is_full(q)){
        error("ť�� ��ȭ�����Դϴ�");
    }
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = item;
}

element delete_front(QueueType *q){
    if(is_empty(q)){
        error;
    }
    //front�� ������Ű��, �� �ڸ��� �ִ� ���� ��ȯ�ϴ°��̳�
    q->front = (q->front +1 )  % MAX_QUEUE_SIZE;
    return q->data[q->front];
}

element delete_rear(QueueType *q){
    int prev = q->rear;
    if(is_empty(q)){
        error;
    }
    //front�� ������Ű��, �� �ڸ��� �ִ� ���� ��ȯ�ϴ°��̳�
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
// �⺻ ����� �������ִ�(�����Ҵ� ���翡���� �����ʴ´�.) �������� ����� �� �־ (ũ�⿡�°�)
// ����ť�� ����ť ����ť���� Ȯ��� ��(double ended queue)
// ����ť�� adt
/*
����ť
create
init
in_empty
is_full
enqueue
dequeue
peek

����ť
craete
init
is_empty
is_full
enqueue
dequeue
peek
����ť�ʹ� ������Ŀ� ���̰� ���� ���۹���̳�

��
����ť�� ����, 
add_front, add_rear
get_front  get_reawr
delete front, delete rear

����ť�� ��� �ִ� ������ n-1���̴�
�׸��� ����ť�� front�� ����Ű�� �ִ� �κ��� ������.

*/