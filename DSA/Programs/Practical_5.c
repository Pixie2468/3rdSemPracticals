#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Simple Queue */
struct SimpleQueue
{
    int size;
    int f;
    int r;
    int *queue;
};

/**
 * @brief Checks if the simple queue is empty.
 *
 * This function determines whether the simple queue is empty by checking
 * if both the front and rear indices are at their initial positions (-1).
 *
 * @param[in] ptr The address of the struct SimpleQueue.
 *
 * @return true if the simple queue is empty, false otherwise.
 */
bool isSimpleEmpty(struct SimpleQueue *ptr)
{
    return ptr->f == -1 && ptr->r == -1;
}

/**
 * @brief Checks if the simple queue is full.
 *
 * This function determines whether the simple queue is full by
 * comparing the rear index with the maximum allowed size.
 *
 * @param[in] ptr The address of the struct SimpleQueue.
 *
 * @return true if the simple queue is full, false otherwise.
 */
bool isSimpleFull(struct SimpleQueue *ptr)
{
    return ptr->r == ptr->size - 1;
}

/**
 * @brief Inserts a value into the simple queue.
 *
 * This function adds a new value to the rear of the simple queue. If the
 * queue is full, it prints an error message and returns -1. Otherwise, it
 * places the value at the next available position, updates the rear
 * index, prints a confirmation message, and returns 1.
 *
 * @param[in] ptr   The address of the struct SimpleQueue.
 * @param[in] value The value to be inserted into the simple queue.
 *
 * @return 1 on successful insertion, -1 if the queue is full.
 */
int sEnqueue(struct SimpleQueue *ptr, int value)
{
    if (isSimpleFull(ptr))
    {
        printf("Simple Queue Overflow!\n");
        return -1;
    }
    if (ptr->f == -1)
        ptr->f = 0;
    printf("Inserted element: %d\n", value);
    ptr->queue[++ptr->r] = value;
    return 1;
}

/**
 * @brief Dequeues a value from the simple queue.
 *
 * This function removes a value from the front of the simple queue. If the
 * queue is empty, it prints an error message and returns -1. Otherwise, it
 * removes the value at the front, updates the front index, prints a
 * confirmation message, and returns the value.
 *
 * @param[in] ptr The address of the struct SimpleQueue.
 *
 * @return The value dequeued if the queue is not empty, -1 if the queue is
 *         empty.
 */
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
        printf("Deleted element: %d\n", value);
        return value;
    }
    else
    {
        printf("Deleted element: %d\n", ptr->queue[ptr->f++]);
        return ptr->queue[ptr->f];
    }
}

/**
 * @brief Creates a simple queue with the given size.
 *
 * This function allocates memory for a SimpleQueue structure and initializes
 * it with the given size. It also allocates memory for the queue array of the
 * given size. The front and rear indices are initialized to -1.
 *
 * @param[in] size the size of the simple queue
 *
 * @return the address of the newly created simple queue
 */
struct SimpleQueue *createSimpleQueue(int size)
{
    struct SimpleQueue *q = (struct SimpleQueue *)malloc(sizeof(struct SimpleQueue));
    q->size = size;
    q->f = q->r = -1;
    q->queue = (int *)malloc(q->size * sizeof(int));
    return q;
}

/**
 * Displays the elements of the SimpleQueue in the format
 * "Simple Queue: X Y Z" if the queue is not empty, or
 * "Simple Queue is empty" if the queue is empty.
 *
 * @param ptr the SimpleQueue to be displayed
 */
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

/* Circular Queue */
struct CircularQueue
{
    int size;
    int f;
    int r;
    int *queue;
};

/**
 * @brief Checks if the circular queue is empty.
 *
 * This function determines whether the circular queue is empty by checking
 * if both the front and rear indices are at their initial positions (-1).
 *
 * @param[in] ptr The address of the struct CircularQueue.
 *
 * @return true if the circular queue is empty, false otherwise.
 */
bool isCircularEmpty(struct CircularQueue *ptr)
{
    return ptr->f == -1 && ptr->r == -1;
}

/**
 * @brief Checks if the circular queue is full.
 *
 * This function determines whether the circular queue is full by
 * checking if the rear index plus one (with wrap around) is equal to
 * the front index.
 *
 * @param[in] ptr The address of the struct CircularQueue.
 *
 * @return true if the circular queue is full, false otherwise.
 */
bool isCircularFull(struct CircularQueue *ptr)
{
    return (ptr->r + 1) % ptr->size == ptr->f;
}

/**
 * @brief Inserts a value into the circular queue.
 *
 * This function adds a new value to the rear of the circular queue. If the
 * queue is full, it prints an error message and does not perform the
 * insertion operation. Otherwise, it places the value at the next available
 * position, updates the rear index, prints a confirmation message, and
 * returns.
 *
 * @param[in] ptr   The address of the struct CircularQueue.
 * @param[in] value The value to be inserted into the circular queue.
 */
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
    printf("Inserted element: %d\n", value);
    ptr->queue[ptr->r] = value;
}

/**
 * @brief Removes the front element from the circular queue.
 *
 * This function removes the front element from the circular queue. If the
 * queue is empty, it prints an error message and returns -1.
 *
 * @param[in] ptr The address of the struct CircularQueue.
 *
 * @return The dequeued value if the queue is not empty, -1 if the queue is empty.
 */
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
        printf("Deleted element: %d\n", value);
        return value;
    }
    else
    {
        int temp = ptr->f;
        ptr->f = (ptr->f + 1) % ptr->size;
        printf("Deleted element: %d\n", ptr->queue[temp]);
        return ptr->queue[temp];
    }
}

/**
 * @brief Creates a circular queue with the given size.
 *
 * This function allocates memory for a CircularQueue structure and initializes
 * it with the given size. It also allocates memory for the queue array of the
 * given size. The front and rear indices are initialized to -1.
 *
 * @param[in] size the size of the circular queue
 *
 * @return the address of the newly created circular queue
 */
struct CircularQueue *createCircularQueue(int size)
{
    struct CircularQueue *q = (struct CircularQueue *)malloc(sizeof(struct CircularQueue));
    q->size = size;
    q->f = q->r = -1;
    q->queue = (int *)malloc(q->size * sizeof(int));
    return q;
}

/**
 * @brief Displays the elements of the circular queue.
 *
 * This function prints all the elements of the circular queue in order from
 * front to rear. If the queue is empty, it prints a message indicating that
 * the circular queue is empty.
 *
 * @param[in] ptr The address of the struct CircularQueue to be displayed.
 */
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
    struct SimpleQueue *simpleQueue = createSimpleQueue(5);
    struct CircularQueue *circularQueue = createCircularQueue(5);

    /* Simple Queue */
    sEnqueue(simpleQueue, 7);
    sEnqueue(simpleQueue, 8);
    sEnqueue(simpleQueue, 9);
    sEnqueue(simpleQueue, 10);

    displaySimpleQueue(simpleQueue);

    sEnqueue(simpleQueue, 11);
    displaySimpleQueue(simpleQueue);

    sDequeue(simpleQueue);
    displaySimpleQueue(simpleQueue);

    printf("\n");
    /* Circular Queue */
    cenqueue(circularQueue, 7);
    cenqueue(circularQueue, 8);
    cenqueue(circularQueue, 9);
    cenqueue(circularQueue, 10);

    displayCircularQueue(circularQueue);

    cenqueue(circularQueue, 11);
    displayCircularQueue(circularQueue);

    cdequeue(circularQueue);
    displayCircularQueue(circularQueue);

    return 0;
}