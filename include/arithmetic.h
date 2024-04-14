#ifndef ARITHMETIC_H
#define ARITHMETIC_H

#include <stdint.h>

int16_t half_adder_sum(int16_t a, int16_t b);
int16_t half_adder_carry(int16_t a, int16_t b);
int16_t full_adder_sum(int16_t a, int16_t b, int16_t carry_in);
int16_t full_adder_carry(int16_t a, int16_t b, int16_t carry_in);
int16_t adder(int16_t a, int16_t b);
int16_t incrementer(int16_t a);
void alu(int16_t x, int16_t y, int16_t instruction_bits, int16_t *out, int16_t *zr, int16_t *ng);

#endif
