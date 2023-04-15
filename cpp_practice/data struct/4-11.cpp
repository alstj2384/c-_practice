#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100
typedef int element;
element stack[MAX_STACK_SIZE];
int top = -1;

int is_empty(){
    return (top == -1);
}
int is_full(){
    return (top == (MAX_STACK_SIZE - 1));
}
void push(element item){
    if(is_full()){
        fprintf(stderr, "스택 포화 에러\n");
        return;
    }
    else stack[++top] = item;
}
element pop(){
    if(is_empty()){
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    else return stack[top--];
}
element peek(){
    if(is_empty()){
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    else return stack[top];
}

int main(){
    char a[100];
    printf("괄호 입력 : ");
    scanf("%s", a);
    int cnt = 0;
    int high = 0;
    printf("괄호 수 : ");
    for(int i = 0; i < strlen(a); i++){
        if(a[i] == '('){
            push(++cnt);
            printf("%d ", peek());
        }
        else if(a[i]== ')'){
            int a = pop();
            printf("%d ", a);
        }
    }
    return 0;
}