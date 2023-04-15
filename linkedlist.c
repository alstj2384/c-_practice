#include <stdio.h>
#include <malloc.h>
#include <string.h>


typedef struct NODE{
    char szchar[64];

    struct NODE* next;
} NODE;

NODE *g_phead = NULL;// 노드에 대한 데이터를 담는 거고, 거기에 NULL을 넣은거임

void printNode(void){

    NODE *pTmp = g_phead;
    while(pTmp != 0){
        printf("[%p] %s\n", pTmp, pTmp->szchar);
        pTmp = pTmp->next;
    }
    putchar('\n');
}

int addNode(char * c){
    NODE *pNode = (NODE *)malloc(sizeof(NODE));
    memset(pNode, 0, sizeof(NODE));

    strcpy(pNode->szchar, c);

    if(g_phead == 0)
        g_phead = pNode;
    else{
        pNode->next = g_phead;
        g_phead = pNode;
    }
    return 1;
}
int main(){

    addNode("Test Test!");
    addNode("Test Test!");
    printNode();
    addNode("Test Test!");
    printNode();
    addNode("Test Test!");
    printNode();
    return 0;
}