#include <stddef.h>
#include <stdint.h>

bool InvalidMemoryRead(const uint8_t *Data, size_t DataSize) {
  int n = 23;
  if (DataSize >= 1) {
    n <<= Data[0];
  }
  return false;
}

extern "C" int LLVMFuzzerTestOneInput(const uint8_t *Data, size_t Size) {
  InvalidMemoryRead(Data, Size);
  return 0;
}
