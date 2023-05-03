#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode{
    int coef;
	int expon;
    struct ListNode* link;
}ListNode;

typedef struct ListType{
	int size;
	ListNode *head;
	ListNode *tail;
} ListType;

void error(char *message){
    fprintf(stderr, "%s\n", message);
    exit(1);
}

ListType* create(){
	ListType* plist = (ListType*)malloc(sizeof(ListType));
	plist->size = 0;
	plist->head = plist->tail = NULL;
	return plist;
}

void insert_last(ListType* plist, int coef, int expon){
	ListNode*temp = (ListNode *)malloc(sizeof(ListNode));
	if(temp == NULL) error("메모리 할당 에러");
	temp->coef = coef;
	temp->expon = expon;
	temp->link = NULL;
	if(plist->tail == NULL){
		plist->head = plist->tail = temp;
	}
	else{
		plist->tail->link = temp;
		plist->tail = temp;
	}
	plist->size++;
}

int poly_eval(ListType* plist, int x) {
	int sum = 0;
	ListNode* a = plist->head;
	while (a) {
		int temp = 1;
		for (int i = 0; i < a->expon; i++)
			temp *= x;
		sum += temp * a->coef;
		a = a->link;
	}
	return sum;
}

int main(){

	ListType * list;
	list = create();

	insert_last(list, 1, 3);
	insert_last(list, 2, 1);
	insert_last(list, 6, 0);
	int x = 2;
	printf("%d\n", poly_eval(list, x));


	return 0;
}