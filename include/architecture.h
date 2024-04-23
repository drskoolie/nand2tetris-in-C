#ifndef ARCHITECTURE_H
#define ARCHITECTURE_H

#include <stdint.h>
#include "memory.h"


int16_t set_instruction_bits(
		uint16_t type_of_instruction,
		uint16_t mnem,
		uint16_t comp,
		uint16_t dest,
		uint16_t jump
		);
void cpu(int16_t instruction_bits, int16_t reset, memory_t *ram, registers_t *regs);

#endif
