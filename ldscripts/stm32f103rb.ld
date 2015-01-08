/* beginning and end of the program rom area (128K)*/
_rom_begin = 0x00000000;
_rom_end   = 0x0001FFFC;

/* beginning and end (i.e., top) of the stack */
/* Set up a stack with a size of 1K */
_stack_begin = 0x20001C00;
_stack_end   = 0x20002000;

__initialStackPointer = 0x20002000;

MEMORY
{
  ROM(rx)  : ORIGIN = 0x08000000, LENGTH = 128K - 4
  RAM(rwx) : ORIGIN = 0x20000000, LENGTH = 0x1C00
}

SECTIONS
{
  . = 0x00000000;
  . = ALIGN(4);

  /* exception vectors */
  .exception_vector :
  {
    *(.exception_vector)
    . = ALIGN(0x10);
    KEEP(*(.exception_vector))
  } > ROM = 0xAAAA

  /* program code (text), read-only data and static ctors */
  .text :
  {
    _ctorsBegin = .;
    *(.init_array)
    . = ALIGN(4);
    KEEP (*(SORT(.init_array)))
    _ctorsEnd = .;
    *(.text)
    . = ALIGN(4);
    *(.text*)
    . = ALIGN(4);
    *(.rodata)
    . = ALIGN(4);
    *(.rodata*)
    . = ALIGN(4);
  } > ROM

  .text :
  {
    . = ALIGN(0x10);
  } > ROM = 0xAAAA

  . = 0x20000000;
  . = ALIGN(4);

  /* rom-to-ram initialized data section */
  .data :
  {
    _dataBegin = .;
    *(.data)
    . = ALIGN(4);
    KEEP (*(.data))
    *(.data*)
    . = ALIGN(4);
    KEEP (*(.data*))
    _dataEnd = .;
  } > RAM AT > ROM

  /* uninitialized (zero-cleared) data section */
  .bss :
  {
    _bssBegin = .;
    *(.bss)
    . = ALIGN(4);
    KEEP (*(.bss))
    *(.bss*)
    . = ALIGN(4);
    KEEP (*(.bss*))
    _bssEnd = .;
  } > RAM

  _romDataBegin = LOADADDR(.data);
}
