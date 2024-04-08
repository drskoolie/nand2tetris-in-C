#include <stdbool.h>

#include "gates.h"

bool nand_gate(bool a, bool b) 
{
	return !(a && b);
}

bool and_gate(bool a, bool b)
{
	return (a && b);
}
