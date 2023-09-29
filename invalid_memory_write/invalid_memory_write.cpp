#include <stddef.h>
#include <stdint.h>

bool InvalidMemoryRead(const uint8_t *Data, size_t DataSize) {
  uint8_t local[3];
  if (DataSize >= 4) {
     local[0] = Data[0];
     local[1] = Data[1];
     local[2] = Data[2];
     local[3] = Data[3]; // Bug
  }
  return local[0] == local[1] && local[1] == local[2];
}

extern "C" int LLVMFuzzerTestOneInput(const uint8_t *Data, size_t Size) {
  InvalidMemoryRead(Data, Size);
  return 0;
}
