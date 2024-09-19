#include <stdio.h>
#include <stdlib.h>
#define MAXSZARR 50

int size;

void display(int *arr)
{
    for (int i = 0; i < size; i++)
    {
        printf("The value at index %d = %d\n", i, arr[i]);
    }
}

void insert(int *arr, int index)
{
    int value;
    printf("Enter the value to be inserted: ");
    scanf("%d", &value);
    for (int i = size; i > index; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[index] = value;
    size++;
}

int search(int *arr, int value)
{
    int i = 0;
    for (; i < size;)
    {
        if (arr[i] == value)
        {
            break;
        }
        else
        {
            i++;
        }
    }
    (i < size) ? (printf("Element Found At %d\n", i)) : (printf("Element Not Found!\n"));
    return (i < size) ? i : -1;
}

void delete(int *arr, int value)
{
    int index = search(arr, value);
    if (index == -1)
        printf("Value Not Found!\n");
    for (int i = index; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    size--;
    printf("Value Deleted\n");
}

int main()
{
    int *arr = (int *)malloc(MAXSZARR * sizeof(int));
    int choice;
    printf("Enter Size: ");
    scanf("%d", &size);
    for (int i = 0; i < size; i++)
    {
        printf("Enter the %d element: ", i);
        scanf("%d", &arr[i]);
    }

    while (choice != 5)
    {
        printf("Enter the Choice\n1->Display\n2->Insert\n3->Delete\n4->Search\n5->Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            display(arr);
        }
        break;
        case 2:
        {
            int index;
            printf("Enter the Index: ");
            scanf("%d", &index);
            insert(arr, index);
        }
        break;
        case 3:
        {
            int value;
            printf("Enter the Value: ");
            scanf("%d", &value);
            delete (arr, value);
        }
        break;
        case 4:
        {
            int value;
            printf("Enter the value to search: ");
            scanf("%d", &value);
            search(arr, value);
        }
        break;
        case 5:
            break;
        default:
            printf("Incorrect Input!");
            break;
        }
    }
    return 0;
}