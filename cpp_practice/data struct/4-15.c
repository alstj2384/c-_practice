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

element here = {1,0}, entry = {1,0};

char maze[MAZE_SIZE][MAZE_SIZE] = {
    { '1', '1', '1', '1', '1', '1' },
    { 'e', '0', '1', '0', '0', '1' },
    { '1', '0', '0', '0', '1', '1' },
    { '1', '0', '1', '0', '1', '1' },
    { '1', '0', '1', '0', '0', 'x' },
    { '1', '1', '1', '1', '1', '1' },
};

void push_loc(StackType *s ,StackType *log, int r, int c){
    if( r < 0 || c < 0) return;
    if(maze[r][c] != '1' && maze[r][c] != '.'){
        element tmp;
        tmp.r = r;
        tmp.c = c;
        push(s, tmp);
        // push(log, tmp);
    }
}

void maze_print(char maze[MAZE_SIZE][MAZE_SIZE]){
    printf("\n");
    for(int r = 0; r < MAZE_SIZE; r++){
        for(int c = 0; c < MAZE_SIZE; c++){
            printf("%c", maze[r][c]);
        }
        printf("\n");
    }
}

int main(){

    int r, c;
    StackType s;
    StackType log; // 이동을 기록하는 스택

    init_stack(&s);
    init_stack(&log); // 이동 기록 스택 초기화
    here = entry;
    while (maze[here.r][here.c] != 'x'){
        r = here.r;
        c = here.c;
        maze[r][c] = '.';

        maze_print(maze);
        push_loc(&s, &log, r, c + 1);
        push_loc(&s, &log, r - 1, c);
        push_loc(&s, &log, r + 1, c);
        push_loc(&s, &log, r, c - 1);
        if (is_empty(&s)){
            printf("실패\n");
            return 0;
            }
        else    
            here = pop(&s);
            push(&log, here); //이동 성공 시 좌표를 log에 저장
        }
        printf("성공\n");


    while(!is_empty(&log)){ // 기록된 log 출력
        element a = pop(&log);
        printf("(%d,%d) ", a.r, a.c);
    }
    return 0;

}