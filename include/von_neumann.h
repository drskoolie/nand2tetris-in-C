#ifndef VON_NEUMANN_H
#define VON_NEUMANN_H

#include <stdint.h>
#include "memory.h"


void cpu(int16_t inM, int16_t instruction_bits, int16_t reset, memory *ram, memory *reg_a, memory *reg_b, memory *program_counter);

#endif
