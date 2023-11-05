#include "utilities.h"


void print_arr(uint32_t* p_arr, uint32_t array_length)
{
	assert(NULL != p_arr);
	assert(0u != array_length);

	for(uint32_t i = 0u; i <= (array_length - 1u); i++)
	{
		printf("p_arr[%u] = %u\n", i, p_arr[i]);
	}
}


uint32_t get_min(uint32_t* p_arr, uint32_t array_length)
{
	assert(NULL != p_arr);
	assert(0u != array_length);

	uint32_t idx = 0u;
	uint32_t current_min = p_arr[idx];
	for(uint32_t i = 1u; i <= (array_length - 1u); i++)
	{
		if(p_arr[i] < current_min)
		{
			idx = i;
			current_min = p_arr[i];
		}
	}
	return idx;
}


bool safe_memcpy(uint32_t* arr_to, uint32_t num_elements_in_arr_to, uint32_t* arr_from, uint32_t num_elements_in_arr_from, uint32_t num_elements_to_copy)
{
	assert(NULL != arr_to);
	assert(NULL != arr_from);
	assert(num_elements_to_copy <= num_elements_in_arr_to);
	assert(num_elements_to_copy <= num_elements_in_arr_from);

	bool successful_memcpy = false;
	uint32_t* memcpy_return = 0;
	memcpy_return = memcpy(arr_to, arr_from, num_elements_to_copy);
	if(arr_to == memcpy_return)
	{
		successful_memcpy = true;
	}
	return successful_memcpy;
}