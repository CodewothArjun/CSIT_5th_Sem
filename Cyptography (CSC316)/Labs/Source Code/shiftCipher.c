#include <stdio.h>
#include <string.h>

void shiftCipher(char text[], int shift) {
    for (int i = 0; text[i] != '\0'; i++) {
        char ch = text[i];
        if (ch >= 'A' && ch <= 'Z') {
            text[i] = (ch - 'A' + shift) % 26 + 'A';
        } else if (ch >= 'a' && ch <= 'z') {
            text[i] = (ch - 'a' + shift) % 26 + 'a';
        }
    }
}

void decryptShift(char text[], int shift) {
    shiftCipher(text, 26 - shift);
}

int main() {
    char text[100];
    int shift;
    printf("Enter Message: ");
    scanf("%s", &text);
    printf("Enter shift key: ");
    scanf("%d", &shift);

    printf("Original Text: %s\n", text);
    shiftCipher(text, shift);
    printf("Encrypted Text: %s\n", text);
    decryptShift(text, shift);
    printf("Decrypted Text: %s\n", text);
    return 0;
}