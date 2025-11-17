#include <stdio.h>
#include <string.h>
#include <ctype.h>

int is_vowel(char ch) {
    ch = tolower(ch);
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

int main() {
    char text[200];
    printf("Enter text: ");
    fgets(text, sizeof(text), stdin);

    // Remove newline
    text[strcspn(text, "\n")] = '\0';

    int vowels = 0, consonants = 0, digits = 0, spaces = 0;
    int i;
    for (i = 0; text[i] != '\0'; i++) {
        char ch = text[i];

        if (isalpha(ch)) {
            if (is_vowel(ch))
                vowels++;
            else
                consonants++;
        } else if (isdigit(ch)) {
            digits++;
        } else if (isspace(ch)) {
            spaces++;
        }
        // punctuation ignored
    }

    int total_chars = strlen(text); // counts exactly typed characters

    printf("\nStatistics:\n");
    printf("Vowels: %d\n", vowels);
    printf("Consonants: %d\n", consonants);
    printf("Digits: %d\n", digits);
    printf("Spaces: %d\n", spaces);
    printf("Total characters: %d\n", total_chars);

    return 0;
}

