/**
 ******************************************************************************
 * File Name          : TIM.h
 * Description        : This file provides code for the configuration
 *                      of the TIM instances.
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#ifndef __tim_H
#define __tim_H
#ifdef __cplusplus
extern "C" {
#endif

#include "../main.h"

extern TIM_HandleTypeDef htim2;

void MX_TIM2_Init(void);

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

#ifdef __cplusplus
}
#endif
#endif /*__ tim_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
