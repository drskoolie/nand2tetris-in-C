#include "unity.h"
#include "arithmetic.h"

void setUp(void) {}

void tearDown(void) {}

void test_half_adder_sum(void)
{
	int16_t a;
	int16_t b;

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
	int16_t a;
	int16_t b;

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
	int16_t a;
	int16_t b;
	int16_t carry_in;

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
	int16_t a;
	int16_t b;
	int16_t carry_in;

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

void test_adder(void)
{
	int16_t a;
	int16_t b;

	a = 10;
	b = 20;
	TEST_ASSERT_EQUAL_INT(30, adder(a, b));

	a = 20;
	b = 20;
	TEST_ASSERT_EQUAL_INT(40, adder(a, b));

	a = 0;
	b = 20;
	TEST_ASSERT_EQUAL_INT(20, adder(a, b));

	a = 20;
	b = 0;
	TEST_ASSERT_EQUAL_INT(20, adder(a, b));

}

void test_incrementer(void)
{
	int16_t a = 0;
	TEST_ASSERT_EQUAL_INT(1, incrementer(a));
}

void test_alu_zx(void)
{
	int16_t instruction_bits;
	int16_t x = 0b1111;
	int16_t y = 0;

	int16_t out = 0b1111;
	int16_t zr = 1;
	int16_t ng = 1;

	instruction_bits = 0b100010;
	alu(x, y, instruction_bits, &out, &zr, &ng);
	TEST_ASSERT_EQUAL_INT(0, out);
	TEST_ASSERT_EQUAL_INT(1, zr);
	TEST_ASSERT_EQUAL_INT(0, ng);

	y = 10;
	instruction_bits = 0b100010;
	alu(x, y, instruction_bits, &out, &zr, &ng);
	TEST_ASSERT_EQUAL_INT(y, out);
	TEST_ASSERT_EQUAL_INT(0, zr);
	TEST_ASSERT_EQUAL_INT(0, ng);
}

void test_alu_zy(void)
{
	int16_t instruction_bits;
	int16_t x = 0b1111;
	int16_t y = 0b1111;

	int16_t out = 0b1111;
	int16_t zr = 0;
	int16_t ng = 1;

	instruction_bits = 0b001010;
	alu(x, y, instruction_bits, &out, &zr, &ng);
	TEST_ASSERT_EQUAL_INT(x, out);
	TEST_ASSERT_EQUAL_INT(0, zr);
	TEST_ASSERT_EQUAL_INT(0, ng);

	x = 0;
	instruction_bits = 0b001010;
	alu(x, y, instruction_bits, &out, &zr, &ng);
	TEST_ASSERT_EQUAL_INT(0, out);
	TEST_ASSERT_EQUAL_INT(1, zr);
	TEST_ASSERT_EQUAL_INT(0, ng);
}

void test_alu_zero(void)
{
	int16_t instruction_bits;
	int16_t x = 0b1111;
	int16_t y = 0;
	int16_t zr = 0;
	int16_t ng = 1;

	int16_t out;
	instruction_bits = 0b101010;

	alu(x, y, instruction_bits, &out, &zr, &ng);
	TEST_ASSERT_EQUAL_INT(0, out);
}


void test_alu_one(void)
{
	int16_t instruction_bits;
	int16_t x = 0b1111;
	int16_t y = 0;
	int16_t zr = 0;
	int16_t ng = 1;

	int16_t out;
	instruction_bits = 0b111111;

	alu(x, y, instruction_bits, &out, &zr, &ng);
	TEST_ASSERT_EQUAL_INT(1, out);
}

void test_alu_negative_one(void)
{
	int16_t instruction_bits;
	int16_t x = 0b1111;
	int16_t y = 0;
	int16_t zr = 0;
	int16_t ng = 1;

	int16_t out;
	instruction_bits = 0b111010;

	alu(x, y, instruction_bits, &out, &zr, &ng);
	TEST_ASSERT_EQUAL_INT(-1, out);
}


int main(void)
{
	UNITY_BEGIN();
	
	RUN_TEST(test_half_adder_sum);
	RUN_TEST(test_half_adder_carry);
	RUN_TEST(test_full_adder_sum);
	RUN_TEST(test_full_adder_carry);
	RUN_TEST(test_adder);
	RUN_TEST(test_incrementer);
	RUN_TEST(test_alu_zx);
	RUN_TEST(test_alu_zy);
	RUN_TEST(test_alu_zero);
	RUN_TEST(test_alu_one);
	RUN_TEST(test_alu_negative_one);

	return UNITY_END();
}
