#include <stdio.h>
#include <math.h>

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

long long modExp(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}

int main() {
    int p, q;
    printf("Enter two prime numbers (p and q): ");
    scanf("%d %d", &p, &q);

    int n = p * q;
    int phi = (p - 1) * (q - 1);

    int e;
    for (e = 2; e < phi; e++) {
        if (gcd(e, phi) == 1) break;
    }

    int d;
    for (d = 1; d < phi; d++) {
        if ((d * e) % phi == 1) break;
    }

    printf("Public Key: {%d, %d}\n", e, n);
    printf("Private Key: {%d, %d}\n", d, n);

    int message;
    printf("Enter message (integer < %d): ", n);
    scanf("%d", &message);

    long long encrypted = modExp(message, e, n);
    long long decrypted = modExp(encrypted, d, n);

    printf("Encrypted message: %lld\n", encrypted);
    printf("Decrypted message: %lld\n", decrypted);

    return 0;
}
