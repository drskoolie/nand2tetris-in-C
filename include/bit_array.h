#ifndef BIT_ARRAY_H
#define BIT_ARRAY_H

typedef struct BitArray BitArray;
typedef void (*PrintFunction)(BitArray*);

struct BitArray{
	int* bits;
	int no_of_bits;
	PrintFunction print;
};

void printBitArray(BitArray* bit_array);

BitArray initializeBitArray(int* bits, int no_of_bits);

#endif
