#include <stdio.h>
#include <math.h>

// Function to compute (base^exp) % mod
long long powerMod(long long base, long long exp, long long mod) {
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
    long long p, g, a, b;
    
    // Publicly known prime number and primitive root
    printf("Enter prime number (p): ");
    scanf("%lld", &p);
    printf("Enter primitive root modulo p (g): ");
    scanf("%lld", &g);

    // Private keys for A and B
    printf("Enter private key for User A: ");
    scanf("%lld", &a);
    printf("Enter private key for User B: ");
    scanf("%lld", &b);

    // Public keys
    long long A = powerMod(g, a, p);
    long long B = powerMod(g, b, p);

    // Shared secret key
    long long secretA = powerMod(B, a, p);
    long long secretB = powerMod(A, b, p);

    printf("User A's Public Key: %lld\n", A);
    printf("User B's Public Key: %lld\n", B);
    printf("User A's Shared Secret: %lld\n", secretA);
    printf("User B's Shared Secret: %lld\n", secretB);

    if (secretA == secretB)
        printf("Key exchange successful! Shared key: %lld\n", secretA);
    else
        printf("Key exchange failed.\n");

    return 0;
}
