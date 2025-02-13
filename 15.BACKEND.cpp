#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// Function to generate simple assembly code
void generateAssembly(char *expr) {
    printf("Generated Assembly Code:\n");
    char *token = strtok(expr, " ");
    int reg = 0;
    while (token != NULL) {
        if (isdigit(token[0])) {
            printf("MOV R%d, %s\n", reg, token);
        } else if (strcmp(token, "+") == 0) {
            reg--;
            printf("ADD R%d, R%d\n", reg, reg + 1);
        } else if (strcmp(token, "-") == 0) {
            reg--;
            printf("SUB R%d, R%d\n", reg, reg + 1);
        } else if (strcmp(token, "*") == 0) {
            reg--;
            printf("MUL R%d, R%d\n", reg, reg + 1);
        } else if (strcmp(token, "/") == 0) {
            reg--;
            printf("DIV R%d, R%d\n", reg, reg + 1);
        } else {
            printf("Invalid Token: %s\n", token);
        }
        token = strtok(NULL, " ");
        reg++;
    }
}

int main() {
    char expr[100];
    printf("Enter a simple arithmetic expression in postfix notation (e.g., 3 4 + 5 *): ");
    fgets(expr, sizeof(expr), stdin);
    expr[strcspn(expr, "\n")] = 0;  // Remove newline character
    generateAssembly(expr);
    return 0;
}

