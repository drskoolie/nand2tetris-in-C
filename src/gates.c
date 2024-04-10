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
