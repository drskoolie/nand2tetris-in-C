#include <stdint.h>
#include "bit_manipulation.h"

uint16_t repeat_lsb(uint16_t lsb)
{
	uint16_t out = 0;

	for (int i = 0; i < 16; i++) {
		out |= (lsb << i);
	}

	return out;
}

uint16_t comparator(uint16_t a, uint16_t b)
{
	uint16_t out = 0;
	return out;

}
