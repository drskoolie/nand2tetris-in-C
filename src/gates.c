#include <stdint.h>
#include "gates.h"

int16_t nand(int16_t in0, int16_t in1)
{
	return ~(in0 & in1);
}

int16_t and(int16_t in0, int16_t in1)
{
	int16_t out = nand(in0, in1);

	return nand(out, out);
}

int16_t or(int16_t in0, int16_t in1)
{
	return nand(nand(in0, in0), nand(in1, in1));
}

int16_t not(int16_t in)
{
	return nand(in, in);
}

int16_t xor(int16_t in0, int16_t in1)
{
	return nand(nand(nand(in0, in0), in1), nand(in0, nand(in1, in1)));
}

int16_t mux(int16_t in0, int16_t in1, int16_t sel)
{
	int16_t out = 0;
	int16_t bit0 = 0;
	int16_t bit1 = 0;

	for (int i = 0; i < 16; i++) {
		bit0 = ((in0 >> i) & 0b1);
		bit1 = ((in1 >> i) & 0b1);

		out |= ((bit0 & ~sel) | (bit1 & sel)) << i;
	}

	return out;
}

void demux(int16_t in, int16_t sel, int16_t *out0, int16_t *out1)
{

	int16_t bit_in = 0;

	for (int i = 0; i < 16; i++) {
		bit_in = ((in >> i) & 0b1);

		*out0 |= (bit_in & ~sel) << i;
		*out1 |= (bit_in & sel) << i;
	}
}
