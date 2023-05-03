#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int row;
    int col;
    int value;
} element;
typedef struct ListNode{
    element data;
    struct ListNode* link;
}ListNode;

void error(char *message){
    fprintf(stderr, "%s\n", message);
    exit(1);
}


ListNode* insert_first(ListNode* head, element item){
    ListNode* p = (ListNode *)malloc(sizeof(ListNode));
    p->data->row = item.row;
    p->data.col = item.col;
    p->data.value = item.value;
    p->link = head;
    head = p;
    return head;
}

ListNode* insert(ListNode* head, ListNode* pre, element item){
    ListNode* p = (ListNode *)malloc(sizeof(ListNode));
    p->data.row = item.row;
    p->data.col = item.col;
    p->data.value = item.value;
    p->link = pre->link;
    pre->link = p;
    return head;
}

ListNode*  insert_last(ListNode *head, element value){
	ListNode *tmp = (ListNode *)malloc(sizeof(ListNode));
	tmp->data = value;
	tmp->link = NULL;
	if (head == NULL) {
		head = tmp;
		return head;
	}
	else {
		ListNode *p;
		for (p = head; p->link != NULL; p = p->link) ;
		p->link = tmp;
		return head;	
	}
}
ListNode* delete_first(ListNode* head){
    ListNode* remove;
    if(head == NULL) return NULL;
    remove = head;
    head = remove->link;
    free(remove);
    return head;
}

ListNode* delete(ListNode* head, ListNode* pre){
    ListNode* remove;
    remove = pre->link;
    pre->link = remove->link;
    free(remove);
    return head;
}

void print_list(ListNode *head, element item[], int n, int m){
    ListNode * p;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            for(p = head; p != NULL; p = p->link){
                if(p->data.row == item[i].row && p->data.col == item[i].col)  
                    printf(" %d", item->value);
                else printf(" 0");
            }

        }printf("\n");
    }
}

void print_list1(ListNode * head){
    for(ListNode *p = head; p != NULL; p = p->link){
        printf("%d, %d, %d\n", p->data.row, p->data.col, p->data.value);
    }
}

int main(){

    ListNode *head;
    int count, a, b;
    // printf("행렬의 크기 (n * m): ");
    // scanf("%d%d", &a, &b);
    // printf("행렬의 0이 아닌 요소의 개수 :");
    // scanf("%d", &count);
    element item;
    // for(int i = 0; i < count; i++){
    //     printf("행렬 입력 (행, 열, 값) :");
    //     scanf("%d%d%d", &item[i].row, &item[i].col, &item[i].value);
    //     printf("%d, %d, %d 입력\n", item[i].row, item[i].col, item[i].value);
    //     insert_first(head, item[i]);
    // }

    item.row = 3;
    item.col = 2;
    item.value = 5;
    insert_first(head, item);

    print_list1(head);


    printf("20203239 송민서\n");
	return 0;

}