#include <stdio.h>

// Function to compute GCD using Euclidean Algorithm
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int num1, num2;
    
    // Input two numbers
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);
    
    // Compute and display the GCD
    printf("The GCD of %d and %d is %d.\n", num1, num2, gcd(num1, num2));
    
    return 0;
}
