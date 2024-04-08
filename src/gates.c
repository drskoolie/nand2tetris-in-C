#include "gates.h"

int nand_gate(int a, int b) 
{
	return !(a && b);
}

int and_gate(int a, int b)
{
	return (a && b);
}

int or_gate(int a, int b)
{
	return (a || b);
}

int not_gate(int a)
{
	return !a;
}

int xor_gate(int a, int b)
{
	return ((a && !b) || (!a && b));
}

int nor_gate(int a, int b)
{
	return !(a || b);
}
