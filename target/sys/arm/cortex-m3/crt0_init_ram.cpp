#include <algorithm>
#include <cstddef>

extern "C"
{
  extern std::uintptr_t _rom_data_begin; // start address for the initialization values of the rom-to-ram section
  extern std::uintptr_t _data_begin; // start address for the .data section
  extern std::uintptr_t _data_end; // end address for the .data section
  extern std::uintptr_t _bss_begin; // start address for the .bss section
  extern std::uintptr_t _bss_end; // end address for the .bss section
}

namespace crt
{
  void init_ram();
}

void crt::init_ram()
{
  typedef std::uint32_t memory_aligned_type;

  // copy the data segment initializers from rom to ram
  // note: all data segments are aligned by 4
  const std::size_t size = std::size_t(
          static_cast<const memory_aligned_type *>(static_cast<const void*>(&_data_end))
                                       - static_cast<const memory_aligned_type *>(static_cast<const void*>(&_data_begin)));

  std::copy(static_cast<const memory_aligned_type *>(static_cast<const void*>(&_rom_data_begin)),
            static_cast<const memory_aligned_type *>(static_cast<const void*>(&_rom_data_begin)) + size,
            static_cast<      memory_aligned_type *>(static_cast<      void*>(&_data_begin)));

  // clear  bss segment.
  // note: bss segment is aligned by 4.
  std::fill(static_cast<memory_aligned_type *>(static_cast<void*>(&_bss_begin)),
            static_cast<memory_aligned_type *>(static_cast<void*>(&_bss_end)),
            static_cast<memory_aligned_type>(0U));
}
