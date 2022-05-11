/*
 * calculate.c
 *
 *  Created on: Apr 12, 2022
 *      Author: grzegorz
 */

#include <math.h>
#include <result.h>

static void Result_Reset();
static void Result_CS();
static void Result_CP();
static void Result_Q();
static void Result_D();
static void Result_LS();
static void Result_LP();
static void Result_RP();
static void Result_MLIN();
static void Result_PHAS();
static void Result_REAL();
static void Result_IMAG();
static void Result_G();
static void Result_B();
static void Result_Y();

static void Result_CalculateParameters()
{
	if(FIMP == bsp.config.function)
	{
		switch(bsp.config.format1)
		{
			case NONE: /* Do nothing */ ; break;
			case MLIN: Result_MLIN(); break;
			case REAL: Result_REAL(); break;
			case CS: Result_CS(); break;
			case LS: Result_LS(); break;
		}
		switch(bsp.config.format2)
		{
			case NONE: /* Do nothing */ ; break;
			case PHAS: Result_PHAS(); break;
			case IMAG: Result_IMAG(); break;
			case D: Result_D(); break;
			case Q: Result_Q(); break;
			case REAL: Result_REAL(); break;
		}
	}
	else if(FADM == bsp.config.function)
	{
		switch(bsp.config.format1)
		{
			case NONE: /* Do nothing */ ; break;
			case MLIN: Result_Y(); break;
			case REAL: Result_G(); break;
			case CP: Result_CP(); break;
			case LP: Result_LP(); break;
		}
		switch(bsp.config.format2)
		{
			case NONE: /* Do nothing */ ; break;
			case PHAS: Result_PHAS(); break;
			case IMAG: Result_B(); break;
			case D: Result_D(); break;
			case Q: Result_Q(); break;
			case REAL: Result_G(); break;
			case RP: Result_RP(); break;
		}
	}
}

