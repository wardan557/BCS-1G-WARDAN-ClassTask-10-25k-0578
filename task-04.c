#include <stdio.h>
#include <string.h>
void encrypt(char *message) {
	int i;
    for (i = 0; message[i] != '\0'; i++) {
        char ch = message[i];
        if (ch >= 'A' && ch <= 'Z') {
            message[i] = ((ch - 'A' + 3) % 26) + 'A';
        }
        else if (ch >= 'a' && ch <= 'z') {
            message[i] = ((ch - 'a' + 3) % 26) + 'a';
        }
    }
}
void decrypt(char *message) {
	int i;
    for (i = 0; message[i] != '\0'; i++) {
        char ch = message[i];
        if (ch >= 'A' && ch <= 'Z') {
            message[i] = ((ch - 'A' - 3 + 26) % 26) + 'A';
        }
        else if (ch >= 'a' && ch <= 'z') {
            message[i] = ((ch - 'a' - 3 + 26) % 26) + 'a';
        }
    }
}
int main() {
    char message[500];
    printf("Original: ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = '\0';
    char encrypted[500];
    strcpy(encrypted, message);
    encrypt(encrypted);
    printf("Encrypted: %s\n", encrypted);
    decrypt(encrypted);
    printf("Decrypted: %s\n", encrypted);
    return 0;
}

