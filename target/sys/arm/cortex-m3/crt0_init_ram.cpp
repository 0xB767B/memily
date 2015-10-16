#include <algorithm>
#include <cstddef>
#include <cstdint>

extern "C"
{
  extern std::uintptr_t _romDataBegin; // start address for the initialization values of the rom-to-ram section
  extern std::uintptr_t _dataBegin; // start address for the .data section
  extern std::uintptr_t _dataEnd; // end address for the .data section
  extern std::uintptr_t _bssBegin; // start address for the .bss section
  extern std::uintptr_t _bssEnd; // end address for the .bss section
}

namespace crt
{
  void init_ram();
}

void crt::init_ram()
{
  typedef std::uint32_t MemoryAlignedType;

  // copy the data segment initializers from rom to ram
  // note: all data segments are aligned by 4
  const std::size_t size = std::size_t(static_cast<const MemoryAlignedType*>(static_cast<const void*>(&_dataEnd))
                                       - static_cast<const MemoryAlignedType*>(static_cast<const void*>(&_dataBegin)));

  std::copy(static_cast<const MemoryAlignedType*>(static_cast<const void*>(&_romDataBegin)),
            static_cast<const MemoryAlignedType*>(static_cast<const void*>(&_romDataBegin)) + size,
            static_cast<      MemoryAlignedType*>(static_cast<      void*>(&_dataBegin)));

  // clear  bss segment.
  // note: bss segment is aligned by 4.
  std::fill(static_cast<MemoryAlignedType*>(static_cast<void*>(&_bssBegin)),
            static_cast<MemoryAlignedType*>(static_cast<void*>(&_bssEnd)),
            static_cast<MemoryAlignedType>(0U));
}
