#ifndef MEMORY_H
#define MEMORY_H

#include <stdint.h>

typedef struct {
	int16_t size;
	int16_t *data;
} memory_t ; 

typedef struct {
	memory_t a;
	memory_t d;
	memory_t m;
	memory_t pc;
} registers_t ;

void initialize_memory(memory_t *mem, int16_t size);
void destroy_memory(memory_t *mem);
void set_memory(memory_t *mem, uint16_t address, int16_t value);
int16_t get_memory(memory_t *mem, uint16_t address);

void initialize_register(memory_t *reg);
void set_register(memory_t *reg, int16_t value);
int16_t get_register(memory_t *reg);

void initialize_registers(registers_t regs);

#endif
