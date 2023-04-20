#include <stdio.h>
#define MAX_QUEUE_DATA 5

typedef int element;
typedef struct QueueType{
    int data[MAX_QUEUE_DATA];
    int rear, front;
} QueueType;

// ����ť������� �װɿ����Է� �ٲ㺸�� 
// add, delete, show, is_empty, is_full, init

void init(QueueType *q){
    q->rear = q->front = 0;
}
int is_empty(QueueType *q){
    return (q->front == q->rear);

}

int is_full(QueueType *q){
    return (MAX_QUEUE_DATA == q->rear);
}

void show(QueueType *q){
    for(int i = q->front; i < q->rear; i++)
        printf("%d |", q->data[i]);
    putchar('\n');
}

void addQueue(QueueType *q, element item){
    if(is_full(q)){
        printf("ť�� ��ȭ�����Դϴ�\n");
        return;
    }
    q->data[q->rear++] = item;
}

void delQueue(QueueType *q){
    if(is_empty(q)){
        printf("ť�� �����Դϴ�\n");
        return;
    }
    q->front++;
}

element getFront(QueueType *q){
    return q->data[q->front];
}
element getRear(QueueType *q){
    return q->data[q->rear-1];
}
int main(){
    int element;
    QueueType q;
    init(&q);

    addQueue(&q, 1);
    addQueue(&q, 2);
    addQueue(&q, 3);
    addQueue(&q, 4);

    addQueue(&q, 5);
    addQueue(&q, 5);
    show(&q);
    delQueue(&q);
    printf("���� ť�� ù ��° �׸�: %d\n", getFront(&q));
    show(&q);
    delQueue(&q);
    show(&q);
    delQueue(&q);
    show(&q);
    delQueue(&q);
    show(&q);
    delQueue(&q);
    printf("���� ť�� ������ �׸�: %d\n", getRear(&q));
    show(&q);
    delQueue(&q);



}