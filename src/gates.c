#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "gates.h"
#include "binary.h"

uint16_t nand(uint16_t in0, uint16_t in1)
{
	return ~(in0 & in1);
}

uint16_t and(uint16_t in0, uint16_t in1)
{
	uint16_t out = nand(in0, in1);

	return nand(out, out);
}

uint16_t or(uint16_t in0, uint16_t in1)
{
	return nand(nand(in0, in0), nand(in1, in1));
}

uint16_t not(uint16_t in)
{
	return nand(in, in);
}

uint16_t xor(uint16_t in0, uint16_t in1)
{
	return nand(nand(nand(in0, in0), in1), nand(in0, nand(in1, in1)));
}

uint16_t mux(uint16_t in0, uint16_t in1, uint16_t sel)
{
	uint16_t out = 0;
	uint16_t bit0 = 0;
	uint16_t bit1 = 0;

	for (int i = 0; i < 16; i++) {
		bit0 = ((in0 >> i) & 0b1);
		bit1 = ((in1 >> i) & 0b1);

		out |= ((bit0 & ~sel) | (bit1 & sel)) << i;
	}

	return out;
}

void demux(uint16_t in, uint16_t sel, uint16_t *out0, uint16_t *out1)
{

	uint16_t bit_in = 0;

	for (int i = 0; i < 16; i++) {
		bit_in = ((in >> i) & 0b1);

		*out0 |= (bit_in & ~sel) << i;
		*out1 |= (bit_in & sel) << i;
	}
}

uint16_t repeat_lsb(uint16_t lsb)
{
	uint16_t out = 0;

	for (int i = 0; i < 16; i++) {
		out |= (lsb << i);
	}

	return out;
}
