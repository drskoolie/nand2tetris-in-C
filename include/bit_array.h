#ifndef BIT_ARRAY_H
#define BIT_ARRAY_H


typedef struct {
	int* bits;
	int no_of_bits;
} BitArray;

void printBitArray(BitArray* bit_array);

#endif
