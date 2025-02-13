#include <stdio.h>
#include <math.h>

// Function to evaluate basic operations
float evaluate_expression(float a, char op, float b) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        case '^': return pow(a, b);
        default: return 0;
    }
}

int main() {
    float a, b, c, result1, result2;
    char op1, op2;
    
    // Taking input from user
    printf("Enter first number: ");
    scanf("%f", &a);
    
    printf("Enter first operator (+, -, *, /, ^): ");
    scanf(" %c", &op1);
    
    printf("Enter second number: ");
    scanf("%f", &b);
    
    printf("Enter second operator (+, -, *, /, ^): ");
    scanf(" %c", &op2);
    
    printf("Enter third number: ");
    scanf("%f", &c);
    
    // Evaluating the expression following precedence
    result1 = evaluate_expression(b, op2, c);
    result2 = evaluate_expression(a, op1, result1);
    
    // Displaying the result
    printf("Result: %.2f\n", result2);
    
    return 0;
}

