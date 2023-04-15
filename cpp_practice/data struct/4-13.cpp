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
    printf("������ �Է��Ͻÿ�: ");
    scanf("%s", a);

    push(a[strlen(a)-1]);
    for(int i = strlen(a)-2; i >= 0; i--){
        if(peek()!=a[i]) push(a[i]);
        
    }

    printf("���: ");
    while(!is_empty()) printf("%c", pop());
    return 0;
}