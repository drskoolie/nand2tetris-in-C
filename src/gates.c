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

int mux_gate(int a, int b, int sel)
{
	return ((a && !sel) || (b && sel));
}

// Hacky way of getting two return values
// a = output[0] 
// b = output[1]
void demux_gate(int in, int sel, int outputs[2])
{
	outputs[0] = 0;
	outputs[1] = 0;

	if (sel == 0) {
		outputs[0] = in;
	} else {
		outputs[1] = in;
	}
}
