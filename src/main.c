#include <stdio.h>
#include "binary.h"
#include "memory.h"

int main()
{
	registers_t regs;

	initialize_registers(&regs);

	print_binary(regs.A.data[0]);

	destroy_registers(&regs);
}
