#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void generateRandomKey(char *key, int length) {
    for (int i = 0; i < length; i++) {
        key[i] = 'A' + rand() % 26;
    }
    key[length] = '\0';
}

void encryptOTP(char *pt, char *key, char *ct) {
    for (int i = 0; pt[i] != '\0'; i++) {
        ct[i] = ((pt[i] - 'A') ^ (key[i] - 'A')) + 'A';
    }
    ct[strlen(pt)] = '\0';
}

void decryptOTP(char *ct, char *key, char *pt) {
    for (int i = 0; ct[i] != '\0'; i++) {
        pt[i] = ((ct[i] - 'A') ^ (key[i] - 'A')) + 'A';
    }
    pt[strlen(ct)] = '\0';
}

int main() {
    char pt[100], key[100], ct[100], decrypted[100];

    printf("Enter plaintext (A-Z only, no spaces): ");
    scanf("%s", pt);

    srand(time(0));
    generateRandomKey(key, strlen(pt));

    encryptOTP(pt, key, ct);
    decryptOTP(ct, key, decrypted);

    printf("Generated Key: %s\n", key);
    printf("Encrypted Text: %s\n", ct);
    printf("Decrypted Text: %s\n", decrypted);

    return 0;
}
