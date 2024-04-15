#include "sequential.h"

int main()
{
	flip_flop *ff0;

	ff0 = initialize_flip_flop();

	for (int i = 0; i < 4; i++) {
		*(ff0->in) = 100;
		print_flip_flop(ff0);
		tick_tock();
		update_flip_flop(ff0);
	}

	destroy_flip_flop(ff0);
}
