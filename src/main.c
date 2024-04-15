#include <stdio.h>
#include <stdint.h>

#include "sequential.h"

int main()
{
	flip_flop *ff0;

	ff0 = initialize_flip_flop();

	for (int i = 0; i < 10; i++) {
		*(ff0->in) = 1;
		printf("------------------------------\n");
		printf("i: %d | Clock State: %d\n", i, get_clock());
		printf("In: %d\n", *(ff0->in));
		printf("Intermediate: %d\n", ff0->intermediate);
		printf("Out: %d\n", *(ff0->out));
		tick_tock();
		update_flip_flop(ff0);

		if (i == 3) {
			set_intermediate_flip_flop(ff0, 10);
			tock();
			update_flip_flop(ff0);
		}
	}

	destroy_flip_flop(ff0);
}
