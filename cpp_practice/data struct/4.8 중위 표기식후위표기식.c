#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STACK_SIZE 100

typedef char element;

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

int prec(char op){
    switch (op)
    {
    case '(': case ')': return 0;
    case '+': case '-': return 1;
    case '*': case '/': return 2;
    }
    return -1;
}

StackType infix_to_postfix(char exp[]){ // �Լ��� ���� Ÿ���� StackType���� ����
    int i = 0;
    char ch, top_op,c;
    int len = strlen(exp);
    StackType s;
    StackType buf; // ���� ������ �ӽ� buf ����

    init_stack(&buf);
    init_stack(&s);
    for(int i = 0; i < len; i++){
        ch = exp[i];
        switch(ch){
        case '+': case '-': case '*': case '/':
            while(!is_empty(&s) && (prec(ch) <= prec(peek(&s)))){
                c = pop(&s);
                push(&buf, c); // ��� �� �Բ� ����
                printf("%c", c);
            }
            push(&s, ch);
            break;
        case '(':
            push(&s, ch);
            break;
        case ')':
            top_op = pop(&s);
            while(top_op != '('){
                printf("%c", top_op);
                push(&buf, top_op); // ��� �� �Բ� ����
                top_op = pop(&s);
            }
            break;
        default:
            printf("%c", ch);
            push(&buf, ch); // ��� �� �Բ� ����
            break;
        }
    }
    while (!is_empty(&s)) {
        c = pop(&s);
        push(&buf, c);
        printf("%c", c);
    }
    return buf;
}

int eval_postfix(char exp[]){
    StackType s;
    init_stack(&s);
    while (*exp) {
        if (isdigit(*exp)) {
            push(&s, *exp - '0');
        } else {
            int op2 = pop(&s);
            int op1 = pop(&s);
            switch (*exp) {
                case '+':
                    push(&s, op1 + op2);
                    break;
                case '-':
                    push(&s, op1 - op2);
                    break;
                case '*':
                    push(&s, op1 * op2);
                    break;
                case '/':
                    push(&s, op1 / op2);
                    break;
            }
        }
        ++exp;
    }
    return pop(&s);
}
int main(){

    char *s = "(2+3)*4+9-4";
    char a[100];
    char c;
    StackType stack;
    StackType buf;
    init_stack(&stack);
    init_stack(&buf);

    printf("����ǥ�ü��� %s \n", s);
    printf("����ǥ�ü��� ");
    stack = infix_to_postfix(s);
    int i = 0;

    printf("\n");

    while(!is_empty(&stack)) push(&buf, pop(&stack));

    while(!is_empty(&buf)){
        c = pop(&buf);
        a[i++] = c;
    }
    a[strlen(a)] = '\0';

    printf("����ǥ�ü��� ��� ��� : %d\n", eval_postfix(a));
    printf("20203239 �۹μ�\n");
    
    return 0;

}