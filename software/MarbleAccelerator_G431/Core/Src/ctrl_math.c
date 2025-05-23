/*
  Copyright (c) 2025 Fabian Mink <fabian.mink@gmx.de>
  All rights reserved.

  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions are met:

  1. Redistributions of source code must retain the above copyright notice, this
     list of conditions and the following disclaimer.
  2. Redistributions in binary form must reproduce the above copyright notice,
     this list of conditions and the following disclaimer in the documentation
     and/or other materials provided with the distribution.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
  ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
  ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
  ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "ctrl_math.h"



int16_t control_pictrl_i16(control_pictrl_i16_t* controller, int16_t ref, int16_t act){

	int32_t ctrldiff;
	int32_t p_val, i_val;
	int32_t tmp_out;
	//int16_t out;

	ctrldiff = ((int32_t)ref - (int32_t)act);
	p_val = (((int32_t)controller->kp) * ctrldiff) >> 2;
	if(controller->ki){
		i_val = ((((int32_t)controller->ki) * ctrldiff)>>4) + controller->i_val;
	}
	else {
		i_val = 0.0f;
	}

	tmp_out = (p_val + i_val);
	tmp_out = tmp_out>>8;

	if(tmp_out > controller->max){
		tmp_out = controller->max;
		if(i_val > controller->i_val) {
			i_val = controller->i_val;
			//i_val = controller->max - p_val;
		}
	}
	if(tmp_out < controller->min){
		tmp_out = controller->min;
		if(i_val < controller->i_val) {
			i_val = controller->i_val;
			//i_val = controller->min - p_val;
		}
	}
	controller->i_val = i_val;
	return((int16_t)tmp_out);
}


//Linear scale / offset:  out = gain*(in + offs)
int16_t interp_linearTrsfm_i16(interp_lin_i16_t* coeffs, int16_t in){
	int32_t accu;

	accu = in + coeffs->offs;
	accu *= coeffs->gain;

	return( (int16_t) (accu>>8));
}

//Piecewise linear interpolator
int pgenerator_lin_int16(pgenerator_lin_int16_data_t* data, int16_t* val){
	*val = 0;
	if(data->numpos == 0) return(1);

	uint32_t deltapos;

	while( ((deltapos = data->deltapos[data->cnt]) == 0) && (data->cnt < (data->numpos-1) ) ) {
		data->cnt++;
	}

	if(data->cnt < (data->numpos-1) ){

		int16_t a = data->val[data->cnt];
		int16_t b = data->val[data->cnt + 1];
		int64_t tmp;
		//Linear interpolate btw. a and b using pos/(deltapos+1)
		//val = a + (b-a)* data->pos / (deltapos+1);

		tmp = ((int32_t)(b-a)) * (int32_t)(data->pos);
		*val = a + (int16_t)(tmp/ (int32_t)(deltapos));

		if(data->pos >= deltapos-1){
			data->pos = 0;
			data->cnt++;
		}
		else {
			data->pos++;
		}
	}
	else {
		*val = data->val[data->numpos-1];
		if(data->pos >= deltapos){
			return(1);
		}
		else {
			data->pos++;
		}
	}
	return(0);
}

void pgenerator_lin_int16_reset(pgenerator_lin_int16_data_t* data){
	data->cnt = 0;
	data->pos = 0;
}
