#include <stdio.h>
#include <string.h>
#include "rnasec.h"

#define MAX 5000
#define MAXLENGTH 5000

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
    printf("Enter RNA sequence (A,U,G,C):\n");
    scanf("%s", rna);
    predict_structure(rna);
}
