#include <stdio.h>
#include <stdlib.h>
#include "bit_array.h"

void print_BitArray(BitArray* bit_array)
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

int BitArray_to_int(BitArray *bit_array)
{
	int number = 0;

	for (int i = 0; i < bit_array->no_of_bits; i++) {
		number = (number << 1) | bit_array->bits[i];
	}

	return number;
}

void int_to_BitArray(int input, BitArray *output)
{
	if (output->no_of_bits != 16) {
		fprintf(stderr, "Error: %d bits given \n%s", 
				output->no_of_bits, "int_to_BitArray is only for 16 bits!\n");
	}

}
