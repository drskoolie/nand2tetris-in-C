#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "sequential.h"
#include "gates.h"

bool clock_state = 0;

void tick() {
	clock_state = 1;
}

void tock() {
	clock_state = 0;
}

void tick_tock() {
	clock_state ^= 1; // Toggle clock state (0 becomes 1, 1 becomes 0)
}

bool get_clock() {
	return clock_state;
}

flip_flop *initialize_flip_flop() {
	flip_flop *ff = malloc(sizeof(flip_flop));
	// Check if ff == NULL;
	ff->in = malloc(sizeof(int16_t));
	ff->in_flag = 1;
	// Check if ff->in == NULL;
	ff->out = malloc(sizeof(int16_t));
	ff->out_flag = 1;
	// Check if ff->out == NULL;
	*(ff->in) = 0;
	*(ff->out) = 0;
    ff->intermediate = 0;

	return ff;
}

void destroy_flip_flop(flip_flop *ff)
{
	if (ff != NULL) {
		if (ff->in != NULL && ff->in_flag) {
			free(ff->in);
		}

		if (ff->out != NULL && ff->out_flag) {
			free(ff->out);
		}

		free(ff);
	}
}

void update_flip_flop(flip_flop *ff)
{
	// Rising edge: capture the current input
    if (get_clock() == 1) {   
        ff->intermediate = *(ff->in);
    }
	// Falling edge: update the output
    else if (get_clock() == 0) {  
        *(ff->out) = ff->intermediate;
    }
}

void print_flip_flop(flip_flop *ff)
{
	printf("------------------------------\n");
	printf("Clock State: %d\n",  get_clock());
	printf("In: %d\n", *(ff->in));
	printf("Intermediate: %d\n", ff->intermediate);
	printf("Out: %d\n", *(ff->out));
	printf("------------------------------\n\n");
}

void set_intermediate_flip_flop(flip_flop *ff, int16_t intermediate)
{ 
	ff->intermediate = intermediate;
}

void chain_flip_flops(flip_flop *ff0, flip_flop *ff1)
{
	ff1->in = ff0->out;
	ff1->in_flag = 0;
}

void ram1(flip_flop *ff, int16_t select)
{
	// select = 0 --> out = out(t-1)
	// select = 1 --> out = in(t-1)
	int16_t intermediate;

	if (get_clock() == 1) {
		intermediate = mux(*ff->out, *ff->in, select);
		set_intermediate_flip_flop(ff, *ff->in);
	}
}
