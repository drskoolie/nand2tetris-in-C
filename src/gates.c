#include "gates.h"
#inlude <stdbool.h>

bool nand_gate(bool a, bool b) {
	return !(a && b);
}
