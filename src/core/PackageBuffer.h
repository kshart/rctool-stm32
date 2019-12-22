#ifndef PackageBuffer_H
#define PackageBuffer_H

#include <string.h>
#include "../main.h"

class PackageBuffer {
public:
  char data[512] = {0};
  size_t size = 0;

  PackageBuffer();

  /**
   * Очистить буфер
   */
  void reset();

  /**
   * Добавить данные в буфер
   */
  bool append(char* data, size_t count);
};

#endif /* PackageBuffer_H */
