

#include "circuit_analysis.h"


// Instantiate a model of the RC circuit
static rc_circuit_t rc_circuit = {0};


static float rc_charge(float elapsed_time_s)
{
	// Calculate the RC time constant
	float tau_s = ( rc_circuit.r2_ohm * rc_circuit.c1_farad );
	float charge_voltage_v = ( rc_circuit.v_src ) * ( ( 1.0f ) - ( exp( ( -1.0f ) * elapsed_time_s / tau_s ) ) );
	return charge_voltage_v;
}


static float rc_decay(float elapsed_time_s)
{
	// Calculate the RC time constant
	float tau_s = ( rc_circuit.r2_ohm * rc_circuit.c1_farad );
	float decay_voltage_v = ( rc_circuit.v_cap ) * ( exp( ( -1.0f ) * elapsed_time_s / tau_s ) );
	return decay_voltage_v;
}


float circuit_analysis_init(void)
{
	rc_circuit.v_src = V_SRC;
	rc_circuit.v_cap = ( 0.0f );
	rc_circuit.r1_ohm = R1_OHM;
	rc_circuit.r2_ohm = R2_OHM;
	rc_circuit.c1_farad = C1_FARAD;
	rc_circuit.rc_charge = &rc_charge;
	rc_circuit.rc_decay = &rc_decay;
}


void circuit_analysis_update_cap_voltage(float v_cap)
{
	rc_circuit.vcap = v_cap;
}


float circuit_analysis_calculate_charge_voltage(float elapsed_time_s)
{
	return rc_charge(elapsed_time_s);
}


float circuit_analysis_calculate_decay_voltage(float elapsed_time_s)
{
	return rc_decay(elapsed_time_s);
}


float circuit_analysis_calculate_decay_derivative(float elapsed_time_s)
{
	;
}


float circuit_analysis_calculate_decay_integral(float elapsed_time_s)
{
	;
}


float circuit_analysis_calculate_charge_derivative(float elapsed_time_s)
{
	;
}


float circuit_analysis_calculate_charge_integral(float elapsed_time_s)
{
	;
}

