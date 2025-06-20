#include <stdio.h>
#include <string.h>
#include <ctype.h>

char keyMatrix[5][5];

void prepareMatrix(char key[]) {
    int dict[26] = {0};
    int i, j, k = 0;
    char ch;

    for (i = 0; key[i]; i++) {
        ch = toupper(key[i]);
        if (ch == 'J') ch = 'I';
        if (!dict[ch - 'A'] && ch >= 'A' && ch <= 'Z') {
            dict[ch - 'A'] = 1;
            keyMatrix[k / 5][k % 5] = ch;
            k++;
        }
    }

    for (ch = 'A'; ch <= 'Z'; ch++) {
        if (ch == 'J') continue;
        if (!dict[ch - 'A']) {
            keyMatrix[k / 5][k % 5] = ch;
            k++;
        }
    }
}

void formatText(char in[], char out[]) {
    int i, j = 0;
    for (i = 0; in[i]; i++) {
        char ch = toupper(in[i]);
        if (ch < 'A' || ch > 'Z') continue;
        if (ch == 'J') ch = 'I';
        out[j++] = ch;
    }
    out[j] = '\0';

    for (i = 0; i < j; i += 2) {
        if (out[i] == out[i + 1]) {
            for (int k = j; k > i + 1; k--)
                out[k] = out[k - 1];
            out[i + 1] = 'X';
            j++;
        }
    }
    if (j % 2 != 0)
        out[j++] = 'X';
    out[j] = '\0';
}

void findPosition(char ch, int *row, int *col) {
    int i, j;
    if (ch == 'J') ch = 'I';
    for (i = 0; i < 5; i++)
        for (j = 0; j < 5; j++)
            if (keyMatrix[i][j] == ch) {
                *row = i;
                *col = j;
                return;
            }
}

void encryptPlayfair(char pt[], char ct[]) {
    int i, row1, col1, row2, col2;
    for (i = 0; pt[i]; i += 2) {
        findPosition(pt[i], &row1, &col1);
        findPosition(pt[i + 1], &row2, &col2);
        if (row1 == row2) {
            ct[i] = keyMatrix[row1][(col1 + 1) % 5];
            ct[i + 1] = keyMatrix[row2][(col2 + 1) % 5];
        } else if (col1 == col2) {
            ct[i] = keyMatrix[(row1 + 1) % 5][col1];
            ct[i + 1] = keyMatrix[(row2 + 1) % 5][col2];
        } else {
            ct[i] = keyMatrix[row1][col2];
            ct[i + 1] = keyMatrix[row2][col1];
        }
    }
    ct[i] = '\0';
}

void decryptPlayfair(char ct[], char pt[]) {
    int i, row1, col1, row2, col2;
    for (i = 0; ct[i]; i += 2) {
        findPosition(ct[i], &row1, &col1);
        findPosition(ct[i + 1], &row2, &col2);
        if (row1 == row2) {
            pt[i] = keyMatrix[row1][(col1 + 4) % 5];
            pt[i + 1] = keyMatrix[row2][(col2 + 4) % 5];
        } else if (col1 == col2) {
            pt[i] = keyMatrix[(row1 + 4) % 5][col1];
            pt[i + 1] = keyMatrix[(row2 + 4) % 5][col2];
        } else {
            pt[i] = keyMatrix[row1][col2];
            pt[i + 1] = keyMatrix[row2][col1];
        }
    }
    pt[i] = '\0';
}

int main() {
    char key[100], plaintext[100], formatted[100], ciphertext[100], decrypted[100];

    printf("Enter key: ");
    scanf("%s", key);
    prepareMatrix(key);

    printf("Enter plaintext: ");
    scanf("%s", plaintext);

    formatText(plaintext, formatted);
    encryptPlayfair(formatted, ciphertext);
    decryptPlayfair(ciphertext, decrypted);

    printf("Formatted Plaintext: %s\n", formatted);
    printf("Encrypted: %s\n", ciphertext);
    printf("Decrypted: %s\n", decrypted);

    return 0;
}
