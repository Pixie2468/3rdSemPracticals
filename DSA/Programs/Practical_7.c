#include <stdio.h>
#include <stdlib.h>

struct DoubleNode
{
    int data;
    struct DoubleNode *prev, *next;
};

/**
 * Inserts a new node at the beginning of the linked list.
 *
 * @param head pointer to the head of the linked list
 * @param data the data to be stored in the new node
 * @return the updated head of the linked list
 */
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

/**
 * Inserts a new node at the end of the doubly linked list.
 *
 * @param head pointer to the head of the doubly linked list
 * @param data the data to be stored in the new node
 * @return the updated head of the doubly linked list
 */
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

/**
 * Deletes the first node of the doubly linked list.
 *
 * @param head pointer to the head of the doubly linked list
 * @return the updated head of the doubly linked list
 */
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

/**
 * Deletes the node after the given index in the doubly linked list.
 *
 * @param head pointer to the head of the doubly linked list
 * @param position the index after which the node is to be deleted
 * @return the updated head of the doubly linked list
 */
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

/**
 * Displays the doubly linked list in the format 1 2 3 ... n
 *
 * @param head pointer to the head of the doubly linked list
 */
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

/**
 * Frees all the memory allocated for the doubly linked list
 *
 * @param head the head of the doubly linked list
 */
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