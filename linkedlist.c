#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char name[100];
} element;
typedef struct ListNode{
    element data;
    struct ListNode *Link;
} ListNode;

//error insert_first, insert, delete_first, delete, print_list

ListNode* insert_first(ListNode* head, element value){
    ListNode *p = (ListNode*)malloc(sizeof(ListNode));
    p->data = value;
    p->Link = head; // 여기서 head는 다음 노드 그 자체를 의미(주소)
    head = p;
    return head;
}

ListNode* insert(ListNode* head,ListNode* pre, element value){
    ListNode* p = (ListNode*)malloc(sizeof(ListNode));
    p->data = value;
    p->Link = pre->Link;
    pre->Link = p;
    return head;
}

ListNode* delete_first(ListNode* head){
    ListNode* remove;
    if(head == NULL) return NULL;
    remove = head;
    head = remove->Link;
    free(remove);
    return head;
}

ListNode* delete(ListNode* head, ListNode* pre){
    ListNode* remove;
    remove = pre->Link;
    pre->Link = remove->Link;
    free(remove);
    return head;
}

ListNode* print_list(ListNode* head){
    for(ListNode *p = head; p != NULL; p = p->Link)
        printf("%s->", p->data.name);
    printf("NULL \n");
}


int main(){
    ListNode* head = NULL;
    element data;


    strcpy(data.name, "APPLE");
    head = insert_first(head, data);
    print_list(head);

    strcpy(data.name, "KIWI");
    head = insert_first(head, data);
    print_list(head);

    
    strcpy(data.name, "BANANA");
    head = insert_first(head, data);
    print_list(head);
    return 0;
}