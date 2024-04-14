#include "unity.h"
#include "gates.h"

void setUp(void) {}

void tearDown(void) {}

void test_nand(void)
{
	int16_t in0 = 0b1010;
	int16_t in1 = 0b1100;

	int16_t out = nand(in0, in1);

	TEST_ASSERT_EQUAL_INT(0b1111111111110111, out);
}

void test_and(void)
{
	int16_t in0 = 0b1010;
	int16_t in1 = 0b1100;

	int16_t out = and(in0, in1);

	TEST_ASSERT_EQUAL_INT(0b1000, out);
}


void test_or(void)
{
	int16_t in0 = 0b1010;
	int16_t in1 = 0b1100;

	int16_t out = or(in0, in1);

	TEST_ASSERT_EQUAL_INT(0b1110, out);
}

void test_not(void)
{
	int16_t in = 0b1010;

	int16_t out = not(in);

	TEST_ASSERT_EQUAL_INT(0b1111111111110101, out);
}

void test_xor(void)
{
	int16_t in0 = 0b1010;
	int16_t in1 = 0b1100;

	int16_t out = xor(in0, in1);

	TEST_ASSERT_EQUAL_INT(0b0110, out);
}

void test_mux(void)
{
	int16_t in0 = 0b1111;
	int16_t in1 = 0b0011;

	TEST_ASSERT_EQUAL_INT(in0, mux(in0, in1, 0b0));
	TEST_ASSERT_EQUAL_INT(in1, mux(in0, in1, 0b1));
}

void test_demux(void)
{
	int16_t in = 0b1111;
	int16_t out0 = 0b0000;
	int16_t out1 = 0b0000;

	demux(in, 0, &out0, &out1);
	TEST_ASSERT_EQUAL_INT(in, out0);
	TEST_ASSERT_EQUAL_INT(0b0000, out1);

	out0 = 0b0000;
	out1 = 0b0000;

	demux(in, 1, &out0, &out1);
	TEST_ASSERT_EQUAL_INT(in, out1);
	TEST_ASSERT_EQUAL_INT(0b0000, out0);

}

int main(void) 
{
	UNITY_BEGIN();
	
	RUN_TEST(test_nand);
	RUN_TEST(test_and);
	RUN_TEST(test_or);
	RUN_TEST(test_not);
	RUN_TEST(test_xor);
	RUN_TEST(test_mux);
	RUN_TEST(test_demux);

	return UNITY_END();
}
