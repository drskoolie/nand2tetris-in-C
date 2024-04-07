#include "gates.h"
#include <stdbool.h>

bool nand_gate(bool a, bool b) 
{
	return !(a && b);
}
