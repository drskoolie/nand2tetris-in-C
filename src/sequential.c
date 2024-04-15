#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "sequential.h"

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
	// Check if ff->in == NULL;
	ff->out = malloc(sizeof(int16_t));
	// Check if ff->out == NULL;
	*(ff->in) = 0;
	*(ff->out) = 0;
    ff->intermediate = 0;

	return ff;
}

void destroy_flip_flop(flip_flop *ff)
{
	if (ff->in != NULL) {
		free(ff->in);
		ff->in = NULL;
	}

	if (ff->out != NULL) {
		free(ff->out);
		ff->out = NULL;
	}

	if (ff != NULL) {
		free(ff);
		ff = NULL;
	}
}

void update_flip_flop(flip_flop *ff)
{
    if (get_clock() == 1) {   // Rising edge: capture the current input
        ff->intermediate = *(ff->in);
    }
    else if (get_clock() == 0) {  // Falling edge: update the output
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
