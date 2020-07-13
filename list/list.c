#include <stdio.h>
#include <stdlib.h>
#include "list.h"

struct Node
{
    ElementType Element;
    Position Next;
};

//Âà§Êñ≠ÈìæË°®ÊòØÂê¶‰∏∫Á©∫
int IsEmpty(List L){
    return L->Next == NULL;
}

//Âà§Êñ≠ÂΩìÂâç‰ΩçÁΩÆÊòØÂê¶ÊòØÈìæË°®Êú´Â∞?
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
    TmpCell = (Position)malloc(sizeof(struct Node));
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
    List L = (Position)malloc(sizeof(struct Node));
    List L2 = (Position)malloc(sizeof(struct Node));
    L2->Next = NULL;
    Position n1 = (Position)malloc(sizeof(struct Node));
    n1->Element = 1;
    Position n2 = (Position)malloc(sizeof(struct Node));
    n2->Element = 2;
    L->Next = n1;
    n1->Next = n2;
    n2->Next = NULL;
    printf(" «∑Ò «ø’¡¥±Ì%d\n", IsEmpty(L));
    printf(" «∑Ò «ø’¡¥±Ì%d\n", IsEmpty(L2));
    system("pause");   //∑¿÷π…¡ÕÀ
    return 0;
}