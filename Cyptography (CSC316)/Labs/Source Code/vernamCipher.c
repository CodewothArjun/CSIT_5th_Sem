#include <stdio.h>
#include <string.h>

void encryptVernam(char pt[], char key[], char ct[]) {
    for (int i = 0; pt[i] != '\0'; i++) {
        ct[i] = ((pt[i] - 'A') ^ (key[i] - 'A')) + 'A';
    }
    ct[strlen(pt)] = '\0';
}

void decryptVernam(char ct[], char key[], char pt[]) {
    for (int i = 0; ct[i] != '\0'; i++) {
        pt[i] = ((ct[i] - 'A') ^ (key[i] - 'A')) + 'A';
    }
    pt[strlen(ct)] = '\0';
}

int main() {
    char plaintext[100], key[100], ciphertext[100], decrypted[100];

    printf("Enter plaintext (A-Z only): ");
    scanf("%s", plaintext);

    printf("Enter key (same length as plaintext): ");
    scanf("%s", key);

    if (strlen(plaintext) != strlen(key)) {
        printf("Error: Key and plaintext must be of same length.\n");
        return 1;
    }

    encryptVernam(plaintext, key, ciphertext);
    printf("Encrypted Text: %s\n", ciphertext);

    decryptVernam(ciphertext, key, decrypted);
    printf("Decrypted Text: %s\n", decrypted);

    return 0;
}
