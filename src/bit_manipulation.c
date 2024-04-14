#include <stdint.h>

#include "gates.h"
#include "bit_manipulation.h"

int16_t repeat_lsb(int16_t lsb)
{
	int16_t out = 0;

	for (int i = 0; i < 16; i++) {
		out |= (lsb << i);
	}

	return out;
}

int16_t comparater(int16_t a, int16_t b)
{
	int16_t compare = 0;
	int16_t out = 0b1;

	compare = not(xor(a, b));

	for (int i = 0; i < 16; i++) {
		out &= (compare >> i) & 0b1;
	}

	return out;
}
