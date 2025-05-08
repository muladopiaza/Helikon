#include <stdio.h>
#include "meth.h"
#include "mutdec.h"
#include "rnasec.h"
#include "var.h"

int main() {
    int choice;

    while (1) {  // Infinite loop
        printf("\nChoose an option:\n");
        printf("1. Find CpG Methylation Sites\n");
        printf("2. Detect Mutations\n");
        printf("3. Predict RNA Structure\n");
        printf("4. Detect Variants\n");
        printf("5. Exit\n");  // Added Exit option
        printf("Enter choice: ");
        scanf("%d", &choice);

        getchar(); // clear input buffer after scanf

        switch (choice) {
            case 1:
                find_methylation_sites();
                break;
            case 2:
                mutation_detection();
                break;
            case 3:
                predict_rna_structure();
                break;
            case 4:
                variant_detection();
                break;
            case 5:
                printf("Exiting program.\n");
                return 0;  // exit the program
            default:
                printf("Invalid choice! Please select a valid option.\n");
        }
    }

    return 0;
}
