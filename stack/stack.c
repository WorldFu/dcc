#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

struct Node{
    ElementType Element;
    PtrToNode Next;
};

int IsEmpty(Stack S) {
    return S->Next == NULL;
}

Stack CreateStack(void) {
    Stack S;
    S = (Stack)malloc(sizeof(struct Node));
    S->Next = NULL;
    MakeEmpty(S);
    return S;
}

void MakeEmpty(Stack S) {
    if(S == NULL) {
        printf("ERROR");
    } else {
        while(!IsEmpty(S)){
            Pop(S);
        }
    }
}

void Push(ElementType X, Stack S) {
    PtrToNode TmpCell;
    TmpCell = (Stack)malloc(sizeof(struct Node));
    TmpCell->Element = X;
    TmpCell->Next = S->Next;
    S->Next = TmpCell;
}

ElementType Top(Stack S) {
    if(!IsEmpty(S)) {
        return S->Next->Element;
    }

    return 0;
}

void Pop(Stack S) {
    PtrToNode FirstCell;
    if(IsEmpty(S)) {
        printf("ERROR");
    } else {
        FirstCell = S->Next;
        S->Next = FirstCell->Next;
        free(FirstCell);
    }
}