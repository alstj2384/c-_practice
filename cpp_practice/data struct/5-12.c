#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_QUEUE_SIZE 100
typedef int element;
typedef struct
{
    element data[MAX_QUEUE_SIZE];
    int front, rear;
} DequeType;

void error(char *massage){
    fprintf(stderr, "%s\n", massage);
    exit(1);
}

void init_queue(DequeType *q){
    q->front = q->rear = 0;
}

int is_empty(DequeType *q){
    return (q->front == q->rear);
}

int is_full(DequeType *q){
    return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

void queue_print(DequeType *q){
    printf("DEQUE(front=%d rear=%d) = ", q->front, q->rear);
    if(!is_empty(q)){
        int i = q->front;
        do{
            i = (i + 1) % (MAX_QUEUE_SIZE);
            printf("%d | ", q->data[i]);
            if(i == q->rear) break;
        } while (i != q->front);
    }
    printf("\n");
}

void add_rear(DequeType *q, element item){
    if(is_full(q)) error("ť�� ��ȭ�����Դϴ�");
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = item;
}

element delete_front(DequeType *q){
    if(is_empty(q)) error("ť�� ��������Դϴ�");
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->data[q->front];
}

element get_front(DequeType *q){
    if(is_empty(q)) error("ť�� ��������Դϴ�");
    return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}

void add_front(DequeType *q, element val){
    if(is_full(q)) error("ť�� ��ȭ�����Դϴ�");
    q->data[q->front] = val;
    q->front = (q->front -1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;

}

element delete_rear(DequeType *q){
    int prev = q->rear;
    if(is_empty(q)) error("ť�� ��������Դϴ�");
    q->rear = (q->rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
    return q->data[prev];
}

element get_rear(DequeType *q){
    if(is_empty(q)) error("ť�� ��������Դϴ�");
    return q->data[q->rear];
}

int main(){
    DequeType d1, d2;
    int a, b, i = 1;
    init_queue(&d1);
    init_queue(&d2);


    while(true){
        printf("�۾��� ������ �� ���� [1 , 2] : ");
        scanf("%d", &b);
        printf("������ �۾��� ���� [1. PUSH] [2. POP] :");
        scanf("%d", &a);
        printf("\n");
        

        if(b == 1){
            if(a == 1){
                add_front(&d1, i++);
            }
            else if (a == 2){
                delete_front(&d1);
                if(is_empty(&d1) && !is_empty(&d2)){
                    printf("Deque[2]���� %d�� Deque[1]�� ������\n", get_rear(&d2));
                    add_front(&d1, get_rear(&d2));
                    delete_rear(&d2);
                }
            }
        }
        else if(b == 2){
            if(a == 1){
                add_front(&d2, i++);
            }
            else if (a == 2){
                delete_front(&d2);
                if(is_empty(&d2) && !is_empty(&d1)){
                    printf("Deque[1]���� %d�� Deque[2]�� ������\n", get_rear(&d1));
                    add_front(&d2, get_rear(&d1));
                    delete_rear(&d1);
                }
            }
        }

        queue_print(&d1);
        queue_print(&d2);
        printf("\n");
    }
    return 0;

}

