#include <stdio.h>
#include <stdlib.h>
#include "gates.h"
#include "bit_array.h"

void raise_error(const char *message) {
	fprintf(stderr, "Error: %s\n", message);
}

void and_n(BitArray input0, BitArray input1, BitArray *output)
{
	if (! ((input0.no_of_bits == input1.no_of_bits) && (input1.no_of_bits == output->no_of_bits)) ) {
		raise_error("and_n()'s no_of_bits is not equal between inputs\n");
	}

	for (int i = 0; i < input0.no_of_bits; i++) {
		output->bits[i] = (input0.bits[i] && input1.bits[i]);
	}
}

void or_n(BitArray input0, BitArray input1, BitArray *output)
{
	if (! ((input0.no_of_bits == input1.no_of_bits) && (input1.no_of_bits == output->no_of_bits)) ) {
		raise_error("or_n()'s no_of_bits is not equal between inputs\n");
	}

	for (int i = 0; i < input0.no_of_bits; i++) {
		output->bits[i] = (input0.bits[i] || input1.bits[i]);
	}
}

void not_n(BitArray input, BitArray *output)
{
	if (! (input.no_of_bits == output->no_of_bits) ) {
		raise_error("not_n()'s no_of_bits is not equal between inputs\n");
	}

	for (int i = 0; i < input.no_of_bits; i++) {
		output->bits[i] = !input.bits[i];
	}
}


void nand_n(BitArray input0, BitArray input1, BitArray *output)
{
	if (! ((input0.no_of_bits == input1.no_of_bits) && (input1.no_of_bits == output->no_of_bits)) ) {
		raise_error("nand_n()'s no_of_bits is not equal between inputs\n");
	}

	for (int i = 0; i < input0.no_of_bits; i++) {
		output->bits[i] = !(input0.bits[i] && input1.bits[i]);
	}
}

void xor_n(BitArray input0, BitArray input1, BitArray *output)
{
	if (! ((input0.no_of_bits == input1.no_of_bits) && (input1.no_of_bits == output->no_of_bits)) ) {
		raise_error("xor_n()'s no_of_bits is not equal between inputs\n");
	}

	for (int i = 0; i < input0.no_of_bits; i++) {
		output->bits[i] = ( (input0.bits[i] && !input1.bits[i]) || (!input0.bits[i] && input1.bits[i]) );
	}
}

void mux_n(BitArray input0, BitArray input1, int selector, BitArray *output)
{
	for (int i = 0; i < input0.no_of_bits; i++) {
		output->bits[i] = (input0.bits[i] && !selector) || (input1.bits[i] && selector);
	}
}
