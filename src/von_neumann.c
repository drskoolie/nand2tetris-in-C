#include "von_neumann.h"
#include "arithmetic.h"
#include "sequential.h"

void cpu(int16_t inM, int16_t instruction_bits, int16_t reset, flip_flop *reg_a)
{

	// Instruction Capturing
	uint16_t type_of_instruction;
	uint16_t comp_instruction;
	uint16_t dest_instruction;
	uint16_t jump_instruction;

	type_of_instruction = instruction_bits >> 15;
	comp_instruction = instruction_bits & 0b0001111111000000;
	dest_instruction = instruction_bits & 0b0000000000111000;
	jump_instruction = instruction_bits & 0b0000000000000111;

	//Address Instruction (sets A register)
	if (type_of_instruction == 0) {
		set_ram(reg_a, 1, instruction_bits);
	}

	//Compute Instruction
	else if (type_of_instruction == 1) {
	}
}
