#include <stdio.h>
#include <stdlib.h>
#define MAXSZARR 50

int size;

/**
 * Displays the elements of the array in the format
 * "The value at index X = Y".
 *
 * @param arr the array to be displayed
 */
void display(int *arr)
{
    for (int i = 0; i < size; i++)
    {
        printf("The value at index %d = %d\n", i, arr[i]);
    }
}

/**
 * Inserts the value at the specified index in the array.
 *
 * @param arr the array to be inserted into
 * @param index the index at which the value is to be inserted
 */
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

/**
 * Searches the array for the given value and returns the index at which it is
 * found. If the value is not found, returns -1.
 *
 * @param arr the array to be searched
 * @param value the value to be searched for
 * @return the index at which the value is found, or -1 if the value is not found
 */
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

/**
 * Deletes the specified value from the array.
 * If the value is found, it is deleted and all elements to the right of it are
 * shifted to the left. If the value is not found, a message is printed to the
 * console.
 *
 * @param arr the array to be searched and modified
 * @param value the value to be deleted
 */
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
    size = 6;

    for (int i = 0; i < size; i++)
    {
        arr[i] = i + 1;
    }

    display(arr);

    insert(arr, 2);
    display(arr);

    search(arr, 3);

    delete (arr, 2);
    display(arr);
    return 0;
}