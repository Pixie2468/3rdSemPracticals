#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Stack
{
    int size;
    int top;
    int *arr;
};

bool isFull(struct Stack *ptr)
{
    return ptr->top == ptr->size - 1;
}

bool isEmpty(struct Stack *ptr)
{
    return ptr->top == -1;
}

int push(struct Stack *ptr, int value)
{
    if (isFull(ptr))
    {
        printf("Stack Overflow!\n");
        return -1;
    }
    ptr->arr[++ptr->top] = value;
    printf("Value Added\n");
    return 0;
}

int pop(struct Stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack Underflow\n");
        return -1;
    }
    return ptr->arr[ptr->top--];
}

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

int change(struct Stack *ptr, int index)
{
    if (index < 0 || index > ptr->top)
    {
        printf("Index out of range\n");
        return -1;
    }
    int value;
    printf("Enter the value: ");
    scanf("%d", &value);
    ptr->arr[index] = value;
    return 0;
}

void displayMenu(struct Stack *ptr)
{
    int choice = 0, position, value, index;
    while (choice != 6)
    {
        printf("\nEnter Your Choice\n1->Push\n2->Pop\n3->Peep\n4->Change\n5->Display\n6->Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the value: ");
            scanf("%d", &value);
            push(ptr, value);
            break;
        case 2:
            value = pop(ptr);
            if (value != -1)
                printf("Popped value: %d\n", value);
            break;
        case 3:
            printf("Enter the position of the element: ");
            scanf("%d", &position);
            value = peep(ptr, position);
            if (value != -1)
                printf("Value at position %d: %d\n", position, value);
            break;
        case 4:
            printf("Enter the index to change: ");
            scanf("%d", &index);
            change(ptr, index);
            break;

        case 5:
            for (int i = 0; i < ptr->top; i++)
            {
                printf("The Value at %d is %d\n", i, ptr->arr[i]);
            }
            break;
        case 6:
            break;
        default:
            printf("Incorrect Input!\n");
            break;
        }
    }
}

int main()
{
    int size, lenArray, value;
    printf("Enter the size of the stack: ");
    scanf("%d", &size);

    struct Stack *s1 = (struct Stack *)malloc(sizeof(struct Stack));
    if (s1 == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    s1->size = size;
    s1->top = -1;
    s1->arr = (int *)malloc(size * sizeof(int));
    if (s1->arr == NULL)
    {
        printf("Memory allocation failed\n");
        free(s1);
        return 1;
    }

    printf("Enter the number of elements to initialize (max %d): ", size);
    scanf("%d", &lenArray);

    if (lenArray > size)
    {
        printf("Error: Number of elements exceeds stack size\n");
        free(s1->arr);
        free(s1);
        return 1;
    }

    for (int i = 0; i < lenArray; i++)
    {
        printf("Enter the value at %d: ", i);
        scanf("%d", &value);
        push(s1, value);
    }

    displayMenu(s1);

    free(s1->arr);
    free(s1);
    return 0;
}