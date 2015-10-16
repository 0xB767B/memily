/* beginning and end of the program rom area (128K)*/
/* _rom_begin = 0x00000000; */
/* _rom_end   = 0x0001FFFC; */

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

ENTRY(reset_handler)

SECTIONS
{
  /* program code (text), read-only data and static ctors */
  .text :
  {
    KEEP(*(.exception_vector))
    /* . = 0x080000ED; todo: temporary. should be correctly aligned by adding interrupt-vectors for mcu */
    _VECTORS_END = .;
    _ctors_begin = .;
    *(.init_array)
    . = ALIGN(4);
    KEEP (*(SORT(.init_array)))
    _ctors_end = .;
    *(.text)
    . = ALIGN(4);
    *(.text*)
    . = ALIGN(4);
    *(.rodata)
    . = ALIGN(4);
    *(.rodata*)
    . = ALIGN(4);
  } > ROM


  . = 0x20000000;
  . = ALIGN(4);

  /* rom-to-ram initialized data section */
  .data :
  {
    _data_begin = .;
    *(.data)
    . = ALIGN(4);
    KEEP (*(.data))
    *(.data*)
    . = ALIGN(4);
    KEEP (*(.data*))
    _data_end = .;
  } > RAM AT > ROM

  /* uninitialized (zero-cleared) data section */
  .bss :
  {
    _bss_begin = .;
    *(.bss)
    . = ALIGN(4);
    KEEP (*(.bss))
    *(.bss*)
    . = ALIGN(4);
    KEEP (*(.bss*))
    _bss_end = .;
  } > RAM

  _rom_data_begin = LOADADDR(.data);
}
