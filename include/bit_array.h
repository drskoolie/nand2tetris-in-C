#ifndef BIT_ARRAY_H
#define BIT_ARRAY_H

typedef struct {
	int* bits;
	int no_of_bits;
} BitArray;

void print_BitArray(BitArray* bit_array);
int BitArray_to_int(BitArray* bit_array);
void int_to_BitArray(int input, BitArray *output);

#endif
