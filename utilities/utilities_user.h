#include "utilities.h"


typedef struct {
	time_t start_time_s;
	time_t stop_time_s;
	time_t elapsed_time_s;

	void (*p_stopwatch_on_entry) (time_t*);
	void (*p_function) (uint32_t*, uint32_t);
	void (*p_stopwatch_on_exit) (time_t*);
} stopwatch_t;


void sample_time_s(time_t* p_time_s);


void run_stopwatch(stopwatch_t* p_stopwatch, uint32_t* p_arr, uint32_t array_length);


void print_stopwatch(stopwatch_t* p_stopwatch);


void print_arr(uint32_t* p_arr, uint32_t array_length);


uint32_t get_min(uint32_t* p_arr, uint32_t array_length);


/*
 * @param  : The array to copy to
 * @param  : The number of elements in the array to copy to
 * @param  : The array to copy from
 * @param  : The number of elements in the array to copy from
 * @param  : The number of elements to copy
 * @return : Whether the memcpy was a success or not
 */
bool safe_memcpy(uint32_t* arr_to, uint32_t num_elements_in_arr_to, uint32_t* arr_from, uint32_t num_elements_in_arr_from, uint32_t num_elements_to_copy);


float round_to_three_decimal_places( float value );