/* list1.c */
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include "list1.h"

list create_list() {
    list l;
    l = (list)malloc(sizeof (struct Node));
    if(l == NULL) {
        perror("malloc error");
        exit(1);
    }

    l->next = NULL;
    return (l);
}

void insert(int x, list l, position p) {
    position newnode;
    newnode = (list)malloc(sizeof( struct Node));
    if(newnode == NULL) {
        perror("malloc error");
        exit(1);
    }

    newnode->data = x;
    newnode->next = p->next;
    p->next = newnode;
}

void insert_to_head(int x, list l) {
    insert(x, l ,l);
}

void insert_to_tail(int x, list l) {
    ptr_to_node nptr;
    nptr = l;
    while(nptr->next != NULL) {
        nptr = nptr->next;
    }
    insert(x, l, nptr);
}

position find_previous(int x, list l) {
    position p;
    p = l;
    while(p->next != NULL && p->next->data != x) {
        p = p->next;
    }
    return (p);
}

int is_last(position p, list l) {
    return (p->next == NULL);
}

void delete_list(int x, list l) {
    position p, tmpp;
    p = find_previous(x, l);
    if(!is_last(p, l)) {
        tmpp = p->next;
        p->next = tmpp->next;
        free(tmpp);
    }
}

void printl(list l) {
    position p;
    p = l->next;
    while(p != NULL) {
        printf("%d->", p->data);
        p = p->next;
    }
    printf("NULL\n");
}

void make_empty(list l) {
    ptr_to_node p, p_next;
    p = l->next;
    while(p != NULL) {
        p_next = p->next;
        free(p);
        p = p->next;
    }
    l->next = NULL;
}

int find_max(int A[], int N) {
    int i, max;
    max= A[0];
    for(i=1; i<N; i++) {
        if(A[i] > max) {
            max = A[i];
        }
    }

    return (max);
}

void bucket_sort(int A[], int N) {
    int i, M;
    M = find_max(A, N);
    list count[10], l;
    for(i =0; i<= 10; i++) {
        count[i] = create_list();
    }

    for(i =0; i<N; i++) {
        insert_to_tail(A[i], count[A[i]]);
    }

    for(i =0; i<= 10; i++) {
        for(l = count[i]->next; l != NULL; l= l->next) {
            printf("%d ", l->data);
        }
    }

    printf("\n");
}

int main(void) {
    int i;
    int A[] = {3,2,4,5,8,1,7,6};
    printf("before sorted: ");
    for(i=0; i<8; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
    printf("after sorted");
    bucket_sort(A , 8);
    printf("\n");

    system("pause");   //防止闪退
    return 0;
}