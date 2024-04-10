#include <stdio.h>
#include <stdint.h>

#include "arithmetic.h"
#include "binary.h"
#include "gates.h"

uint16_t half_adder_sum(uint16_t a, uint16_t b)
{
	return xor(a, b);
}

uint16_t half_adder_carry(uint16_t a, uint16_t b)
{
	return and(a, b);
}

uint16_t full_adder_sum(uint16_t a, uint16_t b, uint16_t carry_in)
{
	return xor(xor(a, b), carry_in);
}

uint16_t full_adder_carry(uint16_t a, uint16_t b, uint16_t carry_in)
{
	return or(or(and(a, b), and(a, carry_in)), and(b, carry_in));
}

uint16_t adder(uint16_t a, uint16_t b)
{
	uint16_t out = 0b0;

	uint16_t mask;
	uint16_t carry_in = 0b0;

	for (int i = 0; i < 16; ++i) {
		mask = 1 << i;
		out |= full_adder_sum(and(a, mask), and(b, mask), carry_in);
		carry_in = full_adder_carry(and(a, mask), and(b, mask), carry_in);
	}

	return out;
}
