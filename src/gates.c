#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "gates.h"

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
	if (sel == 0) {
		return in0;
	}
	else if (sel ==1) {
		return in1;
	}
}
