#include <stdio.h>
#include "binary.h"
#include "memory.h"

int main()
{
	memory_t reg_a;

	initialize_memory(&reg_a, 1);

	print_binary(get_memory(&reg_a, 0));

	destroy_memory(&reg_a);
}
