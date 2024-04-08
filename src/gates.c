#include <stdio.h>
#include "gates.h"
#include "bit_array.h"

void nand_n(BitArray input0, BitArray input1, BitArray *output)
{
	if (! ((input0.no_of_bits == input1.no_of_bits) && (input1.no_of_bits == output->no_of_bits)) ) {
		printf("nand_n()'s no_of_bits is not equal between inputs\n");
	}

	output->bits[0] = 1;
	output->bits[1] = 1;
	output->bits[2] = 1;
	output->bits[3] = 0;
}
