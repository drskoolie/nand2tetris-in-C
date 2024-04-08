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

bool or_gate(bool a, bool b)
{
	return (a || b);
}

bool not_gate(bool a)
{
	return !a;
}

bool xor_gate(bool a, bool b)
{
	return ((a && !b) || (!a && b));
}

bool nor_gate(bool a, bool b)
{
	return !(a || b);
}
