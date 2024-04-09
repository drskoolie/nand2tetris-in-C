#include <stdio.h>
#include <stdlib.h>

#include "gates.h"

int main()
{

	int no_of_bits = 8;
	int bits[8] = {0};

	BitArray input1 = {bits, no_of_bits};

	print_BitArray(&input1);

	return 0;
}
