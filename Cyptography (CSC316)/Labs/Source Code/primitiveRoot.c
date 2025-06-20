#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int isPrime(int n) {
    if (n <= 1) return 0;
    for (int i = 2; i*i <= n; i++)
        if (n % i == 0) return 0;
    return 1;
}

int powerMod(int base, int exp, int mod) {
    int result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}

void findPrimeFactors(int n, int factors[], int *count) {
    *count = 0;
    if (n % 2 == 0) {
        factors[(*count)++] = 2;
        while (n % 2 == 0) n /= 2;
    }
    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) {
            factors[(*count)++] = i;
            while (n % i == 0) n /= i;
        }
    }
    if (n > 2)
        factors[(*count)++] = n;
}

int isPrimitiveRoot(int g, int p, int phi, int factors[], int count) {
    for (int i = 0; i < count; i++) {
        if (powerMod(g, phi / factors[i], p) == 1)
            return 0;
    }
    return 1;
}

int main() {
    int p;
    printf("Enter a prime number: ");
    scanf("%d", &p);

    if (!isPrime(p)) {
        printf("Number is not prime.\n");
        return 0;
    }

    int phi = p - 1;
    int factors[20], count;

    findPrimeFactors(phi, factors, &count);

    printf("Primitive roots of %d are: ", p);
    for (int g = 2; g < p; g++) {
        if (isPrimitiveRoot(g, p, phi, factors, count)) {
            printf("%d ", g);
        }
    }
    printf("\n");
    return 0;
}
