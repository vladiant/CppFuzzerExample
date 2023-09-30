#include <cstddef>
#include <cstdint>
#include <limits>

bool InvalidMemoryRead(const uint8_t *Data, size_t DataSize) {
  auto n = std::numeric_limits<int>::max();
  if (DataSize >= 1) {
    n += Data[0];
  }
  return false;
}

extern "C" int LLVMFuzzerTestOneInput(const uint8_t *Data, size_t Size) {
  InvalidMemoryRead(Data, Size);
  return 0;
}
