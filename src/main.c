#include <stdio.h>
#include <stdint.h>

#include "binary.h"
#include "gates.h"

int main()
{

	uint16_t in0 = 0b1100;
	uint16_t in1 = 0b0011;

	uint16_t out = mux(in0, in1, 1);

	print_binary(and(0b1101101, 0b1));
				
	return 0;
}
