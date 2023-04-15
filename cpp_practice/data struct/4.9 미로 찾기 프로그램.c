#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100
#define MAZE_SIZE 6

typedef struct{
    short r;
    short c;
}element;

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
        fprintf(stderr, "���� ��ȭ ����\n");
        return;
    }
    else s->data[++(s->top)] = item;
}

element pop(StackType *s){
    if(is_empty(s)){
        fprintf(stderr, "���� ���� ����\n");
        exit(1);
    }
    else return s->data[(s->top)--];
}

element peek(StackType *s){
    if(is_empty(s)){
        fprintf(stderr, "���� ���� ����\n");
        exit(1);
    }
    else return s->data[s->top];
}


void push_loc(StackType *s, char **maze , int r, int c){ 
    if( r < 0 || c < 0) return;
    if(maze[r][c] != '1' && maze[r][c] != '.'){
        element tmp;
        tmp.r = r;
        tmp.c = c;
        push(s, tmp);
    }
}

/*
maze �迭�� ������������ main�Լ��� �̵��Ǿ����Ƿ� �Ű������� maze �迭�� �޽��ϴ�

*/

void maze_print(int size, char **maze){
    printf("\n");
    for(int r = 0; r < size; r++){
        for(int c = 0; c < size; c++){
            printf("%c", maze[r][c]);
        }
        printf("\n");
    }
}

/*
���������� maze �迭�� ũ�Ⱑ �����Ǿ����� �����Ƿ� ũ��� maze�迭�� �Է¹޽��ϴ�
*/

int main(){

    int r, c;
    StackType s;
    StackType log; // �̵��� ����ϴ� ����
    StackType buffer; // log ���� ����� �������� �ϱ� ���� �ӽ� ���� ����

    int size; // �迭�� ũ�� [���簢��]
    char **maze; // 2���� ���� �Ҵ��� ���� ������ ���� maze

    printf("�迭 ũ�� �Է� (n) : ");
    scanf("%d", &size); // �迭 ũ�� �Է� �ޱ�

    //2���� �迭 �����ϱ�
    maze = (char **) malloc ( sizeof(char*) * size);
    for(int i = 0; i < size; i++)
        maze[i] = (char *) malloc (sizeof(char) * size);

    getchar(); // ���� ����

    // �迭 �Է¹ޱ�
    printf("�迭 �Է� : ");
    for(int i = 0 ; i < size; i++){
        for(int j = 0; j < size; j++){
            scanf(" %c", &maze[i][j]);
        }
        getchar();
    }


    element entry, here, goal;
    // ������, ����� �Է¹ޱ�
    printf("����� ��ǥ �Է�(x, y) : ");
    scanf("%hd%hd" ,&entry.c, &entry.r);
    maze[entry.r][entry.c] = 'e';
    
    getchar(); // ���� ����

    printf("������ ��ǥ �Է�(x, y) : ");
    scanf("%hd%hd", &goal.c, &goal.r);
    maze[goal.r][goal.c] = 'x';

    maze_print(size, maze); // maze ���

    init_stack(&s);
    init_stack(&log); // �̵� ��� ���� �ʱ�ȭ
    init_stack(&buffer); // ���� ���� �ʱ�ȭ

    here = entry;
    while (maze[here.r][here.c] != 'x'){
        r = here.r;
        c = here.c;
        maze[r][c] = '.';

        maze_print(size, maze);
        push_loc(&s, maze, r, c + 1); // �Լ� ������ ���� maze�� ���ڷ� �߰�
        push_loc(&s, maze,  r - 1, c);// �Լ� ������ ���� maze�� ���ڷ� �߰�
        push_loc(&s, maze,  r + 1, c);// �Լ� ������ ���� maze�� ���ڷ� �߰�
        push_loc(&s, maze,  r, c - 1);// �Լ� ������ ���� maze�� ���ڷ� �߰�
        if (is_empty(&s)){
            printf("����\n");
            return 0;
            }
        else    
            here = pop(&s);
            push(&log, here); //�̵� ���� �� ��ǥ�� log�� ����
        }
        printf("����\n");


    while(!is_empty(&log)) // ��ϵ� log �ӽ� ����
        push(&buffer, pop(&log));

    while(!is_empty(&buffer)){ // ��ϵ� log ���
        element a = pop(&buffer);
        printf("(%d,%d) ", a.r, a.c);
    }

    printf("\n");

    if(maze){ // maze�迭�� nullptr�� �ƴϸ� 
        for(int i = 0; i < size; i++){
            free(maze[i]); // �迭 free
        }
        free(maze);
        printf("20203239 �۹μ�, �迭 ���� �Ϸ�\n");
    }
    return 0;

}