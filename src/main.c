#include <stdio.h>
#include <stdint.h>

#include "arithmetic.h"
#include "binary.h"
#include "gates.h"

int main()
{

	uint16_t a = 0b1010;
	uint16_t b = 0b1100;

	adder(a, b);
}
