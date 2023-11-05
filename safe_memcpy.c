#include "utilities_user.h"


#define ARBITRARY_NUM_ELEMENTS (8u)
#define MAX_NUM_ELEMENTS       (16u)


static uint32_t arr_to[ARBITRARY_NUM_ELEMENTS];
static uint32_t arr_from[MAX_NUM_ELEMENTS];


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