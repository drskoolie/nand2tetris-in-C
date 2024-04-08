#include <stdio.h>
#include <stdlib.h>

#include "gates.h"

int main()
{

	int no_of_bits = 8;
	int bits[8] = {0};

	BitArray input1 = initializeBitArray(bits, no_of_bits);

	input1.print(&input1);

	return 0;
}
