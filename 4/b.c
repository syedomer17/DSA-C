#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define SIZE 100

int stack[SIZE];
int top = -1;

// Push to stack
void push(int value) {
    stack[++top] = value;
}

// Pop from stack
int pop() {
    return stack[top--];
}

// Evaluate postfix expression
int evaluatePostfix(char* exp) {
    int i = 0;
    char c;

    while ((c = exp[i]) != '\0') {
        if (isdigit(c)) {
            push(c - '0'); // Convert char to int
        } else {
            int b = pop();
            int a = pop();

            switch (c) {
                case '+': push(a + b); break;
                case '-': push(a - b); break;
                case '*': push(a * b); break;
                case '/': push(a / b); break;
            }
        }
        i++;
    }

    return pop();
}

// Main
int main() {
    char postfix[SIZE];

    printf("Enter postfix expression (use single-digit numbers only): ");
    scanf("%s", postfix);

    int result = evaluatePostfix(postfix);
    printf("Result = %d\n", result);

    return 0;
}
