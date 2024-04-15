#ifndef SEQUENTIAL_H
#define SEQUENTIAL_H

#include <stdint.h>
#include <stdbool.h>

typedef struct {
	int16_t *in;
	int16_t intermediate;
	int16_t *out;
} FlipFlop;

void tick_tock(void);
bool get_clock(void);
int16_t dff(int16_t in);

#endif
