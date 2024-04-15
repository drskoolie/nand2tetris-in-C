#ifndef SEQUENTIAL_H
#define SEQUENTIAL_H

#include <stdint.h>
#include <stdbool.h>

typedef struct {
	int16_t *in;
	bool in_flag;
	int16_t intermediate;
	int16_t *out;
	bool out_flag;
} flip_flop;

void tick_tock(void);
void tick(void);
void tock(void);
bool get_clock(void);

flip_flop *initialize_flip_flop();
flip_flop **initialize_flip_flops(uint16_t num_flip_flops);
void destroy_flip_flop(flip_flop *ff);
void destroy_flip_flops(flip_flop **ffs, uint16_t num_flip_flops);
void update_flip_flop(flip_flop *ff);
void update_flip_flops(flip_flop **ffs, uint16_t num_flip_flops);
void print_flip_flop(flip_flop *ff);
void set_intermediate_flip_flop(flip_flop *ff, int16_t in);
void chain_flip_flops(flip_flop *ff0, flip_flop *ff1);

void update_ram_1(flip_flop *ff, int16_t select, int16_t in);
int16_t get_ram_1(flip_flop *ff);
void update_ram_x(flip_flop *ram_chips[], uint16_t num_flip_flops, uint16_t address, int16_t select, int16_t in);
int16_t get_ram_x(flip_flop *ram_chips[], uint16_t num_flip_flops, uint16_t address);

flip_flop *initialize_counter();
void update_counter(flip_flop *counter, int16_t inc, int16_t load, int16_t reset, int16_t in);
int16_t get_counter(flip_flop *counter);
void destroy_counter(flip_flop *counter);

#endif
