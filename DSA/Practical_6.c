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
    if (ptr == NULL)
    {
        printf("Memory allocation failed\n");
        return head;
    }
    ptr->data = data;
    ptr->next = head;
    return ptr;
}

struct Node *insertEnd(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    if (ptr == NULL)
    {
        printf("Memory allocation failed\n");
        return head;
    }
    ptr->data = data;
    ptr->next = NULL;

    if (head == NULL)
    {
        return ptr;
    }

    struct Node *current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = ptr;
    return head;
}

struct Node *deleteFirst(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return NULL;
    }
    struct Node *temp = head;
    head = head->next;
    free(temp);
    return head;
}

struct Node *deleteAfterPos(struct Node *head, int index)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return NULL;
    }
    struct Node *current = head;
    for (int i = 0; i < index && current != NULL; i++)
    {
        current = current->next;
    }
    if (current == NULL || current->next == NULL)
    {
        printf("Position out of range\n");
        return head;
    }
    struct Node *temp = current->next;
    current->next = temp->next;
    free(temp);
    return head;
}

struct Node *deleteBeforePos(struct Node *head, int index)
{
    if (head == NULL || head->next == NULL || index <= 1)
    {
        printf("Cannot delete before this position\n");
        return head;
    }
    if (index == 2)
    {
        return deleteFirst(head);
    }
    struct Node *current = head;
    for (int i = 0; i < index - 2 && current->next->next != NULL; i++)
    {
        current = current->next;
    }
    if (current->next->next == NULL)
    {
        printf("Position out of range\n");
        return head;
    }
    struct Node *temp = current->next;
    current->next = temp->next;
    free(temp);
    return head;
}

void displayList(struct Node *head)
{
    struct Node *current = head;
    while (current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void freeList(struct Node *head)
{
    struct Node *current = head;
    while (current != NULL)
    {
        struct Node *temp = current;
        current = current->next;
        free(temp);
    }
}

int main()
{
    struct Node *head = NULL;

    head = insertFirst(head, 30);
    head = insertFirst(head, 20);
    head = insertFirst(head, 10);
    head = insertEnd(head, 40);

    printf("Initial list: ");
    displayList(head);

    head = deleteFirst(head);
    printf("After deleting first node: ");
    displayList(head);

    head = deleteAfterPos(head, 1);
    printf("After deleting node after position 1: ");
    displayList(head);

    head = deleteBeforePos(head, 2);
    printf("After deleting node before position 2: ");
    displayList(head);

    freeList(head);
    return 0;
}