#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *insertFirst(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->next = head;
    ptr->data = data;
    return ptr;
}

struct Node *insertEnd(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *ptr2 = head;
    while (ptr2->next != NULL)
    {
        ptr2 = ptr->next;
    }
    ptr->data = data;
    ptr2->next = ptr;
    ptr->next = NULL;
    return head;
}

struct Node *deleteFirst(struct Node *head)
{
    struct Node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

struct Node *deleteAfterPos(struct Node *head, int index)
{
    struct Node *ptr = head;
    for (int i = 0; i < index; i++)
    {
        ptr = ptr->next;
    }
    struct Node *ptr2 = ptr;
    ptr = ptr2->next;
    free(ptr2);
    return head;
}
struct Node *deleteBeforePos(struct Node *head, int index)
{
    struct Node *ptr = head;
    for (int i = 0; i < index - 1; i++)
    {
        ptr = ptr->next;
    }
    struct Node *ptr2 = ptr;
    ptr = ptr2->next;
    free(ptr2);
    return head;
}
int main()
{

    return 0;
}