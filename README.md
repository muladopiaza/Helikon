#  DNA and RNA Sequence Analysis Program

A **menu-driven C program** for performing basic DNA and RNA sequence analysis through the command line. This tool enables users to explore various biological features such as:

- Finding **CpG Methylation Sites**
- **Detecting Mutations**
- **Predicting RNA Secondary Structures**
- **Detecting DNA Variants**

---

# Menu Options

When you run the program, you'll see the following menu:

Choose an option:

    Find CpG Methylation Sites

    Detect Mutations

    Predict RNA Structure

    Detect Variants

    Exit
    Enter choice:


### 🔹 Option 1: Find CpG Methylation Sites

- Prompts user to enter a DNA sequence (A, T, C, G only).
- Scans the sequence using a sliding window of size 10.
- Detects `CpG` dinucleotide patterns (i.e., "CG") within each window.
- If `>= 2` CpG sites are found in a window, it's reported as a **high-probability methylation site**.

---

### 🔹 Option 2: Detect Mutations

- Calls a placeholder function: `mutation_detection()` defined in `mutdec.h`
- Expected implementation should compare two sequences and highlight mutations.
- (To be implemented in `mutdec.c`)

---

### 🔹 Option 3: Predict RNA Structure

- Placeholder function: `predict_rna_structure()` in `rnasec.h`
- Intended for RNA secondary structure prediction.
- (To be implemented in `rnasec.c`)

---

### 🔹 Option 4: Detect Variants

- Placeholder function: `variant_detection()` in `var.h`
- For detecting genetic variants like **SNPs**.
- (To be implemented in `var.c`)

---

### 🔹 Option 5: Exit

- Cleanly exits the program.

---

## File Structure

| File | Purpose |
|------|---------|
| `main.c` | Menu interface & main program logic |
| `meth.c/h` | CpG methylation site detection |
| `mutdec.c/h` | Mutation detection (placeholder) |
| `rnasec.c/h` | RNA structure prediction (placeholder) |
| `var.c/h` | Variant detection (placeholder) |

---

##  Compilation and Execution

###  Clone the repository

```bash
git clone https://github.com/yourusername/bioinformatics-program.git
cd bioinformatics-program

 Compile with gcc

gcc main.c meth.c mutdec.c rnasec.c var.c -o final_program

 Or use make

make

 Run the program

./final_program

Example Run

Choose an option:
1. Find CpG Methylation Sites
2. Detect Mutations
3. Predict RNA Structure
4. Detect Variants
5. Exit
Enter choice: 1
Enter DNA sequence (A, T, C, G only):
ATCGCGCGTACGCGCGATCG
High-probability CpG methylation sites (window positions):
Position 0 to 9: 3 CpG sites
Position 2 to 11: 3 CpG sites
Position 4 to 13: 3 CpG sites
Position 6 to 15: 2 CpG sites
...

 Notes

    Minimal input validation (expects only valid uppercase nucleotides).

    Mutation detection, RNA structure prediction, and variant detection are placeholders.

    Designed to be modular and easily extensible.

Future Improvements

    Full implementation of:

        Mutation detection

        RNA structure prediction

        Variant detection

    Better input validation (e.g., lowercase handling, file input).

    Sequence I/O (reading from and writing to files).

    Visualization of:

        CpG methylation sites

        RNA secondary structures

