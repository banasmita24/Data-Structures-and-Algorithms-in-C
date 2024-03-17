#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>  // For isdigit()

#define MAX_SIZE 20

int stack[MAX_SIZE];
int top = -1;

int is_empty() {
    return top == -1;
}

int is_full() {
    return top == MAX_SIZE - 1;
}

void push(int element) {
    if (is_full()) {
        printf("Stack overflow\n");
        exit(1);  // Or handle overflow differently
    }
    stack[++top] = element;
}

int pop() {
    if (is_empty()) {
        printf("Stack underflow\n");
        exit(1);  // Or handle underflow differently
    }
    return stack[top--];
}

int calculate(char operator, int operand1, int operand2) {
    switch (operator) {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            if (operand2 == 0) {
                printf("Division by zero\n");
                exit(1);  // Or handle division by zero differently
            }
            return operand1 / operand2;
        default:
            printf("Invalid operator\n");
            exit(1);  // Or handle invalid operator differently
    }
}

int evaluate_postfix(char *postfix) {
    int i, operand1, operand2;

    // Check if expression starts with an operator (minimal validation)
    if (ispunct(postfix[0])) {
        printf("Expression cannot start with an operator\n");
        return -1;
    }

    for (i = 0; postfix[i] != '\0'; i++) {
        if (isdigit(postfix[i])) {
            push(postfix[i] - '0');  // Convert ASCII digit to integer
        } else {
            operand2 = pop();
            operand1 = pop();
            push(calculate(postfix[i], operand1, operand2));
        }
    }

    if (top != 0) {
        printf("Invalid postfix expression\n");
        return -1;
    }

    return stack[top];
}

int main() {
    char postfix[MAX_SIZE];
    int result;

    printf("Enter a valid postfix expression: ");
    scanf("%s", postfix);

    result = evaluate_postfix(postfix);

    if (result != -1) {  // Check for errors returned by evaluate_postfix
        printf("Result: %d\n", result);
    }

    return 0;
}