void Result()
{

	double tmp_denom1 = 0, tmp_denom2 = 0;

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

	if(bsp.compensate.comp_state)
	{
		if (bsp.compensate.comp_open && bsp.compensate.comp_short)
		{
			bsp.result.z_raw_real = (bsp.result.volt_real * bsp.result.curr_real + bsp.result.volt_imag * bsp.result.curr_imag) / (bsp.result.curr_real * bsp.result.curr_real + bsp.result.curr_imag * bsp.result.curr_imag);
			bsp.result.z_raw_imag = (bsp.result.volt_imag * bsp.result.curr_real - bsp.result.volt_real * bsp.result.curr_imag) / (bsp.result.curr_real * bsp.result.curr_real + bsp.result.curr_imag * bsp.result.curr_imag);
			bsp.result.y_raw_real = (bsp.result.volt_real * bsp.result.curr_real + bsp.result.volt_imag * bsp.result.curr_imag) / (bsp.result.volt_real * bsp.result.volt_real + bsp.result.volt_imag * bsp.result.volt_imag);
			bsp.result.y_raw_imag = (bsp.result.volt_real * bsp.result.curr_imag - bsp.result.volt_imag * bsp.result.curr_real) / (bsp.result.volt_real * bsp.result.volt_real + bsp.result.volt_imag * bsp.result.volt_imag);

			tmp_denom1 = (1 - bsp.result.z_raw_real * bsp.compensate.y_stray_real - bsp.compensate.z_resid_real * bsp.compensate.y_stray_real + bsp.result.z_raw_imag * bsp.compensate.y_stray_imag - bsp.compensate.z_resid_real * bsp.compensate.y_stray_imag) * (1 - bsp.result.z_raw_real * bsp.compensate.y_stray_real - bsp.compensate.z_resid_real * bsp.compensate.y_stray_real + bsp.result.z_raw_imag * bsp.compensate.y_stray_imag - bsp.compensate.z_resid_real * bsp.compensate.y_stray_imag) + (-bsp.result.z_raw_imag * bsp.compensate.y_stray_real + bsp.compensate.z_resid_imag * bsp.compensate.y_stray_real - bsp.result.z_raw_real * bsp.compensate.y_stray_imag + bsp.compensate.z_resid_real * bsp.compensate.y_stray_imag) * (-bsp.result.z_raw_imag * bsp.compensate.y_stray_real + bsp.compensate.z_resid_imag * bsp.compensate.y_stray_real - bsp.result.z_raw_real * bsp.compensate.y_stray_imag + bsp.compensate.z_resid_real * bsp.compensate.y_stray_imag);
			bsp.result.z_real = ((bsp.result.z_raw_real - bsp.compensate.z_resid_real) * (1 - bsp.result.z_raw_real * bsp.compensate.y_stray_real - bsp.compensate.z_resid_real * bsp.compensate.y_stray_real + bsp.result.z_raw_imag * bsp.compensate.y_stray_imag - bsp.compensate.z_resid_imag * bsp.compensate.y_stray_imag) + (bsp.result.z_raw_imag - bsp.compensate.z_resid_imag) * (-bsp.result.z_raw_imag * bsp.compensate.y_stray_real + bsp.compensate.z_resid_real * bsp.compensate.y_stray_real - bsp.result.z_raw_real * bsp.compensate.y_stray_imag + bsp.compensate.z_resid_real * bsp.compensate.y_stray_imag)) / tmp_denom1;
			bsp.result.z_imag = ((bsp.result.z_raw_imag - bsp.compensate.z_resid_imag) * (1 - bsp.result.z_raw_real * bsp.compensate.y_stray_real - bsp.compensate.z_resid_real * bsp.compensate.y_stray_real + bsp.result.z_raw_imag * bsp.compensate.y_stray_imag - bsp.compensate.z_resid_imag * bsp.compensate.y_stray_imag) - (bsp.result.z_raw_real - bsp.compensate.z_resid_real) * (-bsp.result.z_raw_imag * bsp.compensate.y_stray_real + bsp.compensate.z_resid_real * bsp.compensate.y_stray_real - bsp.result.z_raw_real * bsp.compensate.y_stray_imag + bsp.compensate.z_resid_real * bsp.compensate.y_stray_imag)) / tmp_denom1;

			tmp_denom2 = (bsp.result.z_raw_real - bsp.compensate.z_resid_real) * (bsp.result.z_raw_real - bsp.compensate.z_resid_real) + (bsp.result.z_raw_imag - bsp.compensate.z_resid_imag) * (bsp.result.z_raw_imag - bsp.compensate.z_resid_imag);
			bsp.result.y_real = ((1 - bsp.result.z_raw_real * bsp.compensate.y_stray_real - bsp.compensate.z_resid_real * bsp.compensate.y_stray_real + bsp.result.z_raw_imag * bsp.compensate.y_stray_imag - bsp.compensate.z_resid_imag * bsp.compensate.y_stray_imag) * (bsp.result.z_raw_real - bsp.compensate.z_resid_real) + (-bsp.result.z_raw_imag * bsp.compensate.y_stray_real + bsp.compensate.z_resid_imag * bsp.compensate.y_stray_real - bsp.result.z_raw_real * bsp.compensate.y_stray_imag + bsp.compensate.z_resid_real * bsp.compensate.y_stray_imag) * (bsp.result.z_raw_imag - bsp.compensate.z_resid_imag)) / tmp_denom2;
			bsp.result.y_imag = ((-bsp.result.z_raw_imag * bsp.compensate.y_stray_real + bsp.compensate.z_resid_imag * bsp.compensate.y_stray_real - bsp.result.z_raw_real * bsp.compensate.y_stray_imag + bsp.compensate.z_resid_real * bsp.compensate.y_stray_imag) * (bsp.result.z_raw_real - bsp.compensate.z_resid_real) - (1 - bsp.result.z_raw_real * bsp.compensate.y_stray_real - bsp.compensate.z_resid_real * bsp.compensate.y_stray_real + bsp.result.z_raw_imag * bsp.compensate.y_stray_imag - bsp.compensate.z_resid_imag * bsp.compensate.y_stray_imag) * (bsp.result.z_raw_imag - bsp.compensate.z_resid_imag)) / tmp_denom2;

		}
	}
	else
	{
		bsp.result.z_real = (bsp.result.volt_real * bsp.result.curr_real + bsp.result.volt_imag * bsp.result.curr_imag) / (bsp.result.curr_real * bsp.result.curr_real + bsp.result.curr_imag * bsp.result.curr_imag);
		bsp.result.z_imag = (bsp.result.volt_imag * bsp.result.curr_real - bsp.result.volt_real * bsp.result.curr_imag) / (bsp.result.curr_real * bsp.result.curr_real + bsp.result.curr_imag * bsp.result.curr_imag);
		bsp.result.y_real = (bsp.result.volt_real * bsp.result.curr_real + bsp.result.volt_imag * bsp.result.curr_imag) / (bsp.result.volt_real * bsp.result.volt_real + bsp.result.volt_imag * bsp.result.volt_imag);
		bsp.result.y_imag = (bsp.result.volt_real * bsp.result.curr_imag - bsp.result.volt_imag * bsp.result.curr_real) / (bsp.result.volt_real * bsp.result.volt_real + bsp.result.volt_imag * bsp.result.volt_imag);

	}

	Result_CalculateParameters();


}

