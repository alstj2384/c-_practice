#include <stdio.h>
#define MAX_LIST_SIZE 100
typedef int element;
typedef struct ArrayListType{
    element data[MAX_LIST_SIZE];
    int size;
} ArrayListType;

//init isfull isemp get_entry , print, insert_last insert, delete

void init(ArrayListType *L){
    L->size = 0;
}

int is_full(ArrayListType *L){
    return L->size == MAX_LIST_SIZE;
}

int is_empty(ArrayListType *L){
    return L->size == 0;
}

void insert_last(ArrayListType *L, element item){
    if(is_full(L)){
        //error;
    }
    L->data[L->size++] = item;
}

void insert(ArrayListType *L, int pos, element item){
    if(!is_full(L) && pos >= 0 && pos <= L->size){
        for(int i = L->size-1; i <= pos; i--)
            L->data[i+1] = L->data[i];
        L->data[pos] = item;
        L->size++;
    }
}

element get_entry(ArrayListType *L, int pos){
    if(!is_full(L))
        return L->data[pos];
}

element delete(ArrayListType *L, int pos){
    if(pos < 0 || pos > L->size) return 0;
    element item = L->data[pos];
    for(int i = pos; i < L->size-1; i++)
        L->data[i] = L->data[i+1];
    return item;
}

int main(){
    return 0;
}