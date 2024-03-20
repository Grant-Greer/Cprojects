#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* concatStrings(const char* string1, const char* string2) {
    // Allocate memory for the concatenated string
    // +1 for the null terminator
    char* result = malloc(strlen(string1) + strlen(string2) + 1);
    if (result == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    strcpy(result, string1); // Copy the first string into result
    strcat(result, string2); // Concatenate the second string to result

    return result;
}

int main() {
    const char* string1 = "Hello";
    const char* string2 = " world!";

    char* concatenatedString = concatStrings(string1, string2);
    printf("%s\n", concatenatedString);

    // Don't forget to free the dynamically allocated memory
    free(concatenatedString);

    return 0;
}

