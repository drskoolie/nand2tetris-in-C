#ifndef ARCHITECTURE_H
#define ARCHITECTURE_H

#include <stdint.h>
#include "memory.h"


void cpu(int16_t instruction_bits, int16_t reset, memory_t *ram, registers_t *regs);

#endif
