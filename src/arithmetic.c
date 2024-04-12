#include <stdio.h>
#include <stdint.h>

#include "arithmetic.h"
#include "binary.h"
#include "bit_manipulation.h"
#include "gates.h"

uint16_t half_adder_sum(uint16_t a, uint16_t b)
{
	a = a & 0b1;
	b = b & 0b1;
	return xor(a, b);
}

uint16_t half_adder_carry(uint16_t a, uint16_t b)
{
	a = a & 0b1;
	b = b & 0b1;
	return and(a, b);
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

uint16_t adder(uint16_t a, uint16_t b, uint16_t *carry_out)
{
	uint16_t sum_bit = 0b0;
	*carry_out = 0b0;

	uint16_t out = 0b0;

	for (int i = 0; i < 16; ++i) {
		sum_bit = full_adder_sum((a >> i) & 1, (b >> i) & 1, *carry_out);
		*carry_out = full_adder_carry((a >> i) & 1, (b >> i) & 1, *carry_out);

		out |= sum_bit << i;
	}

	return out;
}

uint16_t incrementer(uint16_t a)
{
	return adder(a, 0b1, 0b0);
}

void alu(uint16_t x, uint16_t y, uint16_t instruction_bits, uint16_t *out, uint16_t *zr, uint16_t *ng)
{
	uint16_t zx = repeat_lsb((instruction_bits >> 5) & 0b1);
	uint16_t nx = repeat_lsb((instruction_bits >> 4) & 0b1);
	uint16_t zy = repeat_lsb((instruction_bits >> 3) & 0b1);
	uint16_t ny = repeat_lsb((instruction_bits >> 2) & 0b1);
	uint16_t f = repeat_lsb((instruction_bits >> 1) & 0b1);
	uint16_t no = repeat_lsb((instruction_bits) & 0b1);

	x &= ~zx;

	*out = adder(x, y, ng);
}
