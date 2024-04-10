#include <stdint.h>

#include "arithmetic.h"
#include "gates.h"

uint16_t half_adder_sum(uint16_t a, uint16_t b)
{
	return xor(a & 0b1, b & 0b1);
}

uint16_t half_adder_carry(uint16_t a, uint16_t b)
{
	return and(a & 0b1, b & 0b1);
}

uint16_t full_adder_sum(uint16_t a, uint16_t b, uint16_t carry_in)
{
	return xor(xor(a, b), carry_in);
}
