/*
 * interrupt.c
 *
 *  Created on: 10 Feb 2022
 *      Author: Taufik Hidayat
 */

// rule
// usart1 = polling
// usart2 = dma
// usart6 = interrupt

#include "interrupt.h"

short int angka_kirim1 = 5;
short int angka_kirim2 = 6;
int angka_kirim3 = 11111;
int counter = 0;
int counter_usart = 0;
static int counter_rcv_1 = 0;
static int rx_uart1 = 0;
static int rx_uart2 = 0;

float data_terima = 0;

void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart)
{
//	if(huart->Instance == USART2)
//	{
		// using dma
//		memcpy(data_kirim_usart2 + 3, &angka_kirim1, 2);
//		memcpy(data_kirim_usart2 + 5, &angka_kirim2, 2);
//		memcpy(data_kirim_usart2 + 7, &angka_kirim3, 4);
//		HAL_UART_Transmit_DMA(&huart2, (uint8_t*) data_kirim_usart2, strlen(data_kirim_usart2));

		// using interrupt
		HAL_UART_Transmit_IT(&huart6, data_kirim_usart6, strlen(data_kirim_usart6));

		if (rx_uart1 > 100)
		{
			HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
			rx_uart1 = 0;
		}
		rx_uart1++;
		counter_usart++;

//	}
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
//	if(huart->Instance == USART2)
//	{
		if (rx_uart2 > 100)
		{
			HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_13);
			rx_uart2 = 0;
		}
		rx_uart2++;


		// using interrupt
		memcpy(&data_terima, data_terima_usart6, 4);
		HAL_UART_Receive_IT(&huart6, data_terima_usart6, strlen(data_terima_usart6));

		// using dma
//		memcpy(&data_terima, data_terima_usart2, 4);
//		HAL_UART_Receive_DMA(&huart2, (uint8_t*)data_terima_usart2, strlen(data_terima_usart2));

//	}
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if(htim->Instance == TIM2)
	{
//		HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
		counter++;
	}
}

void kirimDataPolling()
{
	memcpy(data_kirim_usart1 + 3, &angka_kirim, 2);
	HAL_UART_Transmit(&huart1, (uint8_t*) data_kirim_usart1, strlen(data_kirim_usart1), 10);
	counter_usart++;
}

void terimaDataPolling()
{
	memcpy(&data_terima, data_terima_usart1, 4);
	HAL_UART_Receive(&huart1, (uint8_t*) data_terima_usart1, strlen(data_terima_usart1), 10);
	counter_rcv_1++;
}
