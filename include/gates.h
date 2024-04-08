#ifndef GATES_H
#define GATES_H

typedef struct {
	int *bits;
	int no_of_bits;
} BitArray;

void nand_n(BitArray input1, BitArray input2, BitArray *output);

#endif
