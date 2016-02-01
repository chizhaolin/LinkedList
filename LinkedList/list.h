#include <stdio.h>
#include <stdlib.h>

#ifndef _linked_list_h
#define _linked_list_h

struct node {
    int num;
    struct node * next;
};

typedef struct node NODE;
typedef struct node * P_NODE;

P_NODE initList(int);
P_NODE addNodeToList(P_NODE, int);
P_NODE deleteNode(P_NODE, int);
void destroyList(P_NODE*);
void printList(P_NODE);
#endif
