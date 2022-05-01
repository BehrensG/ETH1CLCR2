/*
 * calculate.c
 *
 *  Created on: Apr 12, 2022
 *      Author: grzegorz
 */

#include <math.h>
#include <result.h>

static void Result_Reset();
static double Result_Capacitor();


void Result()
{

	Result_Reset();

	if(ADC_ADS8681 == bsp.config.adc_select)
	{
		for(uint16_t x=0; x < bsp.config.ads8681.sample_size;x++)
		{
			bsp.result.volt_real += bsp.measure.voltage.wave[x]*cos(2*PI*x/bsp.config.ads8681.sample_size);
			bsp.result.volt_imag += bsp.measure.voltage.wave[x]*sin(2*PI*x/bsp.config.ads8681.sample_size);
			bsp.result.curr_real += bsp.measure.current.wave[x]*cos(2*PI*x/bsp.config.ads8681.sample_size);
			bsp.result.curr_imag += bsp.measure.current.wave[x]*sin(2*PI*x/bsp.config.ads8681.sample_size);
		}

	}
	else if(ADC_CS5361 == bsp.config.adc_select)
	{

	}

	bsp.result.curr_real /= bsp.config.resistor_value;
	bsp.result.curr_imag /= bsp.config.resistor_value;

	bsp.result.z_real = (bsp.result.volt_real * bsp.result.curr_real + bsp.result.volt_imag * bsp.result.curr_imag) / (bsp.result.curr_real * bsp.result.curr_real + bsp.result.curr_imag * bsp.result.curr_imag);
	bsp.result.z_imag = (bsp.result.volt_imag * bsp.result.curr_real - bsp.result.volt_real * bsp.result.curr_imag) / (bsp.result.curr_real * bsp.result.curr_real + bsp.result.curr_imag * bsp.result.curr_imag);
	bsp.result.y_real = (bsp.result.volt_real * bsp.result.curr_real + bsp.result.volt_imag * bsp.result.curr_imag) / (bsp.result.volt_real * bsp.result.volt_real + bsp.result.volt_imag * bsp.result.volt_imag);
	bsp.result.y_imag = (bsp.result.volt_real * bsp.result.curr_imag - bsp.result.volt_imag * bsp.result.curr_real) / (bsp.result.volt_real * bsp.result.volt_real + bsp.result.volt_imag * bsp.result.volt_imag);

	bsp.result.CS = Result_Capacitor();


	// Test
}

static double Result_Capacitor()
{
	return 1/(2*PI*bsp.config.frequency*fabs(bsp.result.z_imag));
}

static void Result_Reset()
{
	bsp.result.volt_real = 0;
	bsp.result.volt_imag = 0;
	bsp.result.curr_real = 0;
	bsp.result.curr_imag = 0;

	bsp.result.z_real = 0;
	bsp.result.z_imag = 0;
	bsp.result.y_real = 0;
	bsp.result.y_imag = 0;

	bsp.result.REAL = 0;
	bsp.result.IMAG = 0;
	bsp.result.MLIN = 0;
	bsp.result.CP = 0;
	bsp.result.CS = 0;
	bsp.result.LP = 0;
	bsp.result.LS = 0;
	bsp.result.PHAS = 0;
	bsp.result.D = 0;
	bsp.result.Q = 0;
	bsp.result.LP = 0;
	bsp.result.RP = 0;

}

