#include <stdio.h>
#include <stdlib.h>

void callByValue(int a, int b)
{
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}
void callByReference(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int a, b;
    printf("Enter the first number: ");
    scanf("%d", &a);
    printf("Enter the second number: ");
    scanf("%d", &b);
    callByValue(a, b);
    printf("Values of a and b after Call by Value: a = %d, b = %d\n", a, b);
    callByReference(&a, &b);
    printf("Values of a and b after Call by Reference: a = %d, b = %d", a, b);
    return 0;
}
