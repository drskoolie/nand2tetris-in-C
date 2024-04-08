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

int BitArray_to_int(BitArray* bit_array)
{
	return 1;
}
