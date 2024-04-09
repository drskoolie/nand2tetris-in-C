#ifndef GATES_H
#define GATES_H

#include "bit_array.h"

void raise_error(const char *message);
void and_n(BitArray input0, BitArray input1, BitArray *output);
void or_n(BitArray input0, BitArray input1, BitArray *output);
void not_n(BitArray input, BitArray *output);
void nand_n(BitArray input0, BitArray input1, BitArray *output);
void xor_n(BitArray input0, BitArray input1, BitArray *output);
void mux_n(BitArray input0, BitArray input1, int selector, BitArray *output);

#endif
