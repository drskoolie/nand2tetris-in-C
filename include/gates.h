#ifndef GATES_H
#define GATES_H

#include "bit_array.h"

void raise_error(const char *message);
void nand_n(BitArray input0, BitArray input1, BitArray *output);
void and_n(BitArray input0, BitArray input1, BitArray *output);

#endif
