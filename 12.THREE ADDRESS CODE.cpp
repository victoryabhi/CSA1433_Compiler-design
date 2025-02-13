#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;
char tempVar = 't';

void push(char c) {
    stack[++top] = c;
}

char pop() {
    return stack[top--];
}

int precedence(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    return 0;
}

void infixToPostfix(char *infix, char *postfix) {
    int i, j = 0;
    for (i = 0; infix[i] != '\0'; i++) {
        if (isalnum(infix[i])) {
            postfix[j++] = infix[i];
        } else if (infix[i] == '(') {
            push(infix[i]);
        } else if (infix[i] == ')') {
            while (top != -1 && stack[top] != '(')
                postfix[j++] = pop();
            pop(); // Remove '('
        } else {
            while (top != -1 && precedence(stack[top]) >= precedence(infix[i]))
                postfix[j++] = pop();
            push(infix[i]);
        }
    }
    while (top != -1)
        postfix[j++] = pop();
    postfix[j] = '\0';
}

void generateTAC(char *postfix) {
    char op1, op2;
    char result;
    char temp[MAX][10];
    int tempIndex = 0;

    for (int i = 0; postfix[i] != '\0'; i++) {
        if (isalnum(postfix[i])) {
            char str[2] = {postfix[i], '\0'};
            strcpy(temp[tempIndex++], str);
        } else {
            op2 = temp[--tempIndex][0];
            op1 = temp[--tempIndex][0];
            result = tempVar++;
            printf("%c = %c %c %c\n", result, op1, postfix[i], op2);
            snprintf(temp[tempIndex++], 10, "%c", result);
        }
    }
}

int main() {
    char infix[MAX], postfix[MAX];
    printf("Enter an infix expression: ");
    scanf("%s", infix);
    
    infixToPostfix(infix, postfix);
    printf("\nThree Address Code:\n");
    generateTAC(postfix);
    
    return 0;
}

