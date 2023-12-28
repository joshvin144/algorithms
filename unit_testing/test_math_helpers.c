#include "../utilities/utilities_user.h"
#include "../math_helpers/math_helpers_user.h"
#include <stdbool.h>
#include <assert.h>


// Number of sample values to calculate
#define NUM_SAMPLES ( 21u )


// Manually calculated
static float sample_output[NUM_SAMPLES] = {0.0, 0.343, 0.653, 0.9, 1.2, 1.4, 1.6, 1.8, 2.0, 2.1,
	                                2.3, 2.4, 2.5, 2.6, 2.7, 2.8, 2.9, 2.9, 3.0, 3.1, 3.1};
static float expected_derivative[NUM_SAMPLES - 1u] = {0.343, 0.310, 0.280, 0.254, 0.230, 0.208, 0.188, 0.170, 0.154, 0.139,
                                              0.126, 0.114, 0.103, 0.093, 0.084, 0.076, 0.069, 0.063, 0.057, 0.051};
static float expected_riemman_sum[NUM_SAMPLES - 1u] = {0.0, 0.343, 0.995, 1.928, 3.115, 4.532, 6.156, 7.968, 9.951, 12.087,
                                               14.363, 16.764, 19.280, 21.899, 24.611, 27.408, 30.281, 33.223, 36.228, 39.290};
static float expected_trapezoid_sum[NUM_SAMPLES - 1u] = {0.171, 0.669, 1.462, 2.522, 3.823, 5.344, 7.062, 8.959, 11.0187, 13.225, 15.563,
                                                 18.022, 20.589, 23.255, 26.010, 28.844, 31.752, 34.726, 37.759, 40.846};
static float calculated_derivative[NUM_SAMPLES - 1u] = {0};



bool compare_same_size_arrays(float* p_expected, uint32_t size_expected, float* p_calculated, uint32_t size_calculated)
{
	assert( size_expected == size_calculated );
	bool matches_expectation = true;
	for ( uint32_t idx = 0u; idx < size_expected; idx++ )
	{
		if( p_expected[idx] != p_calculated[idx] )
		{
			matches_expectation = false;
		}
	}
	return matches_expectation;
}


bool test_calculate_derivative( void )
{
	bool matches_expectation = false;
	math_helpers_derivative(calculated_derivative, NUM_SAMPLES - 1u, sample_output, NUM_SAMPLES);
	for( uint32_t idx = 0u; idx < NUM_SAMPLES - 1u; idx++ )
	{
		calculated_derivative[idx] = round_to_three_decimal_places(calculated_derivative[idx]);
	}
	matches_expectation = compare_same_size_arrays(expected_derivative, NUM_SAMPLES - 1u, calculated_derivative, NUM_SAMPLES - 1u);
	return matches_expectation;
}


bool test_calculate_riemman_sum( void )
{
	bool matches_expectation = false;
	float calculated_sum = 0.0f;
	calculated_sum = math_helpers_riemman_sum_approximation(sample_output, NUM_SAMPLES);
	matches_expectation = (expected_riemman_sum[NUM_SAMPLES - 2u] == calculated_sum) ? true : false;
	return matches_expectation;
}


bool test_calculate_trapezoid_sum( void )
{
	bool matches_expectation = false;
	float calculated_sum = 0.0f;
	calculated_sum = math_helpers_trapezoid_approximation(sample_output, NUM_SAMPLES);
	matches_expectation = (expected_riemman_sum[NUM_SAMPLES - 2u] == calculated_sum) ? true : false;
	return matches_expectation;
}


int main( int argc, char* argv[] )
{
	assert( test_calculate_derivative() );
	assert( test_calculate_riemman_sum() );
	assert( test_calculate_trapezoid_sum() );
	printf( "All tests passed.\n" );
	return 0;
}