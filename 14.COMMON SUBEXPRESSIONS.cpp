#include <stdio.h>

int main() {
    int a, b, c, d, x, y;
    
    // Input values from user
    printf("Enter values for a, b, c, and d: ");
    scanf("%d %d %d %d", &a, &b, &c, &d);
    
    // Before optimization: Recomputing (a + b) twice
    x = (a + b) * c;
    y = (a + b) * d;
    
    printf("Before optimization:\n");
    printf("x = %d, y = %d\n", x, y);
    
    // After optimization: Eliminating common subexpression
    int temp = a + b;
    x = temp * c;
    y = temp * d;
    
    printf("After optimization:\n");
    printf("x = %d, y = %d\n", x, y);
    
    return 0;
}

