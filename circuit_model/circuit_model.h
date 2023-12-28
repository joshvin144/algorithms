

#include <stdio.h>
#include <stdint.h>
#include <math.h>


#define V_SRC    ( 5.0f )
#define R1_OHM   ( 10000.0f )
#define R2_OHM   ( 10000.0f )
#define C1_FARAD ( 0.000100f )


/*
 * Data structure to model an RC circuit
 */
typedef struct {
	float v_src;
	float v_cap;
	float r1_ohm;
	float r2_ohm;
	float c1_farad;
	float (*charge_function) (float elapsed_time_s);
	float (*decay_function) (float elapsed_time_s);
} rc_circuit_t;

