#include <stdio.h>
#include <string.h>
#include <ctype.h>   // For toupper()
#include "rnasec.h"

#define MAX 5000
#define MAXLENGTH 5000

// RNA sequence validation function
int is_valid_rna(char *seq) {
    for (int i = 0; seq[i] != '\0'; i++) {
        char c = toupper(seq[i]);
        if (c != 'A' && c != 'U' && c != 'C' && c != 'G') {
            return 0; // invalid character found
        }
    }
    return 1; // valid sequence
}

int canpair(char a, char b) {
    return (a == 'A' && b == 'U') ||
           (a == 'U' && b == 'A') ||
           (a == 'C' && b == 'G') ||
           (a == 'G' && b == 'C');
}

void predict_structure(char* rna) {
    int n = strlen(rna);
    char structure[MAXLENGTH + 1];
    int pairs = 0;

    for (int i = 0; i < n; i++) {
        structure[i] = '.';
    }
    structure[n] = '\0';

    for (int i = 0; i < n; i++) {
        for (int j = n - 1; j > i; j--) {
            if (canpair(rna[i], rna[j]) && structure[i] == '.' && structure[j] == '.') {
                structure[i] = '(';
                structure[j] = ')';
                pairs++;
                break;
            }
        }
    }

    printf("Original Sequence is %s\n", rna);
    printf("Predicted secondary structure is %s\n", structure);
    printf("Total no. of pairs are %d\n", pairs);
}

void predict_rna_structure() {
    char rna[MAXLENGTH];
    printf("Enter RNA sequence (A, U, G, C):\n");
    scanf("%s", rna);

    // Validate the RNA sequence
    if (!is_valid_rna(rna)) {
        printf("Error: Invalid characters in RNA sequence. Only A, U, C, G are allowed.\n");
        return;
    }

    predict_structure(rna);
}
