#include <stdint.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>
#include <stdio.h>


#define ARBITRARY_NUM_ELEMENTS (8u)
#define MAX_NUM_ELEMENTS       (16u)


static uint32_t arr_to[ARBITRARY_NUM_ELEMENTS];
static uint32_t arr_from[MAX_NUM_ELEMENTS];


/*
 * @param  : The array to copy to
 * @param  : The number of elements in the array to copy to
 * @param  : The array to copy from
 * @param  : The number of elements in the array to copy from
 * @param  : The number of elements to copy
 * @return : Whether the memcpy was a success or not
 */
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


/*
 * @param  : None
 * @return : Whether the memcpy operation was successful or not
 */
bool test_memcpy(void)
{
	bool successful_memcpy = false;
	successful_memcpy = safe_memcpy(arr_to, ARBITRARY_NUM_ELEMENTS, arr_from, MAX_NUM_ELEMENTS, ARBITRARY_NUM_ELEMENTS);
	return successful_memcpy;
}


int main(int argc, char* argv[])
{
	assert(test_memcpy());
	return 0;
}