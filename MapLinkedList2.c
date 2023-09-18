#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct ht_item
{
    int key;
    int val;
    struct ht_item *next;
} ht_item;

typedef struct hashTable
{
    ht_item **item;
    int size;
    int capacity;
} hashTable;

int hashCode(hashTable *table, int key)
{
    return key % (table->capacity);
}
ht_item *create_item(int key, int val)
{
    ht_item *item = (ht_item *)malloc(sizeof(item));
    item->key = key;
    item->val = val;
    item->next = NULL;
    return item;
}
hashTable *createHashTable(int n)
{
    hashTable *ht = (hashTable *)malloc(sizeof(hashTable));
    ht->item = (ht_item **)malloc(n * sizeof(ht_item *));
    ht->capacity = n;
    ht->size = 0;
    for (int i = 0; i < n; i++)
    {
        ht->item[i] = NULL;
    }
    return ht;
}
void insert(hashTable *table, int key, int val)
{
    int index = hashCode(table, key);
    ht_item *curr_item = table->item[index];
    if (table->size == table->capacity)
    {
        printf("Table is Full\n");
        return;
    }

    if (!curr_item)
    {
        ht_item *item = create_item(key, val);
        table->item[index] = item;
        table->size++;
        return;
    }
    else
    {
        ht_item *temp = curr_item;
        while (temp->next)
        {
            if (temp->key == key)
            {
                temp->val = val;
                return;
            }
            temp = temp->next;
        }
        ht_item *item = create_item(key, val);
        temp->next = item;
    }
}
int search(hashTable *table, int key)
{
    int index = hashCode(table, key);
    ht_item *curr_item = table->item[index];
    if (!curr_item)
    {
        printf("Key does not exist\n");
        return -1;
    }
    else
    {
        ht_item *temp = curr_item;
        while (temp->next)
        {
            if (temp->key == key)
            {
                return temp->val;
            }
            temp = temp->next;
        }
        if (temp->key == key)
        {
            return temp->val;
        }
    }
    printf("Key does not exist\n");
    return -1;
}
void delete(hashTable *table, int key)
{
    int index = hashCode(table, key);
    ht_item *curr_item = table->item[index];
    if (!curr_item)
    {
        printf("Key does not exist in map\n");
        return;
    }
    else
    {
        if (curr_item->key == key)
        {
            table->item[index] = curr_item->next;
            free(curr_item);
            printf("Key Deleted Successfully!");
            return;
        }
        ht_item *temp = curr_item->next;
        ht_item *prev = curr_item;
        while (temp)
        {
            if (temp->key == key)
            {
                prev->next = temp->next;
                free(temp);
                printf("Key Deleted Successfully!");
                return;
            }
            prev = temp;
            temp = temp->next;
        }
        printf("Key does not exist\n");
    }
}
int main()
{
    hashTable *ht = createHashTable(10);
    insert(ht, 1, 2);
    insert(ht, 11, 3);
    printf("Value at %d is %d \n", 1, search(ht, 1));
    printf("Value at %d is %d \n", 2, search(ht, 2));
    printf("Value at %d is %d \n", 11, search(ht, 11));
    // delete (ht, 1);
    // printf("%d", search(ht, 1));
    // printf("%d", 1);
    return 0;
}