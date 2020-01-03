#ifndef PackageManager_H
#define PackageManager_H

#include <string.h>
#include "../main.h"
#include "PackageBuffer.h"

class PackageManager {
protected:
  enum PackType : char {
    SET_XY = 1
  };
  UART_HandleTypeDef* huart = nullptr;
  PackageBuffer buffer;
  PackageBuffer pack;
  char lastChar = 0;
  size_t totalPacks = 0;
public:
  PackageManager(UART_HandleTypeDef* huart);

  /**
   * Начать принимать данные из UART.
   */
  void listen();

  /**
   * Прочитать данные из буфера, и разложить по пакетам
   */
  void read();

  /**
   * Обработать принятый пакет данных.
   */
  bool dispatchPackage();
};

#endif /* PackageManager_H */
