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
	a = a & 0b1;
	b = b & 0b1;
	carry_in = carry_in & 0b1;
	return xor(xor(a, b), carry_in);
}

uint16_t full_adder_carry(uint16_t a, uint16_t b, uint16_t carry_in)
{
	a = a & 0b1;
	b = b & 0b1;
	carry_in = carry_in & 0b1;
	return or(or(and(a, b), and(a, carry_in)), and(b, carry_in));
}

uint16_t adder(uint16_t a, uint16_t b)
{
	uint16_t out = 0b0;

	return out;
}
