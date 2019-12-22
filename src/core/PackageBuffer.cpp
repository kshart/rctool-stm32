#include "PackageBuffer.h"

PackageBuffer::PackageBuffer() {
}

void PackageBuffer::reset() {
  memset(data, 0, size);
  size = 0;
}

bool PackageBuffer::append(char* bytes, size_t count) {
  if (size + count > sizeof(data)) {
    return false;
  }
  memcpy(&data[size], bytes, count);
  size += count;
  return true;
}
