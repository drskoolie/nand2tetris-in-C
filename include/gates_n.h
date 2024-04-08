#ifndef GATES_N_H
#define GATES_N_H

typedef struct {
	int *bits;
	int no_of_bits;
} BitArray;

void nand_n(BitArray input1, BitArray input2, BitArray *output);

#endif
