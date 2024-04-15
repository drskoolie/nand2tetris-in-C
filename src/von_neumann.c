#include "von_neumann.h"
#include "arithmetic.h"

void cpu(int16_t inM, int16_t instruction_bits, int16_t reset)
{

	int16_t type_of_instruction;

	type_of_instruction = instruction_bits >> 15;

	//Address Instruction (sets A register)
	if (type_of_instruction == 0) {
	}

	//Compute Instruction
	else if (type_of_instruction == 1) {
	}
}
