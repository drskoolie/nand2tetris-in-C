#ifndef MEMORY_H
#define MEMORY_H

#include <stdint.h>

typedef struct {
	int16_t size;
	int16_t *data;
} memory_t ; 

typedef struct {
	memory_t A;
	memory_t D;
	memory_t M;
	memory_t PC;
} registers_t ;

void initialize_memory(memory_t *mem, int16_t size);
void destroy_memory(memory_t *mem);
void set_memory(memory_t *mem, uint16_t address, int16_t value);
int16_t get_memory(memory_t *mem, uint16_t address);

void initialize_registers(registers_t *regs);
void destroy_registers(registers_t *regs);

#endif
