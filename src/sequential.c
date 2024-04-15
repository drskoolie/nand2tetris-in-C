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

flip_flop *initialize_flip_flop()
{
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

flip_flop **initialize_flip_flops(uint16_t num_flip_flops)
{
	flip_flop **ffs = malloc(num_flip_flops * sizeof(flip_flop *));
	// Handle memory allocation failure

	for (int i = 0; i < num_flip_flops; i++) {
		ffs[i] = initialize_flip_flop();
		// handle memory allocation failure for individuals
	}

	return ffs;
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

void destroy_flip_flops(flip_flop **ffs, uint16_t num_flip_flops)
{
	for (int i = 0; i < num_flip_flops; i++) {
		destroy_flip_flop(ffs[i]);
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

void update_flip_flops(flip_flop **ffs, uint16_t num_flip_flops)
{
	for (int i = 0; i < num_flip_flops; i++) {
		update_flip_flop(ffs[i]);
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

void update_ram_1(flip_flop *ff, int16_t select, int16_t in)
{
	// select = 0 --> out = out(t-1)
	// select = 1 --> out = in(t-1)
	int16_t intermediate;
	*ff->in = in;

	intermediate = mux(*ff->out, *ff->in, select);
	if (get_clock() == 1) {
		set_intermediate_flip_flop(ff, intermediate);
	}
	else if (get_clock() == 0) {
		update_flip_flop(ff);
	}
}

void update_ram_x(flip_flop *ram_chips[], uint16_t num_flip_flops, uint16_t address, int16_t select, int16_t in)
{

	// select = 0 --> out = out(t-1)
	// select = 1 --> out = in(t-1)
	if (address < num_flip_flops) {
		update_ram_1(ram_chips[address], select, in);
	}
}

int16_t get_ram_1(flip_flop *ff)
{
	return *ff->out;
}

int16_t get_ram_x(flip_flop *ram_chips[], uint16_t num_flip_flops, uint16_t address)
{
	if (address < num_flip_flops) {
		//
	}

	return get_ram_1(ram_chips[address]);
}

flip_flop *initialize_counter()
{
	return initialize_flip_flop();
}

void update_counter(flip_flop *counter, int16_t inc, int16_t load, int16_t reset, int16_t in)
{
	int16_t select = 0;

	select = inc | load | reset;

	if (reset == 1) {
		in = 0;
	}

	if (inc == 1) {
		in = *counter->out + 1;
	}

	update_ram_1(counter, select, in);
}

int16_t get_counter(flip_flop *counter)
{
	return get_ram_1(counter);
}

void destroy_counter(flip_flop *counter)
{
	destroy_flip_flop(counter);
}

// Change update to set
