#include <stdio.h>

// Function to perform Extended Euclidean Algorithm
int extendedEuclid(int a, int b, int* x, int* y) {
    if (b == 0) {
        *x = 1;
        *y = 0;
        return a;
    }

    int x1, y1;
    int gcd = extendedEuclid(b, a % b, &x1, &y1);

    *x = y1;
    *y = x1 - (a / b) * y1;

    return gcd;
}

int main() {
    int a, b, x, y;
    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);

    int gcd = extendedEuclid(a, b, &x, &y);
    printf("GCD of %d and %d is: %d\n", a, b, gcd);
    printf("Coefficients x and y such that ax + by = gcd:\n");
    printf("x = %d, y = %d\n", x, y);

    return 0;
}
