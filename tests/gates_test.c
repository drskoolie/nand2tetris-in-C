#include "unity.h"

#include "bit_array.h"
#include "gates.h"

void setUp(void) {}

void tearDown(void) {}

void test_nand_n(void)
{
	int no_of_bits = 4;
	int input0_bits[] = {0, 0, 1, 1};
	int input1_bits[] = {0, 1, 0, 1};
	int output_bits[4] = {0};

	int correct_bits[] = {1, 1, 1, 0};

	BitArray input0 = {input0_bits, no_of_bits};
	BitArray input1 = {input1_bits, no_of_bits};
	BitArray output = {output_bits, no_of_bits};
	BitArray correct = {correct_bits, no_of_bits};

	nand_n(input0, input1, &output);

	TEST_ASSERT_EQUAL_INT(1, 1);
}

int main(void) {
	UNITY_BEGIN();
	
	RUN_TEST(test_nand_n);

	return UNITY_END();
}