void Result_Compensate()
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

	bsp.result.z_raw_real = (bsp.result.volt_real * bsp.result.curr_real + bsp.result.volt_imag * bsp.result.curr_imag) / (bsp.result.curr_real * bsp.result.curr_real + bsp.result.curr_imag * bsp.result.curr_imag);
	bsp.result.z_raw_imag = (bsp.result.volt_imag * bsp.result.curr_real - bsp.result.volt_real * bsp.result.curr_imag) / (bsp.result.curr_real * bsp.result.curr_real + bsp.result.curr_imag * bsp.result.curr_imag);
	bsp.result.y_raw_real = (bsp.result.volt_real * bsp.result.curr_real + bsp.result.volt_imag * bsp.result.curr_imag) / (bsp.result.volt_real * bsp.result.volt_real + bsp.result.volt_imag * bsp.result.volt_imag);
	bsp.result.y_raw_imag = (bsp.result.volt_real * bsp.result.curr_imag - bsp.result.volt_imag * bsp.result.curr_real) / (bsp.result.volt_real * bsp.result.volt_real + bsp.result.volt_imag * bsp.result.volt_imag);

	if(COMP_ON == bsp.compensate.comp_open)
	{
		bsp.compensate.y_stray_real = bsp.result.y_raw_real;
		bsp.compensate.y_stray_imag = bsp.result.y_raw_imag;
	}
	else if(COMP_ON == bsp.compensate.comp_short)
	{
		bsp.compensate.z_resid_real = bsp.result.z_raw_real;
		bsp.compensate.z_resid_imag = bsp.result.z_raw_imag;
	}
}

static void Result_CS()
{
	bsp.result.CS =  (double)(1/(2*PI*bsp.config.frequency*fabs(bsp.result.z_imag)));
}

static void Result_CP()
{
	bsp.result.Q = fabs((fabs(bsp.result.z_imag)/bsp.result.z_real));
	bsp.result.CP = (double)(1/(2*PI*bsp.config.frequency*(1+1/(bsp.result.Q*bsp.result.Q))*fabs(bsp.result.z_imag)));
}

static void Result_Q()
{
	bsp.result.Q = fabs(fabs(bsp.result.z_imag)/bsp.result.z_real);
}

static void Result_D()
{
	bsp.result.Q = fabs(fabs(bsp.result.z_imag)/bsp.result.z_real);
	bsp.result.D = (double)(1/bsp.result.Q);
}

static void Result_LS()
{
	bsp.result.LS = (double)(fabs(bsp.result.z_imag)/(2*PI));
}

static void Result_LP()
{
	bsp.result.Q = fabs(fabs(bsp.result.z_imag)/bsp.result.z_real);
	bsp.result.LP = ((1+1/(bsp.result.Q*bsp.result.Q))*fabs(bsp.result.z_imag))/(2*PI*bsp.config.frequency);
}

static void Result_RP()
{
	bsp.result.Q = fabs(fabs(bsp.result.z_imag)/bsp.result.z_real);
	bsp.result.RP = fabs((1+bsp.result.Q*bsp.result.Q)*bsp.result.z_real);
}

static void Result_MLIN()
{
	bsp.result.MLIN = sqrt(bsp.result.z_real*bsp.result.z_real + bsp.result.z_imag*bsp.result.z_imag);
}

static void Result_PHAS()
{
	bsp.result.PHAS = atan(bsp.result.z_imag/bsp.result.z_real);
}

static void Result_REAL()
{
	bsp.result.REAL = fabs(bsp.result.z_real);
}

static void Result_G()
{
	bsp.result.G = fabs(1/bsp.result.z_real);
}

static void Result_IMAG()
{
	bsp.result.IMAG = bsp.result.z_imag;
}

static void Result_B()
{
	bsp.result.B = (double)(1/bsp.result.z_imag);
}

static void Result_Y()
{
	bsp.result.Y = (double)(1/(sqrt(bsp.result.z_real*bsp.result.z_real + bsp.result.z_imag*bsp.result.z_imag)));
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

	bsp.result.z_raw_real = 0;
	bsp.result.z_raw_imag = 0;
	bsp.result.y_raw_real = 0;
	bsp.result.y_raw_imag = 0;

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
	bsp.result.Y = 0;
	bsp.result.G = 0;
	bsp.result.B = 0;

}

