#include <stdio.h>
#include <stdint.h>

#include "binary.h"
#include "gates.h"

int main()
{

	uint16_t in0 = 0b1100;
	uint16_t in1 = 0b1010;
	print_binary(nand(in0, in1));

				
	return 0;
}
