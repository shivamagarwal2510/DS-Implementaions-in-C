#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// MaxHeap
struct heap
{
    int *arr;
    int size;
    int ptr;
};
struct heap *createHeap(int n)
{
    struct heap *pq = (struct heap *)malloc(sizeof(struct heap));
    pq->size = n;
    pq->arr = (int *)malloc(n * sizeof(int));
    pq->ptr = -1;
}
bool isFull(struct heap *pq)
{
    if (pq->ptr == pq->size - 1)
    {
        return true;
    }
    return false;
}
bool isEmpty(struct heap *pq)
{
    if (pq->ptr == -1)
    {
        return true;
    }
    return false;
}
void insert(struct heap *pq, int val)
{
    if (isFull(pq))
    {
        return;
    }
    pq->ptr++;
    int index = pq->ptr;
    pq->arr[index] = val;
    while (index > 0)
    {
        int parent = (index - 1) / 2;
        if (pq->arr[parent] < pq->arr[index])
        {
            int temp = pq->arr[parent];
            pq->arr[parent] = pq->arr[index];
            pq->arr[index] = temp;
            index = parent;
        }
        else
        {
            return;
        }
    }
}

int delete(struct heap *pq)
{
    if (isEmpty(pq))
    {
        return -1;
    }
    int val = pq->arr[0];
    pq->arr[0] = pq->arr[pq->ptr--];
    int i = 0;
    while (i < pq->ptr)
    {
        int leftIdx = 2 * i + 1;
        int rightIdx = 2 * i + 2;
        if (leftIdx <= pq->ptr && pq->arr[i] < pq->arr[leftIdx])
        {
            int temp = pq->arr[i];
            pq->arr[i] = pq->arr[leftIdx];
            pq->arr[leftIdx] = temp;
            i = leftIdx;
        }
        if (rightIdx <= pq->ptr && pq->arr[i] < pq->arr[rightIdx])
        {
            int temp = pq->arr[i];
            pq->arr[i] = pq->arr[rightIdx];
            pq->arr[rightIdx] = temp;
            i = rightIdx;
        }
        else
        {
            return val;
        }
    }
    return val;
}
int main()
{
    struct heap *pq = createHeap(20);
    insert(pq, 5);
    insert(pq, 3);
    insert(pq, 2);
    printf("%d \n", delete (pq));
    printf("%d \n", delete (pq));
    printf("%d \n", delete (pq));
    printf("%d \n", delete (pq));
    return 0;
}