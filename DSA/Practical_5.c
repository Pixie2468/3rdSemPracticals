#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct SimpleQueue
{
    int size;
    int f;
    int r;
    int *queue;
};

struct CircularQueue
{
    int size;
    int f;
    int r;
    int *queue;
};

bool isSimpleEmpty(struct SimpleQueue *ptr)
{
    return ptr->f == -1 && ptr->r == -1;
}

bool isSimpleFull(struct SimpleQueue *ptr)
{
    return ptr->r == ptr->size - 1;
}

bool isCircularEmpty(struct CircularQueue *ptr)
{
    return ptr->f == -1 && ptr->r == -1;
}

bool isCircularFull(struct CircularQueue *ptr)
{
    return (ptr->r + 1) % ptr->size == ptr->f;
}

int sEnqueue(struct SimpleQueue *ptr, int value)
{
    if (isSimpleFull(ptr))
    {
        printf("Simple Queue Overflow!\n");
        return -1;
    }
    if (ptr->f == -1)
        ptr->f = 0;
    ptr->queue[++ptr->r] = value;
    return 1;
}

int sDequeue(struct SimpleQueue *ptr)
{
    if (isSimpleEmpty(ptr))
    {
        printf("Simple Queue Underflow!\n");
        return -1;
    }
    if (ptr->f == ptr->r)
    {
        int value = ptr->queue[ptr->f];
        ptr->f = ptr->r = -1;
        return value;
    }
    else
    {
        return ptr->queue[ptr->f++];
    }
}

void cenqueue(struct CircularQueue *ptr, int value)
{
    if (isCircularFull(ptr))
    {
        printf("Circular Queue Overflow!\n");
        return;
    }
    if (ptr->f == -1)
        ptr->f = 0;
    ptr->r = (ptr->r + 1) % ptr->size;
    ptr->queue[ptr->r] = value;
}

int cdequeue(struct CircularQueue *ptr)
{
    if (isCircularEmpty(ptr))
    {
        printf("Circular Queue Underflow!\n");
        return -1;
    }
    if (ptr->f == ptr->r)
    {
        int value = ptr->queue[ptr->f];
        ptr->f = ptr->r = -1;
        return value;
    }
    else
    {
        int temp = ptr->f;
        ptr->f = (ptr->f + 1) % ptr->size;
        return ptr->queue[temp];
    }
}

struct SimpleQueue *createSimpleQueue(int size)
{
    struct SimpleQueue *q = (struct SimpleQueue *)malloc(sizeof(struct SimpleQueue));
    q->size = size;
    q->f = q->r = -1;
    q->queue = (int *)malloc(q->size * sizeof(int));
    return q;
}

struct CircularQueue *createCircularQueue(int size)
{
    struct CircularQueue *q = (struct CircularQueue *)malloc(sizeof(struct CircularQueue));
    q->size = size;
    q->f = q->r = -1;
    q->queue = (int *)malloc(q->size * sizeof(int));
    return q;
}

void displaySimpleQueue(struct SimpleQueue *ptr)
{
    if (isSimpleEmpty(ptr))
    {
        printf("Simple Queue is empty\n");
        return;
    }
    printf("Simple Queue: ");
    for (int i = ptr->f; i <= ptr->r; i++)
    {
        printf("%d ", ptr->queue[i]);
    }
    printf("\n");
}

void displayCircularQueue(struct CircularQueue *ptr)
{
    if (isCircularEmpty(ptr))
    {
        printf("Circular Queue is empty\n");
        return;
    }
    int i = ptr->f;
    printf("Circular Queue: ");
    do
    {
        printf("%d ", ptr->queue[i]);
        i = (i + 1) % ptr->size;
    } while (i != (ptr->r + 1) % ptr->size);
    printf("\n");
}

int main()
{
    int size;
    printf("Enter the size of the queues: ");
    scanf("%d", &size);

    struct SimpleQueue *simplequeue = createSimpleQueue(size);
    struct CircularQueue *circularqueue = createCircularQueue(size);
    int choice;
    while (choice != 5)
    {
        printf("\nEnter your choice\n1->Simple Queue Enqueue\n2->Circular Queue Enqueue\n3->Simple Queue Dequeue\n4->Circular Queue Dequeue\n5->Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            if (isSimpleFull(simplequeue))
            {
                printf("Simple Queue Full, cannot enqueue\n");
            }
            else
            {
                int value;
                printf("Enter the value: ");
                scanf("%d", &value);
                sEnqueue(simplequeue, value);
                displaySimpleQueue(simplequeue);
            }
            break;
        }
        case 2:
        {
            if (isCircularFull(circularqueue))
            {
                printf("Circular Queue Full, cannot enqueue\n");
            }
            else
            {
                int value;
                printf("Enter the value: ");
                scanf("%d", &value);
                cenqueue(circularqueue, value);
                displayCircularQueue(circularqueue);
            }
            break;
        }

        case 3:
        {
            int value = sDequeue(simplequeue);
            if (value != -1)
                printf("Dequeued value from Simple Queue: %d\n", value);
            displaySimpleQueue(simplequeue);
            break;
        }
        case 4:
        {
            int value = cdequeue(circularqueue);
            if (value != -1)
                printf("Dequeued value from Circular Queue: %d\n", value);
            displayCircularQueue(circularqueue);
            break;
        }
        case 5:
            break;
        default:
            printf("Incorrect Input\n");
        }
    }

    free(simplequeue->queue);
    free(simplequeue);
    free(circularqueue->queue);
    free(circularqueue);

    return 0;
}