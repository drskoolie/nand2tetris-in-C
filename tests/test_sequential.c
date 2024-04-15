#include "unity.h"
#include "sequential.h"

void setUp(void) {}

void tearDown(void) {}

void test_clock(void)
{
	tick();
	TEST_ASSERT_EQUAL_INT(1, get_clock());
	tock();
	TEST_ASSERT_EQUAL_INT(0, get_clock());
	tick_tock();
	TEST_ASSERT_EQUAL_INT(1, get_clock());
	tick_tock();
	TEST_ASSERT_EQUAL_INT(0, get_clock());
}

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
	// This isn't really working, don't know how to make it work.
	flip_flop *ff;
	ff = initialize_flip_flop();
	TEST_ASSERT_NOT_NULL(ff);
	TEST_ASSERT_NOT_NULL(ff->in);
	TEST_ASSERT_NOT_NULL(ff->out);

	destroy_flip_flop(ff);
}

void test_flip_flop_tick_tock_0(void)
{
	flip_flop *ff;
	ff = initialize_flip_flop();

	*ff->in = 1;
	TEST_ASSERT_EQUAL_INT(1, *ff->in);
	TEST_ASSERT_EQUAL_INT(0, ff->intermediate);
	TEST_ASSERT_EQUAL_INT(0, *ff->out);

	destroy_flip_flop(ff);
}

void test_flip_flop_tick_tock_1(void)
{
	flip_flop *ff;
	ff = initialize_flip_flop();

	*ff->in = 1;

	tock();
	tick_tock();
	update_flip_flop(ff);
	TEST_ASSERT_EQUAL_INT(1, *ff->in);
	TEST_ASSERT_EQUAL_INT(1, ff->intermediate);
	TEST_ASSERT_EQUAL_INT(0, *ff->out);

	destroy_flip_flop(ff);
}

void test_flip_flop_tick_tock_2(void)
{
	flip_flop *ff;
	ff = initialize_flip_flop();

	*ff->in = 1;

	tock();
	tick_tock();
	update_flip_flop(ff);
	tick_tock();
	update_flip_flop(ff);
	TEST_ASSERT_EQUAL_INT(1, *ff->in);
	TEST_ASSERT_EQUAL_INT(1, ff->intermediate);
	TEST_ASSERT_EQUAL_INT(1, *ff->out);

	destroy_flip_flop(ff);
}

void test_chain_flip_flops(void)
{
	flip_flop *ff0;
	flip_flop *ff1;

	ff0 = initialize_flip_flop();
	ff1 = initialize_flip_flop();

	tock();
	chain_flip_flops(ff0, ff1);
	*ff0->in = 1;

	tick_tock();
	update_flip_flop(ff0);
	update_flip_flop(ff1);
	TEST_ASSERT_EQUAL_INT(0, *ff1->out);

	tick_tock();
	update_flip_flop(ff0);
	update_flip_flop(ff1);
	TEST_ASSERT_EQUAL_INT(0, *ff1->out);

	tick_tock();
	update_flip_flop(ff0);
	update_flip_flop(ff1);
	TEST_ASSERT_EQUAL_INT(0, *ff1->out);

	tick_tock();
	update_flip_flop(ff0);
	update_flip_flop(ff1);
	TEST_ASSERT_EQUAL_INT(1, *ff1->out);


	destroy_flip_flop(ff0);
	destroy_flip_flop(ff1);

}

void test_update_ram1_select_0(void)
{
	// Don't update output
	//
	flip_flop *ff;

	ff = initialize_flip_flop();

	*ff->in = 1;

	tock();
	update_ram_1(ff, 0, 10);
	TEST_ASSERT_EQUAL_INT(0, ff->intermediate);
	TEST_ASSERT_EQUAL_INT(0, *ff->out);

	tick();
	update_ram_1(ff, 0, 10);
	TEST_ASSERT_EQUAL_INT(0, ff->intermediate);
	TEST_ASSERT_EQUAL_INT(0, *ff->out);

	tock();
	update_ram_1(ff, 0, 10);
	TEST_ASSERT_EQUAL_INT(0, ff->intermediate);
	TEST_ASSERT_EQUAL_INT(0, *ff->out);

	destroy_flip_flop(ff);
}

void test_update_ram1_select_1(void)
{
	// Don't update output
	//
	flip_flop *ff;

	ff = initialize_flip_flop();

	tock();
	update_ram_1(ff, 1, 10);
	TEST_ASSERT_EQUAL_INT(0, ff->intermediate);
	TEST_ASSERT_EQUAL_INT(0, *ff->out);

	tick();
	update_ram_1(ff, 1, 10);
	TEST_ASSERT_EQUAL_INT(10, ff->intermediate);
	TEST_ASSERT_EQUAL_INT(0, *ff->out);

	tock();
	update_ram_1(ff, 1, 10);
	TEST_ASSERT_EQUAL_INT(10, ff->intermediate);
	TEST_ASSERT_EQUAL_INT(10, *ff->out);
	destroy_flip_flop(ff);
}

void test_initialize_flip_flops(void)
{
	uint16_t num_flip_flops = 10;
	flip_flop **ffs = initialize_flip_flops(num_flip_flops);

	for (int i = 0; i < num_flip_flops; i++) {
		TEST_ASSERT_EQUAL_INT(1, ffs[i]->in_flag);
		TEST_ASSERT_EQUAL_INT(0, *ffs[i]->in);
		TEST_ASSERT_EQUAL_INT(1, ffs[i]->out_flag);
		TEST_ASSERT_EQUAL_INT(0, *ffs[i]->out);
		TEST_ASSERT_EQUAL_INT(0, ffs[i]->intermediate);
	}

	destroy_flip_flops(ffs, num_flip_flops);
}

void test_update_ram_x(void)
{
	uint16_t num_flip_flops = 4;
	flip_flop **ffs = initialize_flip_flops(num_flip_flops);

	tock();
	for (int i = 0; i < num_flip_flops; i++) {
		update_ram_x(ffs, num_flip_flops, i, 1, i*5);
	}

	for (int i = 0; i < 4; i++) {
		tick();
		update_flip_flops(ffs, num_flip_flops);
		tock();
		update_flip_flops(ffs, num_flip_flops);
	}

	for (int i = 0; i < num_flip_flops; i++) {
		TEST_ASSERT_EQUAL_INT(i*5, *ffs[i]->out);
	}

	destroy_flip_flops(ffs, num_flip_flops);
}

void test_initialize_counter(void)
{
	flip_flop *counter;
	counter = initialize_counter();

	destroy_counter(counter);
}

int main(void)
{
	UNITY_BEGIN();

	RUN_TEST(test_clock);
	RUN_TEST(test_flip_flop_initialize);
	RUN_TEST(test_destroy_flip_flop);
	RUN_TEST(test_flip_flop_tick_tock_0);
	RUN_TEST(test_flip_flop_tick_tock_1);
	RUN_TEST(test_flip_flop_tick_tock_2);
	RUN_TEST(test_chain_flip_flops);
	RUN_TEST(test_update_ram1_select_0);
	RUN_TEST(test_update_ram1_select_1);
	RUN_TEST(test_initialize_flip_flops);
	RUN_TEST(test_update_ram_x);
	RUN_TEST(test_initialize_counter);

	return UNITY_END();
}
