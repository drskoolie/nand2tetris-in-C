#include <stdint.h>

#include "arithmetic.h"
#include "gates.h"

uint16_t half_adder_sum(uint16_t a, uint16_t b)
{
	return xor(a & 0b1, b & 0b1);
}
