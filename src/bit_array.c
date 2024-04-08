#include <stdio.h>
#include "bit_array.h"

void printBitArray(BitArray* bit_array)
{
	printf("Index: ");
	for (int i = 0; i < bit_array->no_of_bits; i++) {
		printf("%d ", i);
	}
	printf("\n");

	printf("Value: ");
	for (int i = 0; i < bit_array->no_of_bits; i++) {
		printf("%d ", bit_array->bits[i]);
	}
	printf("\n");
}

BitArray initializeBitArray(int* bits, int no_of_bits)
{
	BitArray bit_array;
	bit_array.bits = bits;
	bit_array.no_of_bits = no_of_bits;
	bit_array.print = printBitArray;
	return bit_array;
}
