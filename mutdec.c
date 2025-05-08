#include <stdio.h>
#include <string.h>
#include <ctype.h>   // For toupper()
#include "mutdec.h"

#define MAX 1000

// DNA sequence validation function
static int is_valid_dna(char *seq) {
    for (int i = 0; seq[i] != '\0'; i++) {
        char c = toupper(seq[i]);
        if (c != 'A' && c != 'T' && c != 'C' && c != 'G') {
            return 0; // invalid character found
        }
    }
    return 1; // valid sequence
}

// Reads sequence, skips headers if needed
void read_seq(char *s) {
    char line[MAX+1];
    if (!fgets(line, MAX+1, stdin)) return;
    if (line[0] == '>') { // FASTA-style header
        if (!fgets(line, MAX+1, stdin)) return;
    }
    line[strcspn(line, "\r\n")] = '\0'; // Remove newline
    strcpy(s, line);
}

void mutation_detection() {
    char orig[MAX+1], mut[MAX+1];
    int i, j, pos, len1, len2;

    printf("Original sequence> ");
    read_seq(orig);

    if (!is_valid_dna(orig)) {
        printf("Error: Invalid characters in original DNA sequence. Only A, T, C, G are allowed.\n");
        return;
    }

    printf("Mutated sequence>  ");
    read_seq(mut);

    if (!is_valid_dna(mut)) {
        printf("Error: Invalid characters in mutated DNA sequence. Only A, T, C, G are allowed.\n");
        return;
    }

    len1 = strlen(orig);
    len2 = strlen(mut);
    i = j = 0;
    pos = 1;

    while (i < len1 && j < len2) {
        if (orig[i] != mut[j])
            printf("Substitution at %d: %c -> %c\n", pos, orig[i], mut[j]);
        i++; j++; pos++;
    }
    while (i < len1) {
        printf("Deletion    at %d: %c removed\n", pos, orig[i]);
        i++; pos++;
    }
    while (j < len2) {
        printf("Insertion   at %d: %c added\n", pos, mut[j]);
        j++; pos++;
    }
}
