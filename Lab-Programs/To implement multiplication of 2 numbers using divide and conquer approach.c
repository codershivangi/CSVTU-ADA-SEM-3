#include <stdio.h>
#include <math.h>

// Function to calculate the Karatsuba product of two integers
long long karatsuba(long long x, long long y) {
    // Base case for recursion: when the number is small enough
    if (x < 10 || y < 10)
        return x * y;

    // Calculate the size of the numbers
    int n = fmax(log10(x) + 1, log10(y) + 1);
    int m = n / 2;

    // Split the digit sequences at the middle
    long long high1 = x / pow(10, m);
    long long low1 = x % (long long)pow(10, m);
    long long high2 = y / pow(10, m);
    long long low2 = y % (long long)pow(10, m);

    // 3 recursive calls
    long long z0 = karatsuba(low1, low2);  // z0 = low1 * low2
    long long z1 = karatsuba(low1 + high1, low2 + high2);  // z1 = (low1 + high1) * (low2 + high2)
    long long z2 = karatsuba(high1, high2);  // z2 = high1 * high2

    // Combine the results using the Karatsuba formula
    return z2 * pow(10, 2 * m) + (z1 - z2 - z0) * pow(10, m) + z0;
}

int main() {
    long long x, y;
    
    // Input two numbers to multiply
    printf("Enter first number: ");
    scanf("%lld", &x);
    printf("Enter second number: ");
    scanf("%lld", &y);
    
    // Compute the product using Karatsuba multiplication
    long long result = karatsuba(x, y);
    
    // Output the result
    printf("The product is: %lld\n", result);
    
    return 0;
}
