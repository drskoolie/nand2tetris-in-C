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

int main(void)
{
	UNITY_BEGIN();

	RUN_TEST(test_flip_flop_initialize);

	return UNITY_END();
}
