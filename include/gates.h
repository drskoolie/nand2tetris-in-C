#ifndef GATES_H
#define GATES_H

#include <stdint.h>

int16_t nand(int16_t in0, int16_t in1);
int16_t and(int16_t in0, int16_t in1);
int16_t or(int16_t in0, int16_t in1);
int16_t not(int16_t in);
int16_t xor(int16_t in0, int16_t in1);
int16_t mux(int16_t in0, int16_t in1, int16_t sel);
void demux(int16_t in, int16_t sel, int16_t *out0, int16_t *out1);

#endif
