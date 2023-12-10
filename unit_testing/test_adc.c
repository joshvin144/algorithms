#include "../utilities/utilities_user.h"
#include "../adc/adc_user.h"
#include <stdbool.h>
#include <assert.h>


#define NUM_SAMPLES 17


uint32_t predefined_output_code[NUM_SAMPLES] = {0, 256, 512, 768, 1024, 1280, 1536, 1792, 2048,
	                                            2304, 2560, 2816, 3072, 3328, 3584, 3840, 4096};
float expected_output_voltage[NUM_SAMPLES] = {0.0, 0.225, 0.45, 0.675, 0.9, 1.125, 1.35, 1.575,
	                                          1.8, 2.025, 2.25, 2.475, 2.7, 2.925, 3.15, 3.375, 3.6};
float calculated_output_voltage[NUM_SAMPLES] = {0};


bool test_adc_within_range( void )
{
	adc_init_adc_module();
	bool matches_expectation = true;
	for(int i = 0; i < NUM_SAMPLES; i++)
	{
		float temp = adc_calculate_voltage_from_output_code( predefined_output_code[i] );
		// It is necessary to round the calculated voltage to three decimal places to match the precision in the array of expected output voltages
		calculated_output_voltage[i] = round_to_three_decimal_places( temp );
		if( calculated_output_voltage[i] != expected_output_voltage[i] )
		{
			printf( "Mismatch at sample [ %d ]\tCalculated [ %.9f ]\tExpected [ %.9f ]\n", i, calculated_output_voltage[i], expected_output_voltage[i] );
			matches_expectation = false;
		}
	}

	return matches_expectation;
}


int main( int argc, char* argv[] )
{
	assert( test_adc_within_range() );
	printf( "All tests passed.\n" );
	return 0;
}