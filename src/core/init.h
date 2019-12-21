/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   init.h
 * Author: kshar
 *
 * Created on 17 ноября 2019 г., 11:46
 */

#ifndef INIT_H
#define INIT_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../main.h"

TIM_HandleTypeDef htim3;

void SystemClock_Config();
void MX_GPIO_Init();
TIM_HandleTypeDef* MX_TIM3_Init();

#ifdef __cplusplus
}
#endif

#endif /* INIT_H */
