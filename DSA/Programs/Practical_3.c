#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Stack
{
    int size;
    int top;
    int *arr;
};

/**
 * @brief Checks if the stack is full.
 *
 * @param[in] ptr  The address of the struct Stack.
 *
 * @return true if the stack is full, false otherwise.
 */
bool isFull(struct Stack *ptr)
{
    return ptr->top == ptr->size - 1;
}

/**
 * @brief Checks if the stack is empty.
 *
 * @param[in] ptr  The address of the struct Stack.
 *
 * @return true if the stack is empty, false otherwise.
 */
bool isEmpty(struct Stack *ptr)
{
    return ptr->top == -1;
}

/**
 * @brief Pushes a value onto the stack.
 *
 * This function adds a new value to the top of the stack. If the stack
 * is full, it prints an error message and returns -1. Otherwise, it
 * places the value at the next available position, updates the top
 * index, prints a confirmation message, and returns 0.
 *
 * @param[in] ptr   The address of the struct Stack.
 * @param[in] value The value to be pushed onto the stack.
 *
 * @return 0 on successful push, -1 if the stack is full.
 */
int push(struct Stack *ptr, int value)
{
    if (isFull(ptr))
    {
        printf("Stack Overflow!\n");
        return -1;
    }
    ptr->arr[++ptr->top] = value;
    printf("Value pushed: %d\n", value);
    return 0;
}

/**
 * @brief Pops a value from the stack.
 *
 * This function removes the top value from the stack and returns it. If the
 * stack is empty, it prints an error message and returns -1.
 *
 * @param[in] ptr  The address of the struct Stack.
 *
 * @return The popped value if the stack is not empty, -1 if the stack is empty.
 */
int pop(struct Stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack Underflow\n");
        return -1;
    }
    return ptr->arr[ptr->top--];
}

/**
 * @brief Retrieves the value at a specific position in the stack without removing it.
 *
 * This function accesses the stack to return the value at the given position from the top.
 * The top position is considered position 1. If the specified position is out of range,
 * an error message is printed and -1 is returned.
 *
 * @param[in] ptr      The address of the stack.
 * @param[in] position The position from the top of the stack to retrieve the value from.
 *
 * @return The value at the specified position if valid, -1 if the position is out of range.
 */
int peep(struct Stack *ptr, int position)
{
    int arrayIndex = ptr->top - position + 1;
    if (arrayIndex < 0 || arrayIndex > ptr->top)
    {
        printf("Position is out of index\n");
        return -1;
    }
    return ptr->arr[arrayIndex];
}

/**
 * @brief Changes the value at the specified position in the stack.
 *
 * This function updates the value at the given position in the stack. The
 * top position is considered position 0. If the specified position is out of
 * range, an error message is printed and -1 is returned.
 *
 * @param[in] ptr      The address of the stack.
 * @param[in] index    The position from the top of the stack to change the value at.
 *
 * @return 0 on successful change, -1 if the position is out of range.
 */
int change(struct Stack *ptr, int index)
{
    if (index < 0 || index > ptr->top)
    {
        printf("Index out of range\n");
        return -1;
    }
    int value;
    printf("Enter the value to be changed at index %d: ", index);
    scanf("%d", &value);
    ptr->arr[index] = value;
    return 0;
}

int main()
{
    struct Stack s1;
    s1.size = 6;
    s1.arr = (int *)malloc(s1.size * sizeof(int));
    s1.top = -1;

    push(&s1, 1);
    push(&s1, 2);
    push(&s1, 3);
    push(&s1, 4);
    push(&s1, 5);
    push(&s1, 6);

    int poppedValue = pop(&s1);
    printf("Value Popped: %d\n", poppedValue);

    int valueAtPosition = peep(&s1, 2);
    printf("Value at position 2: %d\n", valueAtPosition);

    int changedValue = change(&s1, 1);
    printf("Value Changed\n");

    printf("Stack: ");
    for (int i = 0; i <= s1.top; i++)
    {
        printf("%d ", s1.arr[i]);
    }
    return 0;
}