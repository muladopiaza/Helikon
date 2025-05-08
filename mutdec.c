#include <stdio.h>
#include <string.h>
#include "mutdec.h"

#define MAX 1000

void read_seq(char *s) {
    char line[MAX+1];
    if (!fgets(line, MAX+1, stdin)) return;
    if (line[0] == '>') {
        if (!fgets(line, MAX+1, stdin)) return;
    }
    line[strcspn(line, "\r\n")] = '\0';
    strcpy(s, line);
}

void mutation_detection() {
    char orig[MAX+1], mut[MAX+1];
    int i, j, pos, len1, len2;

    printf("Original sequence> ");
    read_seq(orig);
    printf("Mutated sequence>  ");
    read_seq(mut);

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
