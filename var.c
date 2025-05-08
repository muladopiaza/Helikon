#include <stdio.h>
#include <string.h>
#include "var.h"

#define MAX_LEN 10000

// Function to validate sequence input (only A, T, C, G, and '-' are allowed)
int is_valid_sequence(char* seq) {
    for (int i = 0; seq[i] != '\0'; i++) {
        char c = seq[i];
        if (c != 'A' && c != 'T' && c != 'C' && c != 'G' && c != '-') {
            return 0; // invalid character found
        }
    }
    return 1; // valid sequence
}

void compare_sequences(char* ref, char* sample, int len_ref, int len_sample) {
    int min_len = len_ref < len_sample ? len_ref : len_sample;

    for (int i = 0; i < min_len; i++) {
        if (ref[i] != sample[i]) {
            if (sample[i] == '-') {
                printf("Deletion at position %d: %c -> -\n", i + 1, ref[i]);
            } else if (ref[i] == '-') {
                printf("Insertion at position %d: - -> %c\n", i + 1, sample[i]);
            } else {
                printf("SNP at position %d: %c -> %c\n", i + 1, ref[i], sample[i]);
            }
        }
    }
    if (len_sample > len_ref) {
        for (int i = len_ref; i < len_sample; i++) {
            printf("Insertion at position %d: - -> %c\n", i + 1, sample[i]);
        }
    }
    else if (len_ref > len_sample) {
        for (int i = len_sample; i < len_ref; i++) {
            printf("Deletion at position %d: %c -> -\n", i + 1, ref[i]);
        }
    }
}

// Function to get and validate sequence input
void get_sequence_input(char* prompt, char* sequence) {
    printf("%s", prompt);
    scanf("%s", sequence);

    // Validate the input sequence
    if (!is_valid_sequence(sequence)) {
        printf("Error: Invalid characters in sequence. Only A, T, C, G, and '-' are allowed.\n");
        sequence[0] = '\0';  // Clear the sequence to prevent further processing
    }
}

void variant_detection() {
    char ref[MAX_LEN], sample[MAX_LEN];

    get_sequence_input("Enter reference sequence:\n", ref);
    if (ref[0] == '\0') return;  // Exit if invalid reference sequence was entered

    get_sequence_input("Enter sample sequence:\n", sample);
    if (sample[0] == '\0') return;  // Exit if invalid sample sequence was entered

    int len_ref = strlen(ref);
    int len_sample = strlen(sample);

    compare_sequences(ref, sample, len_ref, len_sample);
}
