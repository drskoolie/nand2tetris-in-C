#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "gates.h"

uint16_t nand(uint16_t in0, uint16_t in1)
{
	return in0 & in1;
}
