#include "utilities_user.h"


#define NUM_ELEMENTS       (16u)


static uint32_t arr_best_case[NUM_ELEMENTS] = {0u, 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u, 13u, 14u, 15u};
static uint32_t arr_worst_case[NUM_ELEMENTS] = {15u, 14u, 13u, 12u, 11u, 10u, 9u, 8u, 7u, 6u, 5u, 4u, 3u, 2u, 1u, 0u};


static stopwatch_t stopwatch;


void linear_sort(uint32_t* p_arr, uint32_t array_length)
{
	assert(NULL != p_arr);
	assert(0u != array_length);

	uint32_t idx = 0u;
	uint32_t temp = 0u;
	for(uint32_t i = 0u; i <= (array_length - 1u); i++)
	{
		// Get the minimum immediately after the last sorted element
		// Note that this updates the pointer to the start of the array
		// The index returned is relative to this pointer, (p_arr + i)
		// This index may be made relative to the original pointer by adding i to it, idx + i
		idx = get_min((p_arr + i), (array_length - i));
		printf("idx: %u\tmin: %u\n", idx, (p_arr + i)[idx]);
		temp = (p_arr + i)[idx];
		(p_arr + i)[idx] = p_arr[i];
		p_arr[i] = temp;
	}
}


bool test_sort()
{
	bool sort_done = false;

	// Set up the stopwatch
	stopwatch.p_stopwatch_on_entry = &sample_time_s;
	stopwatch.p_function = &linear_sort;
	stopwatch.p_stopwatch_on_exit = &sample_time_s;

    // Run the sort function through the stopwatch
	print_arr(arr_worst_case, NUM_ELEMENTS);
	run_stopwatch(&stopwatch, arr_worst_case, NUM_ELEMENTS);

	// Print the results
	print_arr(arr_worst_case, NUM_ELEMENTS);
	print_stopwatch(&stopwatch);

	sort_done = true;
	return sort_done;
}


int main(int argc, char* argv[])
{
	assert(test_sort());
	return 0;
}