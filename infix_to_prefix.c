#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// function to return precedence of operators
int precedence(char c) {
    if (c == '^') return 3;
    else if (c == '*' || c == '/') return 2;
    else if (c == '+' || c == '-') return 1;
    else return -1;
}

// function to check if operator is right-associative
int isRightAssociative(char c) {
    return c == '^';
}

// function to check if a character is an operator
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// function to convert infix expression to prefix
char* infixToPrefix(char* s) {
    int n = strlen(s);
    char* result = (char*)malloc(n * 2); 
    int resIndex = 0;
    char st[100];
    int top = -1;

    // scan from right to left
    for (int i = n - 1; i >= 0; i--) {
        char c = s[i];

        if (isalnum(c)) {
            result[resIndex++] = c;
        }
        else if (c == ')') {
            st[++top] = c;
        }
        else if (c == '(') {
            while (top != -1 && st[top] != ')') {
                result[resIndex++] = st[top--];
            }
            if (top != -1) top--; // pop ')'
        }
        else if (isOperator(c)) {
            while (top != -1 && isOperator(st[top]) &&
                  (precedence(st[top]) > precedence(c) ||
                  (precedence(st[top]) == precedence(c) && isRightAssociative(c)))) {
                result[resIndex++] = st[top--];
            }
            st[++top] = c;
        }
    }

    // pop remaining operators
    while (top != -1) {
        result[resIndex++] = st[top--];
    }

    result[resIndex] = '\0';

    // reverse at the end to get correct prefix
    for (int i = 0; i < resIndex / 2; i++) {
        char temp = result[i];
        result[i] = result[resIndex - i - 1];
        result[resIndex - i - 1] = temp;
    }

    return result;
}

int main() {
    char s[] = "a*(b+c)/d";
    char* prefix = infixToPrefix(s);
    printf("%s\n", prefix);
    return 0;
}