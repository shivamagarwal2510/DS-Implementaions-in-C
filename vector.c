#include <stdio.h>
#include <stdlib.h>

int *create_vector(size_t n)
{
    return malloc(n * sizeof(int));
}

void delete_vector(int *v)
{
    free(v);
}

int *resize_vector(int *v, size_t n)
{
    return realloc(v, n * sizeof(int));
    /* returns NULL on failure here */
}
int main()
{
    int *arr = create_vector(2);
    arr[0] = 1;
    arr[1] = 3;
    arr = resize_vector(arr, 3);
    arr[2] = 4;
    for (int i = 0; i < 3; i++)
    {
        printf("%d\n", arr[i]);
    }
    return 0;
}