/*
 * interrupt.h
 *
 *  Created on: 10 Feb 2022
 *      Author: Taufik Hidayat
 */

#ifndef INTERRUPT_H_
#define INTERRUPT_H_

#include "usart.h"
#include "gpio.h"
#include "main.h"
#include "string.h"
#include "tim.h"

extern char data_kirim_usart1[5];
extern char data_terima_usart1[4];

extern char data_kirim_usart2[11];
extern short int angka_kirim;
extern char data_terima_usart2[4];

extern char data_terima_usart6[4];
extern char data_kirim_usart6[3];

void kirimDataPolling(void);
void terimaDataPolling(void);

#endif /* INTERRUPT_H_ */
