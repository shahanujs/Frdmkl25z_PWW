/*
 * Copyright 2016-2020 NXP
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of NXP Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
 
/**
 * @file    PWM.cpp
 * @brief   Application entry point.
 */
#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MKL25Z4.h"
#include "fsl_debug_console.h"
//#include <iostream>

//using namespace std;

int main(void) {

  	SystemCoreClockUpdate ();
//EECS 3215 PWM on Kinetis
//  	std::cout << "Two PWM channels, center-aligned" << endl;
  	printf("Two PWM channels, center-aligned.");

  	SIM->SCGC5 |= SIM_SCGC5_PORTA_MASK;
  	PORTA->PCR[12] |= 0b001100000000;

  	SIM->SCGC6 |= SIM_SCGC6_TPM1_MASK;
  	SIM->SOPT2 |= 0X01000000;

  	TPM1->SC = 0;
  	TPM1->CONTROLS[0].CnSC = 0x20 | 0x08;

  	TPM1->MOD = 0xFFFF;
  	TPM1->CONTROLS[0].CnV = 0x4000;

  	TPM1->SC = 0b00101010;

  	PORTA->PCR[5] = 0b001100000000;

  	SIM->SCGC6 |= SIM_SCGC6_TPM0_MASK;
  	SIM->SOPT2 |= 0x01000000;
  	TPM0->SC =0;
  	TPM0->CONTROLS[2].CnSC = 0x20 | 0x08;
  	TPM0->MOD = 0xFFFF;
  	TPM0->CONTROLS[2].CnV = 0x0050;
  	TPM0->SC = 0b00101001;

  	volatile static int i = 0;
  	while(1){
  		i++;
  	}


    return 0 ;
}
