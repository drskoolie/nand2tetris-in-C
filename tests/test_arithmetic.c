#include "unity.h"
#include "arithmetic.h"

void setUp(void) {}

void tearDown(void) {}

void test_half_adder_sum(void)
{
	uint16_t a;
	uint16_t b;

	a = 0b0;
	b = 0b0;
	TEST_ASSERT_EQUAL_INT(0, half_adder_sum(a, b));

	a = 0b0;
	b = 0b1;
	TEST_ASSERT_EQUAL_INT(1, half_adder_sum(a, b));

	a = 0b1;
	b = 0b0;
	TEST_ASSERT_EQUAL_INT(1, half_adder_sum(a, b));

	a = 0b1;
	b = 0b1;
	TEST_ASSERT_EQUAL_INT(0, half_adder_sum(a, b));
}

void test_half_adder_carry(void)
{
	uint16_t a;
	uint16_t b;

	a = 0b0;
	b = 0b0;
	TEST_ASSERT_EQUAL_INT(0, half_adder_carry(a, b));

	a = 0b0;
	b = 0b1;
	TEST_ASSERT_EQUAL_INT(0, half_adder_carry(a, b));

	a = 0b1;
	b = 0b0;
	TEST_ASSERT_EQUAL_INT(0, half_adder_carry(a, b));

	a = 0b1;
	b = 0b1;
	TEST_ASSERT_EQUAL_INT(1, half_adder_carry(a, b));
}

void test_full_adder_sum(void)
{
	uint16_t a;
	uint16_t b;
	uint16_t carry_in;

	a = 0b0;
	b = 0b0;
	carry_in = 0b0;
	TEST_ASSERT_EQUAL_INT(0, full_adder_sum(a, b, carry_in));

	a = 0b0;
	b = 0b0;
	carry_in = 0b1;
	TEST_ASSERT_EQUAL_INT(1, full_adder_sum(a, b, carry_in));

	a = 0b0;
	b = 0b1;
	carry_in = 0b0;
	TEST_ASSERT_EQUAL_INT(1, full_adder_sum(a, b, carry_in));

	a = 0b0;
	b = 0b1;
	carry_in = 0b1;
	TEST_ASSERT_EQUAL_INT(0, full_adder_sum(a, b, carry_in));

	a = 0b1;
	b = 0b0;
	carry_in = 0b0;
	TEST_ASSERT_EQUAL_INT(1, full_adder_sum(a, b, carry_in));

	a = 0b1;
	b = 0b0;
	carry_in = 0b1;
	TEST_ASSERT_EQUAL_INT(0, full_adder_sum(a, b, carry_in));

	a = 0b1;
	b = 0b1;
	carry_in = 0b0;
	TEST_ASSERT_EQUAL_INT(0, full_adder_sum(a, b, carry_in));

	a = 0b1;
	b = 0b1;
	carry_in = 0b1;
	TEST_ASSERT_EQUAL_INT(1, full_adder_sum(a, b, carry_in));
}

void test_full_adder_carry(void)
{
	uint16_t a;
	uint16_t b;
	uint16_t carry_in;

	a = 0b0;
	b = 0b0;
	carry_in = 0b0;
	TEST_ASSERT_EQUAL_INT(0, full_adder_carry(a, b, carry_in));

	a = 0b0;
	b = 0b0;
	carry_in = 0b1;
	TEST_ASSERT_EQUAL_INT(0, full_adder_carry(a, b, carry_in));

	a = 0b0;
	b = 0b1;
	carry_in = 0b0;
	TEST_ASSERT_EQUAL_INT(0, full_adder_carry(a, b, carry_in));

	a = 0b0;
	b = 0b1;
	carry_in = 0b1;
	TEST_ASSERT_EQUAL_INT(1, full_adder_carry(a, b, carry_in));

	a = 0b1;
	b = 0b0;
	carry_in = 0b0;
	TEST_ASSERT_EQUAL_INT(0, full_adder_carry(a, b, carry_in));

	a = 0b1;
	b = 0b0;
	carry_in = 0b1;
	TEST_ASSERT_EQUAL_INT(1, full_adder_carry(a, b, carry_in));

	a = 0b1;
	b = 0b1;
	carry_in = 0b0;
	TEST_ASSERT_EQUAL_INT(1, full_adder_carry(a, b, carry_in));

	a = 0b1;
	b = 0b1;
	carry_in = 0b1;
	TEST_ASSERT_EQUAL_INT(1, full_adder_carry(a, b, carry_in));
}

int main(void)
{
	UNITY_BEGIN();
	
	RUN_TEST(test_half_adder_sum);
	RUN_TEST(test_half_adder_carry);
	RUN_TEST(test_full_adder_sum);
	RUN_TEST(test_full_adder_carry);

	return UNITY_END();
}
