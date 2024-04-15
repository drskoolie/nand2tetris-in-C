#include "unity.h"
#include "sequential.h"

void setUp(void) {}

void tearDown(void) {}

void test_flip_flop_initialize(void)
{
	flip_flop *ff;
	ff = initialize_flip_flop();

	TEST_ASSERT_EQUAL_INT(1, ff->in_flag);
	TEST_ASSERT_EQUAL_INT(0, *ff->in);
	TEST_ASSERT_EQUAL_INT(1, ff->out_flag);
	TEST_ASSERT_EQUAL_INT(0, *ff->out);
	TEST_ASSERT_EQUAL_INT(0, ff->intermediate);

	destroy_flip_flop(ff);
}

void test_destroy_flip_flop(void)
{
	flip_flop *ff;
	ff = initialize_flip_flop();
	TEST_ASSERT_NOT_NULL(ff);
	TEST_ASSERT_NOT_NULL(ff->in);
	TEST_ASSERT_NOT_NULL(ff->out);

	destroy_flip_flop(ff);
}

int main(void)
{
	UNITY_BEGIN();

	RUN_TEST(test_flip_flop_initialize);
	RUN_TEST(test_destroy_flip_flop);

	return UNITY_END();
}
