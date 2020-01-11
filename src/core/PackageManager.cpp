#include <stdio.h>
#include "PackageManager.h"
#include "tim.h"

float getFloatFromBuffer(char* buffer) {
  char flipBuffer[4];
  flipBuffer[0] = buffer[3];
  flipBuffer[1] = buffer[2];
  flipBuffer[2] = buffer[1];
  flipBuffer[3] = buffer[0];
  return ((float*)flipBuffer)[0];
}

PackageManager::PackageManager(UART_HandleTypeDef* huart)
  :huart(huart),
  buffer() {
}

bool PackageManager::dispatchPackage() {
  if (pack.size <= 0) {
    return false;
  }
  totalPacks++;
  PackType type = static_cast<PackType>(pack.data[0]);
  switch (type) {
    case PackType::SET_XY:
      float x = getFloatFromBuffer(pack.data + 1);
      float y = getFloatFromBuffer(pack.data + 5);
      if (x < 0 || x > 1 || y < 0 || y > 1) {
        // char failMessage[64];
        // sprintf(failMessage, "fail %f %f\r\n", x, y);
        // HAL_UART_Transmit(&huart2, (uint8_t*)failMessage, strlen(failMessage), 0xFFFF);
        return false;
      }
      htim3.Instance->CCR1 = 800 + static_cast<int>(1350.0 * y);
      htim1.Instance->CCR1 = 800 + static_cast<int>(1350.0 * x);
      return true;
  }
  return false;
}

void PackageManager::listen() {
  while (1) {
    // HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_RESET);
    // HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_SET);

    {
      // char* hc05Hello = "hello\r\n";
      char* nothing = "nothing\r\n";
      // HAL_UART_Transmit(huart, (uint8_t*)hc05Hello, strlen(hc05Hello), 0xFFFF);

      HAL_StatusTypeDef result = HAL_UART_Receive(huart, (uint8_t*)(buffer.data), sizeof(buffer.data), 10);
      if (result == HAL_OK || result == HAL_TIMEOUT) {
        buffer.size = strlen(buffer.data);
        if (buffer.size > 0) {
          read();
        } else {
          // HAL_UART_Transmit(&huart2, (uint8_t*)nothing, strlen(nothing), 0xFFFF);
        }
      }
    }
    // HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_SET);
    // HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_RESET);
    buffer.reset();
    // HAL_Delay(10);
  }
}

/**
 * Прочитать данные из буфера, и разложить по пакетам
 */
void PackageManager::read() {
  // HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_RESET);
  // HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_RESET);
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
  // HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_SET);
  // HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_SET);
}
