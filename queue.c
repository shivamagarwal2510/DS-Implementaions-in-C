#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
struct queue
{
    int front, rear, size, capacity;
    int *arr;
};
struct queue *createQueue(int n)
{
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    q->capacity = n;
    q->front = 0;
    q->size = 0;
    q->rear = q->capacity - 1;
    return q;
}
bool isFull(struct queue *q)
{
    if (q->size == q->capacity)
    {
        return true;
    }
    return false;
}
bool isEmpty(struct queue *q)
{
    if (q->size == 0)
    {
        return true;
    }
    return false;
}
void enqueue(struct queue *q, int val)
{
    if (isFull(q))
    {
        return;
    }
    q->rear = (q->rear + 1) % q->capacity;
    q->arr[q->rear] = val;
    q->size++;
}
int dequeue(struct queue *q)
{
    if (isEmpty(q))
    {
        return -1;
    }
    int val = q->arr[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    return val;
}
int main()
{
    struct queue *q = createQueue(20);
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    printf("value of front %d \n", dequeue(q));
    printf("value of front %d \n", dequeue(q));
    enqueue(q, 5);
    printf("value of front %d \n", dequeue(q));
    printf("value of front %d \n", dequeue(q));
    printf("value of front %d \n", dequeue(q));
    printf("value of front %d \n", dequeue(q));
    return 0;
}