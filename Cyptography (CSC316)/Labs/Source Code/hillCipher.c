#include <stdio.h>
#include <string.h>

void getKeyMatrix(char key[], int keyMatrix[2][2]) {
    int k = 0;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            keyMatrix[i][j] = key[k++] % 65;
}

void encrypt(char message[], int keyMatrix[2][2], int cipherMatrix[2]) {
    for (int i = 0; i < 2; i++) {
        cipherMatrix[i] = 0;
        for (int j = 0; j < 2; j++)
            cipherMatrix[i] += keyMatrix[i][j] * (message[j] % 65);
        cipherMatrix[i] = cipherMatrix[i] % 26;
    }
}

void hillCipher(char message[], char key[]) {
    int keyMatrix[2][2];
    int cipherMatrix[2];
    char cipherText[3];

    getKeyMatrix(key, keyMatrix);
    encrypt(message, keyMatrix, cipherMatrix);

    for (int i = 0; i < 2; i++)
        cipherText[i] = cipherMatrix[i] + 65;

    cipherText[2] = '\0';

    printf("Encrypted text: %s\n", cipherText);
}

int main() {
    char message[3], key[5];

    printf("Enter 2-letter plaintext (in uppercase): ");
    scanf("%s", message);

    printf("Enter 4-letter key (2x2 matrix) (in uppercase): ");
    scanf("%s", key);

    hillCipher(message, key);

    return 0;
}
