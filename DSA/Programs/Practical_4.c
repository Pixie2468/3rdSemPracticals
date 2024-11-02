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

/**
 * @brief Checks if the stack is empty.
 *
 * This function determines whether the stack is empty by checking
 * if the top index is at its initial position (-1).
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
 * @brief Checks if the stack is full.
 *
 * This function determines whether the stack is full by
 * comparing the top index with the maximum allowed size.
 *
 * @param[in] ptr  The address of the struct Stack.
 *
 * @return true if the stack is full, false otherwise.
 */
bool isFull(struct Stack *ptr)
{
    return ptr->top == MAX - 1;
}

/**
 * @brief Checks if the character is an operator.
 *
 * This function checks if the given character is one of the four
 * basic arithmetic operators (+, -, *, /). If it is, true is returned;
 * otherwise, false is returned.
 *
 * @param[in] ch  The character to be checked.
 *
 * @return true if the character is an operator, false otherwise.
 */
bool isOperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

/**
 * @brief Pushes a character onto the stack.
 *
 * This function adds a new character to the top of the stack. If the stack
 * is full, it prints an error message and does not perform the push operation.
 *
 * @param[in] ptr The address of the struct Stack.
 * @param[in] ch  The character to be pushed onto the stack.
 */
void push(struct Stack *ptr, char ch)
{
    if (isFull(ptr))
    {
        printf("Stack Overflow\n");
        return;
    }
    ptr->arr[++ptr->top] = ch;
}

/**
 * @brief Removes the top element from the stack.
 *
 * This function removes the top element from the stack. If the stack is
 * empty, it prints an error message and returns the null character.
 *
 * @param[in] ptr The address of the struct Stack.
 *
 * @return The popped character if the stack is not empty, the null
 * character if the stack is empty.
 */
char pop(struct Stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack Underflow\n");
        return '\0';
    }
    return ptr->arr[ptr->top--];
}

/**
 * @brief Gets the precedence of the operator.
 *
 * This function takes a character operator as input and returns an integer
 * representing its precedence. The precedence is as follows: * and / have
 * precedence 2, + and - have precedence 1, and all other characters have
 * precedence 0.
 *
 * @param[in] operator The operator to get the precedence of.
 *
 * @return The precedence of the operator.
 */
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

/**
 * @brief Converts an infix expression into a postfix expression.
 *
 * This function takes a infix expression, uses a stack to store the operators and
 * parentheses, and then prints the postfix expression.
 *
 * @param[in] ptr      The address of the struct Stack.
 * @param[in] equation The infix expression to be converted.
 *
 * @return The converted postfix expression.
 */
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