#include <stdio.h>
#include <ctype.h>  // For isalpha() and isdigit()

#define SIZE 100

char stack[SIZE];
int top = -1;

// Push to stack
void push(char c) {
    stack[++top] = c;
}

// Pop from stack
char pop() {
    return stack[top--];
}

// Peek top of stack
char peek() {
    return stack[top];
}

// Check if operator
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Get operator precedence
int precedence(char op) {
    if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return 0;
}

// Convert infix to postfix
void infixToPostfix(char infix[]) {
    char postfix[SIZE];
    int i = 0, j = 0;
    char c;

    while ((c = infix[i++]) != '\0') {
        if (isalnum(c)) {
            postfix[j++] = c;  // Operand goes directly to output
        } else if (c == '(') {
            push(c);
        } else if (c == ')') {
            while (top != -1 && peek() != '(')
                postfix[j++] = pop();
            pop(); // Remove '('
        } else if (isOperator(c)) {
            while (top != -1 && precedence(peek()) >= precedence(c))
                postfix[j++] = pop();
            push(c);
        }
    }

    while (top != -1)  // Pop any remaining operators
        postfix[j++] = pop();

    postfix[j] = '\0';  // Null terminate
    printf("Postfix Expression: %s\n", postfix);
}

// Main
int main() {
    char infix[SIZE];

    printf("Enter an infix expression (no spaces): ");
    scanf("%s", infix);

    infixToPostfix(infix);

    return 0;
}
