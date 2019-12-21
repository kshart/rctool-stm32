/*
 * File:   hc05.h
 * Author: kshar
 *
 * Created on 20 ноября 2019 г., 20:47
 */

#ifndef HC05_H
#define HC05_H

#include "usart.h"

#ifdef __cplusplus
extern "C" {
#endif

bool hc05Init(UART_HandleTypeDef *huart);

#ifdef __cplusplus
}
#endif

#endif /* HC05_H */
