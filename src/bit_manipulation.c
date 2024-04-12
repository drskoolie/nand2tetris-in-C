#include <stdint.h>
#include "bit_manipulation.h"
#include "gates.h"

uint16_t repeat_lsb(uint16_t lsb)
{
	uint16_t out = 0;

	for (int i = 0; i < 16; i++) {
		out |= (lsb << i);
	}

	return out;
}

uint16_t comparater(uint16_t a, uint16_t b)
{
	uint16_t compare = 0;
	uint16_t out = 0b1;

	compare = not(xor(a, b));

	for (int i = 0; i < 16; i++) {
		out &= (compare >> i) & 0b1;
	}

	return out;
}
