#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void encryptRailFence(char *text, int rails, char *result) {
    int len = strlen(text);
    char rail[rails][len];
    
    // Fill with null chars
    for (int i = 0; i < rails; i++)
        for (int j = 0; j < len; j++)
            rail[i][j] = '\n';

    int row = 0;
    bool down = false;

    for (int i = 0; i < len; i++) {
        rail[row][i] = text[i];

        if (row == 0 || row == rails - 1)
            down = !down;

        row += down ? 1 : -1;
    }

    // Read row-wise
    int idx = 0;
    for (int i = 0; i < rails; i++)
        for (int j = 0; j < len; j++)
            if (rail[i][j] != '\n')
                result[idx++] = rail[i][j];
    result[idx] = '\0';
}

void decryptRailFence(char *cipher, int rails, char *result) {
    int len = strlen(cipher);
    char rail[rails][len];

    for (int i = 0; i < rails; i++)
        for (int j = 0; j < len; j++)
            rail[i][j] = '\n';

    int row = 0;
    bool down = false;

    // Mark the positions
    for (int i = 0; i < len; i++) {
        rail[row][i] = '*';

        if (row == 0 || row == rails - 1)
            down = !down;

        row += down ? 1 : -1;
    }

    // Fill with cipher characters
    int idx = 0;
    for (int i = 0; i < rails; i++)
        for (int j = 0; j < len; j++)
            if (rail[i][j] == '*')
                rail[i][j] = cipher[idx++];

    // Read in zigzag
    row = 0;
    down = false;
    idx = 0;

    for (int i = 0; i < len; i++) {
        result[idx++] = rail[row][i];

        if (row == 0 || row == rails - 1)
            down = !down;

        row += down ? 1 : -1;
    }
    result[idx] = '\0';
}

int main() {
    char text[100], encrypted[100], decrypted[100];
    int rails;

    printf("Enter plaintext: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';

    printf("Enter number of rails: ");
    scanf("%d", &rails);

    encryptRailFence(text, rails, encrypted);
    printf("Encrypted text: %s\n", encrypted);

    decryptRailFence(encrypted, rails, decrypted);
    printf("Decrypted text: %s\n", decrypted);

    return 0;
}
