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
maze 배열이 전역변수에서 main함수로 이동되었으므로 매개변수로 maze 배열을 받습니다

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
마찬가지로 maze 배열의 크기가 한정되어있지 않으므로 크기와 maze배열을 입력받습니다
*/

int main(){

    int r, c;
    StackType s;
    StackType log; // 이동을 기록하는 스택
    StackType buffer; // log 스택 출력을 역순으로 하기 위한 임시 버퍼 스택

    int size; // 배열의 크기 [정사각형]
    char **maze; // 2차원 동적 할당을 위한 포인터 변수 maze

    printf("배열 크기 입력 (n) : ");
    scanf("%d", &size); // 배열 크기 입력 받기

    //2차원 배열 생성하기
    maze = (char **) malloc ( sizeof(char*) * size);
    for(int i = 0; i < size; i++)
        maze[i] = (char *) malloc (sizeof(char) * size);

    getchar(); // 버퍼 비우기

    // 배열 입력받기
    printf("배열 입력 : ");
    for(int i = 0 ; i < size; i++){
        for(int j = 0; j < size; j++){
            scanf(" %c", &maze[i][j]);
        }
        getchar();
    }


    element entry, here, goal;
    // 도착지, 출발지 입력받기
    printf("출발지 좌표 입력(x, y) : ");
    scanf("%hd%hd" ,&entry.c, &entry.r);
    maze[entry.r][entry.c] = 'e';
    
    getchar(); // 버퍼 비우기

    printf("도착지 좌표 입력(x, y) : ");
    scanf("%hd%hd", &goal.c, &goal.r);
    maze[goal.r][goal.c] = 'x';

    maze_print(size, maze); // maze 출력

    init_stack(&s);
    init_stack(&log); // 이동 기록 스택 초기화
    init_stack(&buffer); // 버퍼 스택 초기화

    here = entry;
    while (maze[here.r][here.c] != 'x'){
        r = here.r;
        c = here.c;
        maze[r][c] = '.';

        maze_print(size, maze);
        push_loc(&s, maze, r, c + 1); // 함수 수정에 따라 maze를 인자로 추가
        push_loc(&s, maze,  r - 1, c);// 함수 수정에 따라 maze를 인자로 추가
        push_loc(&s, maze,  r + 1, c);// 함수 수정에 따라 maze를 인자로 추가
        push_loc(&s, maze,  r, c - 1);// 함수 수정에 따라 maze를 인자로 추가
        if (is_empty(&s)){
            printf("실패\n");
            return 0;
            }
        else    
            here = pop(&s);
            push(&log, here); //이동 성공 시 좌표를 log에 저장
        }
        printf("성공\n");


    while(!is_empty(&log)) // 기록된 log 임시 저장
        push(&buffer, pop(&log));

    while(!is_empty(&buffer)){ // 기록된 log 출력
        element a = pop(&buffer);
        printf("(%d,%d) ", a.r, a.c);
    }

    printf("\n");

    if(maze){ // maze배열이 nullptr이 아니면 
        for(int i = 0; i < size; i++){
            free(maze[i]); // 배열 free
        }
        free(maze);
        printf("20203239 송민서, 배열 해제 완료\n");
    }
    return 0;

}