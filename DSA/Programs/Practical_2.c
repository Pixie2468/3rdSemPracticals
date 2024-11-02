#include <stdio.h>
#include <stdlib.h>

/**
 * Swaps the values of two integers using XOR operator by value.
 * @param a first integer
 * @param b second integer
 */
void callByValue(int a, int b)
{
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}
/**
 * Swaps the values of two integers using pointer parameters by reference.
 * @param a pointer to first integer
 * @param b pointer to second integer
 */
void callByReference(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int a = 4, b = 5;

    callByValue(a, b);
    printf("a = %d, b = %d\n", a, b);

    callByReference(&a, &b);
    printf("a = %d, b = %d\n", a, b);

    return 0;
}