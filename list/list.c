#include <stdio.h>
#include <stdlib.h>
#include "list.h"

struct Node
{
    ElementType Element;
    Position Next;
};

//判断链表是否为空
int IsEmpty(List L){
    return L->Next == NULL;
}

//判断当前位置是否是链表末尾
int IsLast(Position P, List L) {
    return P->Next == NULL;
}

/* Return Position of X in L;NULL if not found */
Position Find(ElementType X, List L){
    Position P = L->Next;
    while( P !=NULL && P->Element !=X ) {
        P = P->Next;
    }
    return P;
}

/* if X is not found,then next field of returned Position is NULL*/
/* Assumes a header*/
Position FindPrevious(ElementType X, List L) {
    Position P = L;
    while( P->Next != NULL && P->Next->Element != X) {
        P = P->Next;
    }
    return P;
}

/* Delete first occurrence of X from a List*/
/* Assume use of a header node */
void Delete(ElementType X, List L) {
    Position P, TmpCell;
    P = FindPrevious(X , L);
    if(!IsLast(P, L)) {
        TmpCell = P->Next;
        P->Next = TmpCell->Next;
        free(TmpCell);
    }
}

/* Insert (after legal position P)*/
/* Header implementation assumed */
/* Parameter L is unused in this implementation */
void Insert(ElementType X, List L, Position P) {
    Position TmpCell;
    TmpCell = malloc(sizeof(struct Node));
    if(TmpCell == NULL) {
        printf("Out of space!!");
    }
    TmpCell->Element = X;
    TmpCell->Next = P->Next;
    P->Next = TmpCell;
}

/* Delete List*/
void DeleteList(List L) {
    Position P, Tmp;
    P = L->Next;
    L->Next = NULL;
    while(P != NULL) {
        Tmp = P->Next;
        free(P);
        P = Tmp;
    }
}


int main(void) {
    
    system("pause");   //防止闪退
    return 0;
}