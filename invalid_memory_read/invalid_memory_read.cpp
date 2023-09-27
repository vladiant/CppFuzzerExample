#include <stddef.h>
#include <stdint.h>

bool InvalidMemoryRead(const uint8_t *Data, size_t DataSize) {
  return DataSize >= 3 && Data[0] == 'F' && Data[1] == 'U' && Data[2] == 'Z' &&
         Data[3] == 'Z';  // Bug
}

extern "C" int LLVMFuzzerTestOneInput(const uint8_t *Data, size_t Size) {
  InvalidMemoryRead(Data, Size);
  return 0;
}