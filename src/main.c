#include <stdio.h>
#include <stdlib.h>

#include "gates.h"

int main()
{

	int no_of_bits = 8;
	int bits[8];

	BitArray input1 = initializeBitArray(bits, no_of_bits);

	for (int i = 0; i < input1.no_of_bits; i++) {
		input1.bits[i] = i;
	}

	input1.print(&input1);

	return 0;
}
