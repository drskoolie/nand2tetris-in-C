#ifndef ARITHMETIC_H
#define ARITHMETIC_H

uint16_t half_adder_sum(uint16_t a, uint16_t b);
uint16_t half_adder_carry(uint16_t a, uint16_t b);
uint16_t full_adder_sum(uint16_t a, uint16_t b, uint16_t carry_in);
uint16_t full_adder_carry(uint16_t a, uint16_t b, uint16_t carry_in);
uint16_t adder(uint16_t a, uint16_t b);

#endif
