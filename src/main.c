#include <stdio.h>

#include "gates.h"

int main()
{
	printf("%d\n", nand_gate(0,0));
	printf("%d\n", nand_gate(0,1));
	printf("%d\n", nand_gate(1,0));
	printf("%d\n", nand_gate(1,1));

	return 0;
}
