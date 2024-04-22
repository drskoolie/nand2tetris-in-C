#include <stdio.h>
#include "binary.h"
#include "memory.h"

int main()
{
	memory ram;
	memory reg_a;

	initialize_memory(&ram, 128);
	initialize_memory(&reg_a, 1);

	print_binary(get_memory(&reg_a, 0));
	set_memory(&reg_a, 0, 100);
	print_binary(get_memory(&reg_a, 0));
	print_binary(get_memory(&ram, 0));

	destroy_memory(&ram);
	destroy_memory(&reg_a);
}
