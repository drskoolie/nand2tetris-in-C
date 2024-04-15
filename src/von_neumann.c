#include "von_neumann.h"
#include "arithmetic.h"
#include "sequential.h"

void cpu(int16_t inM, int16_t instruction_bits, int16_t reset, flip_flop *reg_a)
{

	int16_t type_of_instruction;
	int16_t value;

	type_of_instruction = instruction_bits >> 15;

	//Address Instruction (sets A register)
	if (type_of_instruction == 0) {
		set_ram(reg_a, 1, instruction_bits);
	}

	//Compute Instruction
	else if (type_of_instruction == 1) {
	}
}
