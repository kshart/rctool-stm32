#include "usart.h"
#include "gpio.h"
#include <string.h>
#include <stdbool.h>

char buffer[64] = {0};

void clearBuffer(char *buffer, size_t size) {
  for (size_t i = 0; i < size; ++i) {
    buffer[i] = 0;
  }
}

/**
 * Запуск Bluetooth модуля.
 * @retval boolean
 */
bool hc05Init(UART_HandleTypeDef *huart) {
  bool stateOk = false;
  char *helloMessage = "AT\r\n";
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_RESET);
  while (!stateOk) {
    HAL_UART_Transmit(huart, helloMessage, strlen(helloMessage), 0xFFFF);

    HAL_StatusTypeDef result = HAL_UART_Receive(huart, (uint8_t*)buffer, 64, 500);
    if (result == HAL_OK || result == HAL_TIMEOUT) {
      size_t stringLength = strlen(buffer);
      if (stringLength > 0) {
        stateOk = true;
      } else {
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_RESET);
        HAL_Delay(100);
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_SET);
      }
    }
    clearBuffer(buffer, sizeof(buffer));
  }
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_RESET);

  {
    char *roleMessage = "AT+ROLE=0\r\n";
    HAL_UART_Transmit(huart, roleMessage, strlen(roleMessage), 0xFFFF);
    HAL_StatusTypeDef result = HAL_UART_Receive(huart, (uint8_t*)buffer, 64, 500);
    if (result == HAL_OK || result == HAL_TIMEOUT) {
      size_t stringLength = strlen(buffer);
      if (stringLength <= 0 || buffer[0] != 'O' || buffer[1] != 'K') {
        return false;
      }
    }
    clearBuffer(buffer, sizeof(buffer));
  }
  {
    char *initMessage = "AT+UART=921600,0,0\r\n";
    HAL_UART_Transmit(huart, initMessage, strlen(initMessage), 0xFFFF);
    HAL_StatusTypeDef result = HAL_UART_Receive(huart, (uint8_t*)buffer, 64, 500);
    if (result == HAL_OK || result == HAL_TIMEOUT) {
      size_t stringLength = strlen(buffer);
      if (stringLength <= 0 || buffer[0] != 'O' || buffer[1] != 'K') {
        return false;
      }
    }
    clearBuffer(buffer, sizeof(buffer));
  }

  char *resetMessage = "AT+RESET\r\n";
  HAL_UART_Transmit(huart, resetMessage, strlen(resetMessage), 0xFFFF);
  return true;
}

/**
 * Отправить пакет через bluetooth.
 * @retval boolean
 */
bool hc05WritePack(char* message, size_t length) {
  UART_HandleTypeDef *huart;
  HAL_UART_Receive(huart, (uint8_t*)buffer, 64, 500);
  bool stateOk = false;
  char *helloMessage = "AT\r\n";
  while (!stateOk) {
    HAL_UART_Transmit(huart, (uint8_t*)helloMessage, strlen(helloMessage), 0xFFFF);

    HAL_StatusTypeDef result = HAL_UART_Receive(huart, (uint8_t*)buffer, 64, 500);
    if (result == HAL_OK || result == HAL_TIMEOUT) {
      size_t stringLength = strlen(buffer);
      if (stringLength > 0) {
        stateOk = true;
      }
    }
    clearBuffer(buffer, sizeof(buffer));
  }

  {
    char *roleMessage = "AT+ROLE=0\r\n";
    HAL_UART_Transmit(huart, (uint8_t*)roleMessage, strlen(roleMessage), 0xFFFF);
    HAL_StatusTypeDef result = HAL_UART_Receive(huart, (uint8_t*)buffer, 64, 500);
    if (result == HAL_OK || result == HAL_TIMEOUT) {
      size_t stringLength = strlen(buffer);
      if (stringLength <= 0 || buffer[0] != 'O' || buffer[1] != 'K') {
        return false;
      }
    }
    clearBuffer(buffer, sizeof(buffer));
  }
  {
    char *initMessage = "AT+UART=921600,0,0\r\n";
    HAL_UART_Transmit(huart, (uint8_t*)initMessage, strlen(initMessage), 0xFFFF);
    HAL_StatusTypeDef result = HAL_UART_Receive(huart, (uint8_t*)buffer, 64, 500);
    if (result == HAL_OK || result == HAL_TIMEOUT) {
      size_t stringLength = strlen(buffer);
      if (stringLength <= 0 || buffer[0] != 'O' || buffer[1] != 'K') {
        return false;
      }
    }
    clearBuffer(buffer, sizeof(buffer));
  }

  char *resetMessage = "AT+RESET\r\n";
  HAL_UART_Transmit(huart, (uint8_t*)resetMessage, strlen(resetMessage), 0xFFFF);
  return true;
}
