#include <stdio.h>
#include <stdbool.h>

/**
 * Swaps the values of two integers using a temporary variable.
 *
 * @param a pointer to first integer
 * @param b pointer to second integer
 */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * Sorts an array of integers in ascending order using an optimized Bubble Sort algorithm.
 *
 * This function iteratively compares adjacent elements in the array and swaps them
 * if they are in the wrong order. The process repeats until no more swaps are needed,
 * indicating that the array is sorted. It includes optimizations for already sorted
 * arrays and uses pointer arithmetic for faster access.
 *
 * @param arr An array of integers to be sorted.
 * @param size The number of elements in the array.
 */
void bubbleSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        bool swapped = false;
        int *ptr = arr;

        for (int j = 0; j < size - i - 1; j++, ptr++)
        {
            if (*ptr > *(ptr + 1))
            {
                swap(ptr, ptr + 1);
                swapped = true;
            }
        }

        if (!swapped)
        {
            break;
        }
    }
}

/**
 * Searches an array of integers for a target element using Binary Search.
 *
 * This function searches an array of integers for a target element using
 * Binary Search. It assumes the array is already sorted in ascending order.
 * It returns the index of the target element if found, or -1 if not found.
 *
 * @param arr An array of integers to be searched.
 * @param size The number of elements in the array.
 * @param target The element to be searched for.
 * @return The index of the target element if found, or -1 if not found.
 */
int binarySearch(int arr[], int size, int target)
{
    int left = 0;
    int right = size - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
        {
            return mid;
        }

        if (arr[mid] > target)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    return -1;
}

/**
 * Prints the elements of an array in the format "Array: X Y Z..."
 *
 * @param arr An array of integers to be printed.
 * @param size The number of elements in the array.
 */
void printArray(const int arr[], int size)
{
    printf("Array: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[] = {10, 7, 8, 9, 1, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 5;

    printf("Original ");
    printArray(arr, size);

    // Sort array
    bubbleSort(arr, size);
    printf("Sorted ");
    printArray(arr, size);

    // Search for target
    int result = binarySearch(arr, size, target);

    if (result != -1)
    {
        printf("Element %d found at index %d\n", target, result);
    }
    else
    {
        printf("Element %d not found in array\n", target);
    }

    return 0;
}