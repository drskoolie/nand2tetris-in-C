#include <stdio.h>
#include <stdint.h>

#include "arithmetic.h"
#include "sequential.h"
#include "binary.h"
#include "gates.h"

int main()
{

	for (int i = 0; i < 10; i++) {
		printf("Clock State: %d\n", get_clock());
		tick_tock();
	}
}
