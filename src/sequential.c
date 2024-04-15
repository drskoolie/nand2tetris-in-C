#include <stdint.h>
#include <stdbool.h>
#include "sequential.h"

bool clock_state = 0;

void tick_tock() {
	clock_state ^= 1; // Toggle clock state (0 becomes 1, 1 becomes 0)
}

bool get_clock() {
	return clock_state;
}

void initialize_flip_flop(flip_flop *ff, int16_t *input, int16_t *output) {
    ff->in = input;
    ff->out = output;
    ff->intermediate = 0;
}

void update_flip_flop(flip_flop *ff) {
    if (clock_state == 1) {   // Rising edge: capture the current input
        ff->intermediate = *(ff->in);
    }
    else if (clock_state == 0) {  // Falling edge: update the output
        *(ff->out) = ff->intermediate;
    }
}

void set_intermediate_flip_flop(flip_flop *ff, int16_t in) { 

	ff->intermediate = in;
}

