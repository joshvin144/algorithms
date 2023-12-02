#include "utilities_user.h"


#define NUM_ELEMENTS       (16u)


static uint32_t arr_best_case[NUM_ELEMENTS] = {0u, 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u, 13u, 14u, 15u};
static uint32_t arr_worst_case[NUM_ELEMENTS] = {15u, 14u, 13u, 12u, 11u, 10u, 9u, 8u, 7u, 6u, 5u, 4u, 3u, 2u, 1u, 0u};


void merge(uint32_t* p_arr, uint32_t lhs, uint32_t rhs)
{
	// Implementation
}


void merge_sort(uint32_t* p_arr, uint32_t lhs, uint32_t rhs)
{
	assert(NULL != p_arr);
	assert(0u != (rhs - lhs));

	uint32_t midpoint = lhs + ((rhs - lhs)/2u);

	// Base case
	if(1u == (rhs-lhs))
	{
		return;
	}
	else
	{
		merge_sort(p_arr, lhs, midpoint);
		merge_sort(p_arr, midpoint + 1, rhs);
		merge(p_arr, lhs, rhs);
	}
}


bool test_sort()
{
	bool sort_done = false;
	print_arr(arr_worst_case, NUM_ELEMENTS);
	print_arr(arr_worst_case, NUM_ELEMENTS);
	return sort_done;
}


int main(int argc, char* argv[])
{
	assert(test_sort());
	return 0;
}