#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
struct stack
{
    int top;
    int size;
    int *arr;
};
struct stack *createStack(int n)
{
    struct stack *st = (struct stack *)malloc(n * sizeof(int));
    st->size = n;
    st->top = -1;
}
bool isFull(struct stack *st)
{
    if (st->top == st->size - 1)
    {
        return true;
    }
    return false;
}
void push(struct stack *st, int val)
{
    if (isFull(st))
    {
        return;
    }
    st->top++;
    st->arr[st->top] = val;
    st->size++;
}
bool isEmpty(struct stack *st)
{
    if (st->top == -1)
    {
        return true;
    }
    return false;
}
int pop(struct stack *st)
{
    if (isEmpty(st))
    {
        return -1;
    }
    int val = st->arr[st->top];
    st->top--;
    return val;
}

int main()
{
    struct stack *st = createStack(20);
    push(st, 1);
    push(st, 2);
    push(st, 3);
    push(st, 4);
    printf("value of top %d \n", pop(st));
    printf("value of top %d \n", pop(st));
    push(st, 5);
    printf("value of top %d \n", pop(st));
    printf("value of top %d \n", pop(st));
    printf("value of top %d \n", pop(st));
    printf("value of top %d \n", pop(st));
    return 0;
}