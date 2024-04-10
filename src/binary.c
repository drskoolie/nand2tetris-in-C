#include <stdio.h>
#include <stdint.h>

void print_binary(int16_t input)
{
	printf("Decimal: %u\n", input);
	printf("Hex: 0x%X\n", input);
	printf("Binary: ");
	for (int i = 15; i >= 0; --i) {
		printf("%d", (input >> i) & 1);
		if (i % 4 == 0) {
			printf(" ");
		}
	}
	printf("\n");
}
