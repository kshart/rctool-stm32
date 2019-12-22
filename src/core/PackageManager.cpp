#include "PackageManager.h"
#include <stdio.h>

PackageManager::PackageManager(UART_HandleTypeDef* huart)
  :huart(huart),
  buffer() {
}

bool PackageManager::dispatchPackage() {
  if (pack.size <= 0) {
    return false;
  }
  HAL_UART_Transmit(&huart1, (uint8_t*)pack.data, pack.size, 0xFFFF);
  PackType type = static_cast<PackType>(pack.data[0]);
  switch (type) {
    case PackType::SET_XY:
      return true;
  }
  return false;
}

void PackageManager::listen() {
  while (1) {
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_SET);

    {
      char* hc05Hello = "hello\r\n";
      char* nothing = "nothing\r\n";
      HAL_UART_Transmit(huart, (uint8_t*)hc05Hello, strlen(hc05Hello), 0xFFFF);

      HAL_StatusTypeDef result = HAL_UART_Receive(huart, (uint8_t*)(buffer.data), sizeof(buffer.data), 100);
      if (result == HAL_OK || result == HAL_TIMEOUT) {
        buffer.size = strlen(buffer.data);
        if (buffer.size > 0) {
          read();
        } else {
          HAL_UART_Transmit(&huart1, (uint8_t*)nothing, strlen(nothing), 0xFFFF);
        }
      }
    }
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_RESET);
    buffer.reset();
    HAL_Delay(10);
  }
}

/**
 * Прочитать данные из буфера, и разложить по пакетам
 */
void PackageManager::read() {
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_RESET);
  size_t startPack = 0;
  for (size_t i = 0; i < buffer.size; ++i) {
    if (lastChar == '\r' && buffer.data[i] == '\n') {
      pack.append(buffer.data + startPack, i + 1 - startPack);
      dispatchPackage();
      pack.reset();
      startPack = i + 1;
    }
    lastChar = buffer.data[i];
  }

  if (startPack < buffer.size) {
    pack.append(buffer.data + startPack, buffer.size - startPack);
  }
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_SET);
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_SET);
}
