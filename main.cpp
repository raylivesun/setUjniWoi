#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>


// Function to validate the input string
bool isValidString(const char* str) {
    if (str == NULL) {
        return false;
    }

    for (size_t i = 0; i < strlen(str); i++) {
        if (!isalnum(str[i]) && str[i] != ' ') {
            return false;
        }
    }

    return true;
}

// Function to calculate the sum of vowels and consonants
void countVowelsAndConsonants(const char* str, int* vowelCount, int* consonantCount) {
    if (str == NULL || vowelCount == NULL || consonantCount == NULL) {
        return;
    }

    *vowelCount = 0;
    *consonantCount = 0;

    for (size_t i = 0; i < strlen(str); i++) {
        char c = tolower(str[i]);

        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            (*vowelCount)++;
        } else if (isalpha(c) && c != ' ') {
            (*consonantCount)++;
        }
    }
}

// Function to replace vowels with their next consonant
void replaceVowelsWithNextConsonant(char* str) {
    if (str == NULL) {
        return;
    }

    for (size_t i = 0; i < strlen(str); i++) {
        char c = tolower(str[i]);

        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            char nextConsonant = 'a';

            for (size_t j = 0; j < strlen(str); j++) {
                if (tolower(str[j]) != 'a' && tolower(str[j]) != 'e' && tolower(str[j]) != 'i' && tolower(str[j]) != 'o' && tolower(str[j]) != 'u') {
                    nextConsonant = tolower(str[j]);
                    break;
                }
            
                if (j == strlen(str) - 1) {
                    nextConsonant = 'a';
                }
                if (tolower(str[i]) == nextConsonant) {
                    str[i] = toupper(nextConsonant);
                    break;
                }
            }
            if (tolower(str[i]) == 'u') {
                str[i] = toupper('a');
            }
            if (tolower(str[i]) == 'y') {
                str[i] = toupper('a');
            }
            if (tolower(str[i]) == 'w') {
                str[i] = toupper('a');
            }
        }
        if (c == ' ') {
            str[i] = '_';
        }
        if (c == 'q' && str[i + 1] == 'u') {
            str[i] = 'u';
            str[i + 1] = 'a';
            i++;
        }
        if (c == 'z') {
            str[i] = 'b';
        }
    }
    str[strlen(str)] = '\0';
    return;
}

int main() {
    char input[100];
    int vowelCount, consonantCount;

    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';

    if (!isValidString(input)) {
        printf("Invalid input. Please enter a string containing only alphanumeric characters and spaces.\n");
        return 1;
    }

    printf("Original string: %s\n", input);

    replaceVowelsWithNextConsonant(input);
    printf("String with vowels replaced by next consonant: %s\n", input);

    countVowelsAndConsonants(input, &vowelCount, &consonantCount);
    printf("Number of vowels: %d\n", vowelCount);
    printf("Number of consonants: %d\n", consonantCount);

}

