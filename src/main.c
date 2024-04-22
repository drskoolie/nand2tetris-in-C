#include <stdio.h>
#include "binary.h"
#include "memory.h"

int main()
{
	registers_t regs;

	initialize_registers(&regs);

	print_binary(get_register_A(&regs));

	destroy_registers(&regs);
}
