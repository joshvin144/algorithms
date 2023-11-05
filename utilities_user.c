#include "utilities_user.h"


void sample_time_s(time_t* p_time_s)
{
	assert(NULL != p_time_s);

	*p_time_s = time(NULL);
}


void run_stopwatch(stopwatch_t* p_stopwatch, uint32_t* p_arr, uint32_t array_length)
{
	assert(NULL != p_stopwatch);
	assert(NULL != p_arr);
	assert(0u < array_length);

	p_stopwatch->p_stopwatch_on_entry(&p_stopwatch->start_time_s);
	p_stopwatch->p_function(p_arr, array_length);
	p_stopwatch->p_stopwatch_on_exit(&p_stopwatch->stop_time_s);
	p_stopwatch->elapsed_time_s = p_stopwatch->stop_time_s - p_stopwatch->start_time_s;
}


void print_stopwatch(stopwatch_t* p_stopwatch)
{
	printf("Start Time [s]:\t%f\n", (float) p_stopwatch->start_time_s);
	printf("Stop Time [s]:\t%f\n", (float) p_stopwatch->stop_time_s);
	printf("Elapsed Time [s]:\t%f\n", (float) p_stopwatch->elapsed_time_s);
}


