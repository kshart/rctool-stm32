#include "usart.h"
#include "gpio.h"
#include <string.h>
#include <stdbool.h>


char package[1024] = {0};
size_t packageSize = 0;

void resetPackage() {
  memset(package, 0, packageSize);
  packageSize = 0;
}

void appendPackage(char* bytes, size_t count) {
  memcpy(&package[packageSize], bytes, count);
  packageSize += count;
}
