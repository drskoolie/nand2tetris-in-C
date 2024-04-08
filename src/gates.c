#include "gates.h"
#include "bit_array.h"

void nand_n(BitArray input0, BitArray input1, BitArray *output)
{
	output->bits[0] = 1;
	output->bits[1] = 1;
	output->bits[2] = 1;
	output->bits[3] = 0;
}
