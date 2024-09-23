#include <stdio.h>
#include <stdlib.h>

struct DoubleNode
{
    int data;
    struct DoubleNode *prev, *next;
};

struct DoubleNode *insertFront(struct DoubleNode *head, int data)
{
    struct DoubleNode *ptr = (struct DoubleNode *)malloc(sizeof(struct DoubleNode));
    if (ptr == NULL)
    {
        printf("Memory allocation failed\n");
        return head;
    }
    ptr->data = data;
    ptr->next = head;
    ptr->prev = NULL;
    if (head != NULL)
    {
        head->prev = ptr;
    }
    return ptr;
}

struct DoubleNode *insertEnd(struct DoubleNode *head, int data)
{
    struct DoubleNode *ptr = (struct DoubleNode *)malloc(sizeof(struct DoubleNode));
    if (ptr == NULL)
    {
        printf("Memory allocation failed\n");
        return head;
    }
    ptr->data = data;
    ptr->next = NULL;

    if (head == NULL)
    {
        ptr->prev = NULL;
        return ptr;
    }

    struct DoubleNode *current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = ptr;
    ptr->prev = current;
    return head;
}

struct DoubleNode *deleteFront(struct DoubleNode *head)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return NULL;
    }

    struct DoubleNode *temp = head;
    head = head->next;
    if (head != NULL)
    {
        head->prev = NULL;
    }
    free(temp);
    return head;
}

struct DoubleNode *deleteAfterPos(struct DoubleNode *head, int position)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return NULL;
    }

    struct DoubleNode *current = head;
    for (int i = 0; i < position && current != NULL; i++)
    {
        current = current->next;
    }

    if (current == NULL || current->next == NULL)
    {
        printf("Position out of range\n");
        return head;
    }

    struct DoubleNode *temp = current->next;
    current->next = temp->next;
    if (temp->next != NULL)
    {
        temp->next->prev = current;
    }
    free(temp);
    return head;
}

void displayList(struct DoubleNode *head)
{
    struct DoubleNode *current = head;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void freeList(struct DoubleNode *head)
{
    struct DoubleNode *current = head;
    while (current != NULL)
    {
        struct DoubleNode *temp = current;
        current = current->next;
        free(temp);
    }
}

int main()
{
    struct DoubleNode *head = NULL;

    head = insertFront(head, 10);
    head = insertFront(head, 20);
    head = insertEnd(head, 30);
    head = insertEnd(head, 40);

    printf("Initial list: ");
    displayList(head);

    head = deleteFront(head);
    printf("After deleting front node: ");
    displayList(head);

    head = deleteAfterPos(head, 1);
    printf("After deleting node after position 1: ");
    displayList(head);

    freeList(head);
    return 0;
}