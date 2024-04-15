#ifndef SEQUENTIAL_H
#define SEQUENTIAL_H

#include <stdint.h>
#include <stdbool.h>

typedef struct {
	int16_t *in;
	int16_t intermediate;
	int16_t *out;
} flip_flop;

void tick_tock(void);
void tick(void);
void tock(void);
bool get_clock(void);
flip_flop *initialize_flip_flop();
void destroy_flip_flop(flip_flop *ff);
void update_flip_flop(flip_flop *ff);
void set_intermediate_flip_flop(flip_flop *ff, int16_t in);

#endif
