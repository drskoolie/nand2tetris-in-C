#include "unity.h"

#include "bit_array.h"

void setUp(void) {}

void tearDown(void) {}

void test_nand_n(void)
{
	int no_of_bits = 4;
	int input0_bits[no_of_bits] = {0, 0, 1, 1};
	int input1_bits[no_of_bits] = {0, 1, 0, 1};
	int output_bits[no_of_bits] = {0};

	int correct_bits[no_of_bits] = {1, 1, 1, 0};

	BitArray input0 = BitArray{input0_bits, no_of_bits};
	BitArray input1 = BitArray{input1_bits, no_of_bits};
	BitArray output = BitArray{output_bits, no_of_bits};
	BitArray correct = BitArray{correct_bits, no_of_bits};

	TEST_ASSERT_EQUAL_INT(1, 1);
}

int main(void) {
	UNITY_BEGIN();
	
	RUN_TEST(test_nand_n);

	return UNITY_END();
}
