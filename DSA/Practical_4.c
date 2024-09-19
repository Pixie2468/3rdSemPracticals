#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX 100

struct Stack
{
    int top;
    char *arr;
};

bool isEmpty(struct Stack *ptr)
{
    return ptr->top == -1;
}

bool isFull(struct Stack *ptr)
{
    return ptr->top == MAX - 1;
}

bool isOperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

void push(struct Stack *ptr, char ch)
{
    if (isFull(ptr))
    {
        printf("Stack Overflow\n");
        return;
    }
    ptr->arr[++ptr->top] = ch;
}

char pop(struct Stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack Underflow\n");
        return '\0';
    }
    return ptr->arr[ptr->top--];
}

int precedence(char operator)
{
    switch (operator)
    {
    case '*':
    case '/':
        return 2;
    case '+':
    case '-':
        return 1;
    default:
        return 0;
    }
}

char *infixToPostfix(struct Stack *ptr, char *equation)
{
    char temp;
    static char ans[MAX];
    int j = 0;
    for (int i = 0; equation[i] != '\0'; i++)
    {
        temp = equation[i];
        if (isalnum(temp))
        {
            ans[j++] = temp;
        }
        else if (isOperator(temp) || temp == '(')
        {
            if (isEmpty(ptr) || precedence(temp) > precedence(ptr->arr[ptr->top]) || temp == '(')
            {
                push(ptr, temp);
            }
            else
            {
                while (!isEmpty(ptr) && ptr->arr[ptr->top] != '(' && precedence(temp) <= precedence(ptr->arr[ptr->top]))
                {
                    ans[j++] = pop(ptr);
                }
                push(ptr, temp);
            }
        }
        else if (temp == ')')
        {
            while (!isEmpty(ptr) && ptr->arr[ptr->top] != '(')
            {
                ans[j++] = pop(ptr);
            }
            if (!isEmpty(ptr) && ptr->arr[ptr->top] == '(')
            {
                pop(ptr);
            }
        }
    }
    while (!isEmpty(ptr))
    {
        ans[j++] = pop(ptr);
    }
    ans[j] = '\0';
    return ans;
}

int main()
{
    struct Stack s1;
    s1.arr = (char *)malloc(MAX * sizeof(char));
    s1.top = -1;
    char infix[] = "(9+4*(4/8*9)/0)";
    printf("Infix: %s\n", infix);
    printf("Postfix: %s\n", infixToPostfix(&s1, infix));
    free(s1.arr);
    return 0;
}