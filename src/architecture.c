#include "architecture.h"
#include "arithmetic.h"
#include "memory.h"

void cpu(
		int16_t instruction_bits,
		int16_t reset,
		memory_t *ram,
		memory_t *reg_a,
		memory_t *reg_b,
		memory_t *reg_m,
		memory_t *program_counter
)
{

	// Instruction Capturing
	int16_t type_of_instruction;
	int16_t mnem_instruction; // Mnemonic Instruction bit
	int16_t comp_instruction;
	int16_t dest_instruction;
	int16_t jump_instruction;

	int16_t x_alu;
	int16_t y_alu;

	type_of_instruction = instruction_bits >> 15;
	mnem_instruction = (instruction_bits & 0b0001000000000000) >> 12;
	comp_instruction = (instruction_bits & 0b0000111111000000) >> 6;
	dest_instruction = (instruction_bits & 0b0000000000111000) >> 3;
	jump_instruction = instruction_bits & 0b0000000000000111;

	/*
	//Address Instruction (sets A register)
	if (type_of_instruction == 0) {
		set_memory(reg_a, 1, instruction_bits);
	}

	//Compute Instruction
	else if (type_of_instruction == 1) {
		if (mnem_instruction == 1) {
			x_alu = get_ram(reg_a);
		}
		else if (mnem_instruction == 0){
			x_alu = get_ram(reg_a);
		}
	}
	*/
}
