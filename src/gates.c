#include <stdio.h>
#include "gates.h"
#include "bit_array.h"

void nand_n(BitArray input0, BitArray input1, BitArray *output)
{
	if (! ((input0.no_of_bits == input1.no_of_bits) && (input1.no_of_bits == output->no_of_bits)) ) {
		printf("nand_n()'s no_of_bits is not equal between inputs\n");
	}

	for (int i = 0; i < input0.no_of_bits; i++) {
		output->bits[i] = !(input0.bits[i] && input1.bits[i]);
	}
}
