#include <stdio.h>
#include <stdlib.h>

int main() {
    // Create the file "text.txt" and write some lines of English text to it
    FILE *fp = fopen("text.txt", "w");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    fprintf(fp, "This is the first line.\n");
    fprintf(fp, "The quick brown fox jumps over the lazy dog.\n");
    fprintf(fp, "In the end, we will remember not the words of our enemies, but the silence of our friends.\n");
    fprintf(fp, "Success is not final, failure is not fatal: It is the courage to continue that counts.\n");

    fclose(fp);

    // Read the input 'n' from the user
    int n;
    printf("Enter the number of lines to print: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Please enter a valid positive integer for the number of lines.\n");
        return 1;
    }

    // Open the file "text.txt" to read its content
    fp = fopen("text.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    // Read the file and store the last 'n' lines in an array
    char lines[n][1000];
    int lineCount = 0;
    while (fgets(lines[lineCount], sizeof(lines[lineCount]), fp) != NULL) {
        lineCount++;
        if (lineCount >= n) {
            lineCount = 0; // Wrap around the array to store only the last 'n' lines
        }
    }

    // Print the last 'n' lines stored in the array
    for (int i = 0; i < n; i++) {
        printf("%s", lines[lineCount]);
        lineCount = (lineCount + 1) % n;
    }

    fclose(fp);

    return 0;
}
