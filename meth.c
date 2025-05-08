#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 1000
#define WINDOW_SIZE 10
#define THRESHOLD 2

static int is_valid_dna(char *seq) {
    for (int i = 0; seq[i] != '\0'; i++) {
        char c = toupper(seq[i]);
        if (c != 'A' && c != 'T' && c != 'C' && c != 'G') {
            return 0; // invalid
        }
    }
    return 1; // valid
}

void find_methylation_sites() {
    char dna[MAX_LEN];
    int length, i, j;
    int found = 0;

    printf("Enter DNA sequence (A, T, C, G only):\n");
    scanf("%s", dna);

    if (!is_valid_dna(dna)) {
        printf("Error: Invalid characters in DNA sequence. Only A, T, C, G are allowed.\n");
        return;
    }

    length = strlen(dna);

    if (length < WINDOW_SIZE) {
        printf("\nDNA sequence too short! Needs at least %d bases.\n", WINDOW_SIZE);
        return;
    }

    printf("\nHigh-probability CpG methylation sites (window positions):\n");

    for (i = 0; i <= length - WINDOW_SIZE; i++) {
        int cpg_count = 0;
        for (j = i; j < i + WINDOW_SIZE - 1; j++) {
            if (dna[j] == 'C' && dna[j + 1] == 'G') {
                cpg_count++;
            }
        }
        if (cpg_count >= THRESHOLD) {
            printf("Position %d to %d: %d CpG sites\n", i, i + WINDOW_SIZE - 1, cpg_count);
            found = 1;
        }
    }

    if (!found) {
        printf("No high-probability CpG methylation sites found.\n");
    }
}
