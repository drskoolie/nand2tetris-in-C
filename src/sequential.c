#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include "sequential.h"

bool clock_state = 0;

void tick_tock() {
	clock_state ^= 1; // Toggle clock state (0 becomes 1, 1 becomes 0)
}

bool get_clock() {
	return clock_state;
}

flip_flop *initialize_flip_flop() {
	flip_flop *ff = malloc(sizeof(flip_flop));
	// Check if ff == NULL;
	*(ff->in) = 0;
	*(ff->out) = 0;
    ff->intermediate = 0;

	return ff;
}

void destroy_flip_flop(flip_flop *ff)
{
	if (ff != NULL) {
		free(ff);
	}
}

void update_flip_flop(flip_flop *ff) {
    if (get_clock() == 1) {   // Rising edge: capture the current input
        ff->intermediate = *(ff->in);
    }
    else if (get_clock() == 0) {  // Falling edge: update the output
        *(ff->out) = ff->intermediate;
    }
}

void set_intermediate_flip_flop(flip_flop *ff, int16_t in) { 

	ff->intermediate = in;
}
