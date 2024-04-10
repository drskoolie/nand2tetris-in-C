#ifndef GATES_H
#define GATES_H

uint16_t nand(uint16_t in0, uint16_t in1);
uint16_t and(uint16_t in0, uint16_t in1);
uint16_t or(uint16_t in0, uint16_t in1);
uint16_t not(uint16_t in);
uint16_t xor(uint16_t in0, uint16_t in1);
uint16_t mux(uint16_t in0, uint16_t in1, uint16_t sel);
void demux(uint16_t in, uint16_t sel, uint16_t *out0, uint16_t *out1);

#endif
