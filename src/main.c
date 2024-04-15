#include <stdio.h>
#include <stdlib.h>
#include "sequential.h"

int main()
{
	flip_flop *ff0, *ff1;

	ff0 = initialize_flip_flop();
	ff1 = initialize_flip_flop();
	chain_flip_flops(ff0, ff1);
	for (int i = 0; i < 5; i++) {

		*(ff0->in) = 100;
		printf("FF0\n");
		print_flip_flop(ff0);
		printf("FF1\n");
		print_flip_flop(ff1);
		tick_tock();

		update_flip_flop(ff0);
		update_flip_flop(ff1);
	}

	destroy_flip_flop(ff0);
	destroy_flip_flop(ff1);
}
