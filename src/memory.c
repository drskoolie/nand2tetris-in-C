#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "memory.h"

void initialize_memory(memory_t *mem, int16_t size)
{
	mem->size = size;
	mem->data = (int16_t *)calloc(size, sizeof(int16_t));

	if (mem->data == NULL) {
		fprintf(stderr, "Memory allocation failed\n");
		exit(1);
	}
}

void destroy_memory(memory_t *mem)
{
	if (mem->data != NULL) {
		free(mem->data);
		mem->data = NULL;
	}
}

void set_memory(memory_t *mem, uint16_t address, int16_t value)
{
	if (address < mem->size) {
		mem->data[address] = value;
	}
	else {
		fprintf(stderr, "Error: Address out of bounds\n");
		exit(1);
	}
}

int16_t get_memory(memory_t *mem, uint16_t address)
{
	if (address < mem->size) {
		return mem->data[address];
	}
	else {
		fprintf(stderr, "Error: Address out of bounds\n");
		exit(1);
	}
}

void initialize_registers(registers_t *regs)
{
	initialize_memory(&regs->A, 1);
	initialize_memory(&regs->D, 1);
	initialize_memory(&regs->M, 1);
	initialize_memory(&regs->PC, 1);
}

void destroy_registers(registers_t *regs)
{
	destroy_memory(&regs->A);
	destroy_memory(&regs->D);
	destroy_memory(&regs->M);
	destroy_memory(&regs->PC);
}

void set_register_A(registers_t *regs, int16_t value)
{
	set_memory(&regs->A, 0, value);
}

void set_register_D(registers_t *regs, int16_t value)
{
	set_memory(&regs->D, 0, value);
}

void set_register_PC(registers_t *regs, int16_t value)
{
	set_memory(&regs->PC, 0, value);
}

int16_t get_register_A(registers_t *regs)
{
	return get_memory(&regs->A, 0);
}

int16_t get_register_D(registers_t *regs)
{
	return get_memory(&regs->D, 0);
}

int16_t get_register_PC(registers_t *regs)
{
	return get_memory(&regs->PC, 0);
}
