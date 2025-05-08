DNA and RNA Sequence Analysis Program
Description

This is a menu-driven C program for performing basic DNA and RNA sequence analysis.
It allows the user to select from different biological analysis options through a simple command-line menu, including:

    Finding CpG Methylation Sites

    Detecting Mutations

    Predicting RNA Secondary Structures

    Detecting DNA Variants
Menu Options

When you run the program, you will see the following menu:

Choose an option:
1. Find CpG Methylation Sites
2. Detect Mutations
3. Predict RNA Structure
4. Detect Variants
5. Exit
Enter choice:

Details of each option:

    1. Find CpG Methylation Sites

        Prompts the user to input a DNA sequence (A, T, C, G only).

        Scans the sequence using a sliding window of size 10.

        Counts the number of CpG dinucleotide patterns (CG) in each window.

        If the number of CpG sites in a window is greater than or equal to 2, it is reported as a high-probability methylation site.

    2. Detect Mutations

        Placeholder function (mutation_detection() in mutdec.h) for detecting mutations between sequences.
        (Implementation expected to be in mutdec.c.)

    3. Predict RNA Structure

        Placeholder function (predict_rna_structure() in rnasec.h) for analyzing and predicting basic RNA secondary structures.
        (Implementation expected to be in rnasec.c.)

    4. Detect Variants

        Placeholder function (variant_detection() in var.h) for detecting genetic variants like SNPs.
        (Implementation expected to be in var.c.)

    5. Exit

        Cleanly exits the program.

File Structure
File	Purpose
main.c	Displays the menu and controls program flow.
meth.h + meth.c	Functions to find CpG methylation sites.
mutdec.h + mutdec.c	Functions to detect mutations.
rnasec.h + rnasec.c	Functions to predict RNA structure.
var.h + var.c	Functions to detect genetic variants.


