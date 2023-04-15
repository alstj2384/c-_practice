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
        fprintf(stderr, "���� ��ȭ ����\n");
        return;
    }
    else stack[++top] = item;
}
element pop(){
    if(is_empty()){
        fprintf(stderr, "���� ���� ����\n");
        exit(1);
    }
    else return stack[top--];
}
element peek(){
    if(is_empty()){
        fprintf(stderr, "���� ���� ����\n");
        exit(1);
    }
    else return stack[top];
}

int main(){
    char a[100];
    printf("��ȣ �Է� : ");
    scanf("%s", a);
    int cnt = 0;
    int high = 0;
    printf("��ȣ �� : ");
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