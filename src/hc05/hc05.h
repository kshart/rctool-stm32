/*
 * File:   hc05.h
 * Author: kshar
 *
 * Created on 20 ноября 2019 г., 20:47
 */

#ifndef HC05_H
#define HC05_H

#include "usart.h"
#include "PinGPIO.h"

bool hc05Init(UART_HandleTypeDef *huart, PinGPIO& ledPin);

#endif /* HC05_H */
