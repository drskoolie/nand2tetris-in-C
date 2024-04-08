#include "unity.h"
#include "bit_array.h"
#include "gates.h"

void setUp(void) {}

void tearDown(void) {}

void test_nand_n_0(void)
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

	for (int i = 0; i < no_of_bits; i++) {
		TEST_ASSERT_EQUAL_INT(correct.bits[i], output_bits[i]);
	}
}


void test_nand_n_1(void)
{
	int no_of_bits = 6;
	int input0_bits[] = {0, 0, 1, 1, 0, 0};
	int input1_bits[] = {0, 1, 0, 1, 1, 0};
	int output_bits[6] = {0};

	int correct_bits[] = {1, 1, 1, 0, 1, 1};

	BitArray input0 = {input0_bits, no_of_bits};
	BitArray input1 = {input1_bits, no_of_bits};
	BitArray output = {output_bits, no_of_bits};
	BitArray correct = {correct_bits, no_of_bits};

	nand_n(input0, input1, &output);

	for (int i = 0; i < no_of_bits; i++) {
		TEST_ASSERT_EQUAL_INT(correct.bits[i], output_bits[i]);
	}
}

void test_and_n_0(void)
{
	int no_of_bits = 4;
	int input0_bits[] = {0, 0, 1, 1};
	int input1_bits[] = {0, 1, 0, 1};
	int output_bits[4] = {0};

	int correct_bits[] = {0, 0, 0, 1};

	BitArray input0 = {input0_bits, no_of_bits};
	BitArray input1 = {input1_bits, no_of_bits};
	BitArray output = {output_bits, no_of_bits};
	BitArray correct = {correct_bits, no_of_bits};

	and_n(input0, input1, &output);

	for (int i = 0; i < no_of_bits; i++) {
		TEST_ASSERT_EQUAL_INT(correct.bits[i], output_bits[i]);
	}
}


void test_and_n_1(void)
{
	int no_of_bits = 6;
	int input0_bits[] = {0, 0, 1, 1, 0, 0};
	int input1_bits[] = {0, 1, 0, 1, 1, 0};
	int output_bits[6] = {0};

	int correct_bits[] = {0, 0, 0, 1, 0, 0};

	BitArray input0 = {input0_bits, no_of_bits};
	BitArray input1 = {input1_bits, no_of_bits};
	BitArray output = {output_bits, no_of_bits};
	BitArray correct = {correct_bits, no_of_bits};

	and_n(input0, input1, &output);

	for (int i = 0; i < no_of_bits; i++) {
		TEST_ASSERT_EQUAL_INT(correct.bits[i], output_bits[i]);
	}
}


int main(void) {
	UNITY_BEGIN();
	
	RUN_TEST(test_nand_n_0);
	RUN_TEST(test_nand_n_1);
	RUN_TEST(test_and_n_0);
	RUN_TEST(test_and_n_1);

	return UNITY_END();
}
