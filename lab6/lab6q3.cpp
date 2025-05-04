#include "q3.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>

class infix {
public:
    int precedence(char);
    int isOperator(char);
    void infixToPostfix(char*, char*);
    int evaluatePostfix(char*);
};

int main() {
    char infixExpr[100], postfixExpr[100];
    int choice;

    infix in;

    do {
        printf("\nMenu:\n");
        printf("1. Get Infix Expression\n");
        printf("2. Convert Infix to Postfix\n");
        printf("3. Evaluate Postfix Expression\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a valid infix expression: ");
                scanf("%s", infixExpr);
                break;
            case 2:
                in.infixToPostfix(infixExpr, postfixExpr);
                printf("Postfix Expression: %s\n", postfixExpr);
                break;
            case 3:
                printf("Result of Postfix Evaluation: %d\n", in.evaluatePostfix(postfixExpr));
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 4);

    freeStack();
    return 0;
}

int infix::precedence(char op) {
    switch (op) {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        case '=': return 0; // for assignment operator
        default: return -1;
    }
}

int infix::isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '=');
}

void infix::infixToPostfix(char* infix, char* postfix) {
    int j = 0;
    for (int i = 0; infix[i] != '\0'; i++) {
        if (isalnum(infix[i])) {
            postfix[j++] = infix[i];
        } else if (isOperator(infix[i])) {
            while (!isEmpty() && precedence(peek()) >= precedence(infix[i])) {
                postfix[j++] = pop();
            }
            push(infix[i]);
        }
    }
    while (!isEmpty()) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}

int infix::evaluatePostfix(char* postfix) {
    for (int i = 0; postfix[i] != '\0'; i++) {
        if (isdigit(postfix[i])) {
            push(postfix[i] - '0');
        } else if (isOperator(postfix[i])) {
            int val2 = pop();
            int val1 = pop();
            switch (postfix[i]) {
                case '+': push(val1 + val2); break;
                case '-': push(val1 - val2); break;
                case '*': push(val1 * val2); break;
                case '/': push(val1 / val2); break;
            }
        }
    }
    return pop();
}
