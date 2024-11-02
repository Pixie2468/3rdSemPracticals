#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

/**
 * Checks if the linked list is empty.
 *
 * @param head pointer to the head of the linked list
 * @return 1 (true) if the list is empty, 0 (false) otherwise
 */
int checkHead(struct Node *head)
{
    return head == NULL;
}

/**
 * Inserts a new node at the beginning of the linked list.
 *
 * @param head pointer to the head of the linked list
 * @param data the data to be stored in the new node
 * @return the updated head of the linked list
 */
struct Node *insertFirst(struct Node *head, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        return NULL;
    }

    newNode->data = data;

    if (checkHead(head))
    {
        newNode->next = newNode;
        return newNode;
    }

    struct Node *ptr = head;
    while (ptr->next != head)
    {
        ptr = ptr->next;
    }

    newNode->next = head;
    ptr->next = newNode;
    return newNode;
}

/**
 * Inserts a new node at the given position in the linked list.
 *
 * @param head pointer to the head of the linked list
 * @param pos the position at which the new node is to be inserted
 * @param data the data to be stored in the new node
 * @return the updated head of the linked list
 */
struct Node *insertPos(struct Node *head, int pos, int data)
{
    if (pos < 0)
    {
        return head;
    }

    if (pos == 0 || checkHead(head))
    {
        return insertFirst(head, data);
    }

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        return head;
    }

    struct Node *current = head;
    int i = 0;
    while (i < pos - 1 && current->next != head)
    {
        current = current->next;
        i++;
    }

    newNode->data = data;
    newNode->next = current->next;
    current->next = newNode;
    return head;
}

/**
 * Deletes the first node of the circular linked list.
 *
 * @param head pointer to the head of the circular linked list
 * @return the updated head of the circular linked list
 */
struct Node *deleteFirst(struct Node *head)
{
    if (checkHead(head))
    {
        return NULL;
    }

    if (head->next == head)
    {
        free(head);
        return NULL;
    }

    struct Node *last = head;
    while (last->next != head)
    {
        last = last->next;
    }

    struct Node *newHead = head->next;
    last->next = newHead;
    free(head);
    return newHead;
}

/**
 * Deletes the node at the given position in the circular linked list.
 *
 * @param head pointer to the head of the circular linked list
 * @param pos the position at which the node is to be deleted
 * @return the updated head of the circular linked list
 */
struct Node *deletePos(struct Node *head, int pos)
{
    if (checkHead(head) || pos < 0)
    {
        return head;
    }

    if (pos == 0)
    {
        return deleteFirst(head);
    }

    struct Node *current = head;
    int i = 0;
    while (i < pos - 1 && current->next != head)
    {
        current = current->next;
        i++;
    }

    if (current->next == head || i < pos - 1)
    {
        return head;
    }

    struct Node *temp = current->next;
    current->next = temp->next;
    free(temp);
    return head;
}

/**
 * Displays the circular linked list in the format 1 2 3 ... n.
 *
 * If the list is empty, it prints a message indicating that the list is empty.
 *
 * @param head pointer to the head of the circular linked list
 */
void displayList(struct Node *head)
{
    if (checkHead(head))
    {
        printf("List is empty\n");
        return;
    }

    struct Node *current = head;
    do
    {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);
    printf("\n");
}

/**
 * Frees all the memory allocated for the circular linked list.
 *
 * @param head the head of the circular linked list
 */
void freeList(struct Node *head)
{
    if (checkHead(head))
    {
        return;
    }

    struct Node *current = head->next;
    struct Node *temp;

    while (current != head)
    {
        temp = current;
        current = current->next;
        free(temp);
    }
    free(head);
}

int main()
{
    struct Node *head = NULL;

    // Test insertions
    head = insertPos(head, 0, 1);
    head = insertPos(head, 1, 2);
    head = insertPos(head, 2, 3);
    head = insertPos(head, 3, 4);
    head = insertPos(head, 4, 5);

    printf("Original list: ");
    displayList(head);

    // Test deletion
    head = deletePos(head, 0);
    printf("After deleting position 0: ");
    displayList(head);

    // Free the list
    freeList(head);
    return 0;
}