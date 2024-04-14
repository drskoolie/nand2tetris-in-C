#include <stdio.h>
#include <stdint.h>

#include "arithmetic.h"
#include "binary.h"
#include "bit_manipulation.h"
#include "gates.h"

int16_t half_adder_sum(int16_t a, int16_t b)
{
	a = a & 0b1;
	b = b & 0b1;
	return xor(a, b);
}

int16_t half_adder_carry(int16_t a, int16_t b)
{
	a = a & 0b1;
	b = b & 0b1;
	return and(a, b);
}

int16_t full_adder_sum(int16_t a, int16_t b, int16_t carry_in)
{
	a = a & 0b1;
	b = b & 0b1;
	carry_in = carry_in & 0b1;
	return xor(xor(a, b), carry_in);
}

int16_t full_adder_carry(int16_t a, int16_t b, int16_t carry_in)
{
	a = a & 0b1;
	b = b & 0b1;
	carry_in = carry_in & 0b1;
	return or(or(and(a, b), and(a, carry_in)), and(b, carry_in));
}

int16_t adder(int16_t a, int16_t b)
{
	int16_t sum_bit = 0b0;
	int16_t carry_in = 0b0;

	int16_t out = 0b0;

	for (int i = 0; i < 16; ++i) {
		sum_bit = full_adder_sum((a >> i) & 1, (b >> i) & 1, carry_in);
		carry_in = full_adder_carry((a >> i) & 1, (b >> i) & 1, carry_in);

		out |= sum_bit << i;
	}

	return out;
}

int16_t incrementer(int16_t a)
{
	return adder(a, 0b1);
}

void alu(int16_t x, int16_t y, int16_t instruction_bits, int16_t *out, int16_t *zr, int16_t *ng)
{
	int16_t zx = repeat_lsb((instruction_bits >> 5) & 0b1);
	int16_t nx = repeat_lsb((instruction_bits >> 4) & 0b1);
	int16_t zy = repeat_lsb((instruction_bits >> 3) & 0b1);
	int16_t ny = repeat_lsb((instruction_bits >> 2) & 0b1);
	int16_t f = repeat_lsb((instruction_bits >> 1) & 0b1);
	int16_t no = repeat_lsb((instruction_bits) & 0b1);

	printf("x: ");
	print_binary(x);
	x &= ~zx;
	printf("x & ~zx: ");
	print_binary(x);
	x ^= nx;
	printf("x ^ nx: ");
	print_binary(x);

	printf("y: ");
	print_binary(y);
	y &= ~zy;
	printf("y & ~zy: ");
	print_binary(y);
	y ^= ny;
	printf("y ^ ny: ");
	print_binary(y);

	*out = adder(x, y);
	printf("out: ");
	print_binary(*out);
	*out = mux(x & y, adder(x, y), f);
	*out ^= no;
	printf("out ^: ");
	print_binary(*out);

	*zr = comparater(*out, 0);
	*ng = ((*out & 0b1000000000000000) >> 15) & 0b1;
}
