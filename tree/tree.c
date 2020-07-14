#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

struct TreeNode
{
    ElementType Element;
    SearchTree Left;
    SearchTree Right;
};

SearchTree MakeEmpty(SearchTree T) {
    if(T != NULL) {
        MakeEmpty(T->Left);
        MakeEmpty(T->Right);
        free(T);
    }
    return NULL;
}

Position Find(ElementType X, SearchTree T) {
    if(T == NULL) {
        return NULL;
    }

    if(X < T->Element) {
        return Find(X, T->Left);
    } else if(X > T->Element) {
        return Find(X, T->Right);
    } else {
        return T;
    }
}

Position FindMin(SearchTree T) {
    if(T == NULL) {
        return NULL;
    } else if(T->Left == NULL) {
        return T;
    } else {
        return FindMin(T->Left);
    }
}

Position FindMax(SearchTree T) {
    if(T != NULL) {
        while(T->Right != NULL) {
            T = T->Right;
        }
    }

    return T;
}

SearchTree Insert(ElementType X, SearchTree T) {
    if(T == NULL) {
        T = (Position)malloc(sizeof(struct TreeNode));
        T->Element = X;
        T->Left = T->Right = NULL;
    } else if(X < T->Element) {
        T->Left = Insert(X, T->Left);
    } else if(X > T->Right){
        T->Right = Insert(X, T->Right);
    }

    /* Else X is the tree already;we'll do nothing */

    return T;
}

SearchTree Delete(ElementType X, SearchTree)