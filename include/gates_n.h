#ifndef GATES_N_H
#define GATES_N_H

int nand_gate(int a, int b);
int and_gate(int a, int b);
int or_gate(int a, int b);
int not_gate(int a);
int xor_gate(int a, int b);
int nor_gate(int a, int b);
int mux_gate(int a, int b, int sel);
void demux_gate(int in, int sel, int outputs[2]);

#endif
