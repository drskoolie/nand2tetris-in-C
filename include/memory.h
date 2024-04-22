#ifndef MEMORY_H
#define MEMORY_H

#include <stdint.h>

typedef struct {
	int16_t size;
	int16_t *data;
} memory ; 

void initialize_memory(memory *mem, int16_t size);
void destroy_memory(memory *mem);
void set_memory(memory *mem, uint16_t address, int16_t value);
int16_t get_memory(memory *mem, uint16_t address);

void initialize_register(memory *reg);
void set_register(memory *reg, int16_t value);
int16_t get_register(memory *reg);

#endif
