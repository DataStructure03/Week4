#include "maxHeap.h"

int getRchild(int parent_index){
        return (2 * parent_index + 1);
}

int getLchild(int parent_index){
  return (2 * parent_index);  
}

int getParent(int child_index){
  return (child_index / 2);
}

t_maxheap   *createHeap(int max_size)
{
    t_maxheap   *newHeap = (t_maxheap *)malloc(sizeof(t_maxheap));
    int         *arr = (int *)malloc(sizeof(int) * (max_size + 1));
    
    newHeap->arr = arr;
    newHeap->capacity = max_size;
    newHeap->count = 0;
    return (newHeap);
}

void        deleteHeap(t_maxheap *h){
  free(h->arr);
  h->arr = NULL;
  
  free(h);
  h = NULL;
}

void        addData(t_maxheap *h, int data)
{
    int temp = h->count + 1;
    int aux;
    int parent;
  
    if (isFullHeap(h))
    {
        printf("isFULL\n");
        return ;
    }
    h->arr[h->count + 1] = data;
    while (temp > 1)
    {
        parent = getParent(temp);
        if (h->arr[parent] > h->arr[temp])
          break;
        {
            aux = h->arr[parent];
            h->arr[parent] = h->arr[temp];
            h->arr[temp] = aux;
        }
        temp = parent;
    }
    h->count++; 
}

void      DownHeap(t_maxheap *h, int parent)
{
    int temp;
    int aux;

    if (getLchild(parent) > h->count)
        return ;
    
    temp = getLchild(parent);
    if (getRchild(parent) > h->count)
        ;
    else
        if (h->arr[getRchild(parent)] > h->arr[temp])
          temp = getRchild(parent);


    if ( h->arr[parent] < h->arr[temp]){
        {
            aux = h->arr[parent];
            h->arr[parent] = h->arr[temp];
            h->arr[temp] = aux;
        }
        DownHeap(h, temp);
    }
}

int        removeMaxData(t_maxheap *h)
{
    if (isEmptyHeap(h))
    {
        printf("EMPTY\n");
        return -1;
    }
        
    h->arr[1] = h->arr[h->count];    
    h->count--;
    DownHeap(h, 1);
}


int         isFullHeap(t_maxheap *h){
    return (h->count == h->capacity);
}

int         isEmptyHeap(t_maxheap *h)
{
    return (h->count == 0);
}

void        printHeap(t_maxheap *h)
{
    for (int i = 1; i <= h->count; i++)
        printf("%d ", h->arr[i]);
    printf("\n ");
}