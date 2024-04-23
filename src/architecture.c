#include "architecture.h"
#include "arithmetic.h"
#include "binary.h"
#include "memory.h"

// TODO
// Test later
int16_t set_instruction_bits(
		uint16_t type_of_instruction,
		uint16_t mnem,
		uint16_t comp,
		uint16_t dest,
		uint16_t jump
)
{
	int16_t instruction_bits = 0;

	instruction_bits |= (type_of_instruction << 15);
	instruction_bits |= (mnem << 12);
	instruction_bits |= (comp << 6);
	instruction_bits |= (dest << 3);
	instruction_bits |= jump;

	return instruction_bits;
}

void cpu(int16_t instruction_bits, int16_t reset, memory_t *ram, registers_t *regs)
{
	// Instruction Capturing
	int16_t type_of_instruction;
	int16_t mnem_instruction; // Mnemonic Instruction bit
	int16_t comp_instruction;
	int16_t dest_instruction;
	int16_t jump_instruction;

	int16_t x_alu;
	int16_t y_alu;
	int16_t out_alu;
	int16_t zr_alu;
	int16_t ng_alu;

	type_of_instruction = (instruction_bits >> 15) & 0b1;
	mnem_instruction = (instruction_bits & 0b0001000000000000) >> 12;
	comp_instruction = (instruction_bits & 0b0000111111000000) >> 6;
	dest_instruction = (instruction_bits & 0b0000000000111000) >> 3;
	jump_instruction = instruction_bits & 0b0000000000000111;

	//Address Instruction (sets A register)
	if (type_of_instruction == 0) {
		set_register_A(regs, instruction_bits);
		inc_register_PC(regs);
	}
	else if (type_of_instruction == 1) {
		// Setting first input to ALU
		x_alu = get_register_D(regs);

		// Setting second input to ALU
		if (mnem_instruction == 1) {
			y_alu = get_register_M(regs, ram);
		}
		else if (mnem_instruction == 0){
			y_alu = get_register_A(regs);
		}

		alu(x_alu, y_alu, comp_instruction, &out_alu, &zr_alu, &ng_alu);

		// Destination
		if (dest_instruction & 0b001) {
			set_register_M(regs, ram, out_alu);
		}

		if (dest_instruction & 0b010) {
			set_register_D(regs, out_alu);
		}

		if (dest_instruction & 0b100) {
			set_register_A(regs, out_alu);
		}

		inc_register_PC(regs);
		print_binary(get_register_PC(regs));

		if (jump_instruction & 0b001 && (ng_alu & 0b1) != 0b1) {
			set_register_PC(regs, get_register_A(regs));
		}

		if (jump_instruction & 0b010 && (zr_alu & 0b1) == 0b0) {
			set_register_PC(regs, get_register_A(regs));
		}

		if (jump_instruction & 0b100 && (ng_alu & 0b1) == 0b1) {
			set_register_PC(regs, get_register_A(regs));
		}
	}

}
