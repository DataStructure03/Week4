#ifndef MAXHEAP_H

#define MAXHEAP_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct s_maxheap
{
    int     *arr;
    int     count;
    int     capacity;
}              t_maxheap;

int getRchild(int parent_index);
int getLchild(int parent_index);
int getParent(int child_index);

t_maxheap   *createHeap(int max_size);
void        deleteHeap(t_maxheap *h);
void        addData(t_maxheap *h, int data);
int         removeMaxData(t_maxheap *h);
int         isFullHeap(t_maxheap *h);
int         isEmptyHeap(t_maxheap *h);

void        printHeap(t_maxheap *h);

#endif