#include <stddef.h>
#include <stdint.h>

bool InvalidMemoryRead(const uint8_t *data, size_t size) {
  if (size > 0 && data[0] == 'H')
    if (size > 1 && data[1] == 'I')
       if (size > 2 && data[2] == '!')
       __builtin_trap();
  return false;
}

extern "C" int LLVMFuzzerTestOneInput(const uint8_t *Data, size_t Size) {
  InvalidMemoryRead(Data, Size);
  return 0;
}
