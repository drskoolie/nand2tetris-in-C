#include "unity.h"
#include "bit_array.h"
#include "gates.h"

void setUp(void) {}

void tearDown(void) {}

void test_bit_array_to_int_0(void)
{
	int no_of_bits = 4;
	int input_bits[] = {1, 0, 1, 0};
	int output;
	int correct = 10;

	BitArray input = {input_bits, no_of_bits};

	output = BitArray_to_int(&input);

	TEST_ASSERT_EQUAL_INT(output, correct);
}

void test_bit_array_to_int_1(void)
{
	int no_of_bits = 8;
	int input_bits[8] = {1};
	int output;
	int correct = 128;

	BitArray input = {input_bits, no_of_bits};

	output = BitArray_to_int(&input);

	TEST_ASSERT_EQUAL_INT(output, correct);
}

void test_bit_array_to_int_2(void)
{
	int no_of_bits = 2;
	int input_bits[2] = {0};
	int output;
	int correct = 0;

	BitArray input = {input_bits, no_of_bits};

	output = BitArray_to_int(&input);

	TEST_ASSERT_EQUAL_INT(output, correct);
}


int main(void) {
	UNITY_BEGIN();
	
	RUN_TEST(test_bit_array_to_int_0);
	RUN_TEST(test_bit_array_to_int_1);
	RUN_TEST(test_bit_array_to_int_2);

	return UNITY_END();
}
