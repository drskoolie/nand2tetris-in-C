#ifndef ARCHITECTURE_H
#define ARCHITECTURE_H

#include <stdint.h>
#include "memory.h"


void cpu(
		int16_t instruction_bits,
		int16_t reset,
		memory *ram,
		memory *reg_a,
		memory *reg_b,
		memory *reg_m,
		memory *program_counter
);

#endif
