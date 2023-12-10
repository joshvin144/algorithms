#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>
#include <assert.h>


#define VDDA ( 3.6f )
#define VREF ( VDDA )
#define ADC_RESOLUTION ( 12u )
#define OUTPUT_CODE_RANGE ( ( uint32_t ) ( exp2( ADC_RESOLUTION ) ) ) 
#define SINGLE_LSB ( VREF/ ( float ) OUTPUT_CODE_RANGE )


typedef struct{
	float reference_voltage;
	uint32_t output_code_range;
	float single_lsb;
} adc_t;