#include "../utilities/utilities_user.h"
#include "../math_helpers/math_helpers_user.h"
#include <stdbool.h>
#include <assert.h>


// Number of sample values to calculate
#define NUM_SAMPLES ( 21u )


// Manually calculated
float sample_output[NUM_SAMPLES] = {0.0,
0.652569288919265, 1.1868478342717, 1.6242781100615, 1.982415729178, 2.27563401178281,
2.51570083711607, 2.71225092981022, 2.87317253521924, 3.00492400240229, 3.11279298034819,
3.2011086298956, 3.27341536815811, 3.3326151184284, 3.38108377454922, 3.42076655387569,
3.45325606567788, 3.47985622814283, 3.50163459918975, 3.5194652213178, 3.53406370000056};
float expected_derivative[NUM_SAMPLES - 1u] = {0.652569288919265, 0.534278545352435, 0.4374302757898, 0.3581376191165, 0.29321828260481,
0.24006682533326, 0.19655009269415, 0.16092160540902, 0.13175146718305, 0.1078689779459,
0.08831564954741, 0.07230673826251, 0.05919975027029, 0.04846865612082, 0.03968277932647,
0.03248951180219, 0.02660016246495, 0.02177837104692, 0.01783062212805, 0.01459847868276};
float expected_riemman_sum[NUM_SAMPLES - 1u] = {0.0, 0.652569288919265, 1.83941712319097, 3.46369523325247, 5.44611096243047,
7.72174497421328, 10.2374458113293, 12.9496967411396, 15.8228692763588, 18.8277932787611,
21.9405862591093, 25.1416948890049, 28.415110257163, 31.7477253755914, 35.1288091501406,
38.5495757040163, 42.0028317696942, 45.482687997837, 48.9843225970268, 52.5037878183446};
float expected_trapezoid_sum[NUM_SAMPLES - 1u] = {0.326284644459633, 1.24599320605512, 2.65155617822172, 4.45490309784147, 6.58392796832188,
8.97959539277132, 11.5935712762345, 14.3862830087492, 17.32533127756, 20.3841897689352,
23.5411405740571, 26.778402573084, 30.0814178163772, 33.438267262866, 36.8391924270785,
40.2762037368553, 43.7427598837656, 47.2335052974319, 50.7440552076857, 54.2708196683449};
float calculated_derivative[NUM_SAMPLES - 1u] = {0};


bool compare_same_size_arrays(float* p_expected, uint32_t size_expected, float* p_calculated, uint32_t size_calculated)
{
	assert( size_expected == size_calculated );
	bool matches_expectation = true;
	for ( uint32_t idx = 0u; idx < size_expected; idx++ )
	{
		if( p_expected[idx] != p_calculated[idx] )
		{
			printf( "Mismatch at sample [ %d ]\tCalculated [ %.9f ]\tExpected [ %.9f ]\n", idx, p_calculated[idx], p_expected[idx] );
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
		expected_derivative[idx] = round_to_three_decimal_places(expected_derivative[idx]);
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
	calculated_sum = round_to_three_decimal_places(calculated_sum);
	printf("%.9f\t%.9f\n", expected_riemman_sum[NUM_SAMPLES - 2u], calculated_sum);
	matches_expectation = ( expected_riemman_sum[NUM_SAMPLES - 2u] == calculated_sum ) ? true : false;
	return matches_expectation;
}


bool test_calculate_trapezoid_sum( void )
{
	bool matches_expectation = false;
	float calculated_sum = 0.0f;
	calculated_sum = math_helpers_trapezoid_approximation(sample_output, NUM_SAMPLES);
	calculated_sum = round_to_three_decimal_places(calculated_sum);
	printf("%.9f\t%.9f\n", expected_trapezoid_sum[NUM_SAMPLES - 2u], calculated_sum);
	matches_expectation = ( expected_trapezoid_sum[NUM_SAMPLES - 2u] == calculated_sum ) ? true : false;
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