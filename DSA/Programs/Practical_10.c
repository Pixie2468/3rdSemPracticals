#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * Swaps the values of two integers using XOR operator.
 * @param n1 pointer to first integer
 * @param n2 pointer to second integer
 */
void swap(int *n1, int *n2)
{
    int temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

/**
 * Sorts an array of integers in ascending order using the Bubble Sort algorithm.
 *
 * This function iteratively compares adjacent elements in the array and swaps them
 * if they are in the wrong order. The process repeats until no more swaps are needed,
 * indicating that the array is sorted.
 *
 * @param arr Pointer to the array of integers to be sorted.
 * @param size The number of elements in the array.
 */
void bubbleSort(int *arr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        bool swapped = false;
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            return;
    }
}

/**
 * Sorts an array of integers in ascending order using the Quick Sort algorithm.
 *
 * This function recursively divides the array into two parts based on a pivot
 * element, and then recursively sorts the two parts. The pivot element is chosen
 * as the middle element of the current range. The function swaps elements in the
 * array to ensure that elements smaller than the pivot are on the left of the
 * pivot, and elements larger than the pivot are on the right.
 *
 * @param arr Pointer to the array of integers to be sorted.
 * @param low The lowest index in the current range of the array to be sorted.
 * @param high The highest index in the current range of the array to be sorted.
 */
void quick_sort(int arr[], int low, int high)
{
    while (low < high)
    {
        // Use middle element as pivot
        int pivot = arr[(low + high) / 2];
        int i = low - 1;
        int j = high + 1;

        while (1)
        {
            while (arr[++i] < pivot)
                ;
            while (arr[--j] > pivot)
                ;
            if (i >= j)
                break;
            swap(&arr[i], &arr[j]);
        }

        // Recurse on smaller part, iterate on larger part
        if (j - low < high - j)
        {
            quick_sort(arr, low, j);
            low = j + 1;
        }
        else
        {
            quick_sort(arr, j + 1, high);
            high = j;
        }
    }
}

/**
 * Merges two subarrays of arr[] into a single sorted subarray.
 *
 * This function takes two subarrays defined by indices [low..mid] and [mid+1..high],
 * and merges them into a single sorted subarray. It uses temporary arrays to store
 * the elements of each subarray and merges them back into the original array in
 * sorted order.
 *
 * @param arr  The original array containing the subarrays to merge.
 * @param low  The starting index of the first subarray.
 * @param mid  The ending index of the first subarray and the starting index of the second subarray minus one.
 * @param high The ending index of the second subarray.
 */
void merge(int arr[], int low, int mid, int high)
{
    int i = 0, j = 0, k = low;
    int n1 = mid - low + 1;
    int n2 = high - mid;

    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++)
        L[i] = arr[low + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    while (i < n1 && j < n2)
    {
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];

    free(L);
    free(R);
}

/**
 * Sorts an array of integers in ascending order using the Merge Sort algorithm.
 *
 * This function recursively divides the array into two halves until each
 * subarray contains only one element. It then merges the subarrays in sorted
 * order, using the merge function to combine each pair of subarrays.
 *
 * @param arr  The array of integers to be sorted.
 * @param low  The starting index of the subarray to be sorted.
 * @param high The ending index of the subarray to be sorted.
 */
void merge_sort(int arr[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

int main()
{
    int arr[] = {10, 7, 8, 9, 1, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Bubble Sort: ");
    bubbleSort(arr, size);
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\nQuick Sort: ");
    quick_sort(arr, 0, size - 1);
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\nMerge Sort: ");
    merge_sort(arr, 0, size - 1);
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}