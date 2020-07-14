/* list1.h */
#ifndef _LINKLIST_H

#define _LINKLIST_H

struct Node {
    int data;
    struct Node *next;
};

typedef struct Node *ptr_to_node;
typedef struct Node *position;
typedef struct Node *list;
list create_list();
void insert(int x, list l, position p);
void insert_to_head(int x, list l);
void insert_to_tail(int x, list l);
position find_previous(int x, list l);
int is_last(position p, list l);
void delete_list(int x, list l);
void printl(list l);
void make_empty(list l);

#endif