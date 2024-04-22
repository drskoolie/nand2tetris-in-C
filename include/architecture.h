#ifndef ARCHITECTURE_H
#define ARCHITECTURE_H

#include <stdint.h>
#include "memory.h"


void cpu(
		int16_t instruction_bits,
		int16_t reset,
		memory_t *ram,
		memory_t *reg_a,
		memory_t *reg_b,
		memory_t *reg_m,
		memory_t *program_counter
);

#endif
