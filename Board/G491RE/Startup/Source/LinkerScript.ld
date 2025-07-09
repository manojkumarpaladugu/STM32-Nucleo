/* Entry Point */
ENTRY(ResetHandler)

/* Highest address of the user mode stack */
_estack = ORIGIN(RAM) + LENGTH(RAM); /* stack beginning at the end of "RAM" */

_Min_Heap_Size = 0x200; /* required amount of heap */
_Min_Stack_Size = 0x400; /* required amount of stack */

/* Memories definition */
MEMORY
{
  FLASH (rx)  : ORIGIN = 0x08000000, LENGTH = 512K
  RAM   (rwx) : ORIGIN = 0x20000000, LENGTH = 112K
}

/* Sections */
SECTIONS
{
  /* The startup code into "FLASH" */
  .isr_vector :
  {
    . = ALIGN(4);
    KEEP(*(.isr_vector)) /* Startup code */
    . = ALIGN(4);
  } >FLASH

  /* The program code and other data into "FLASH" */
  .text :
  {
    . = ALIGN(4);
    *(.text)           /* .text sections (code) */
    *(.text*)          /* .text* sections (code) */
    *(.glue_7)         /* glue arm to thumb code */
    *(.glue_7t)        /* glue thumb to arm code */
    *(.eh_frame)

    KEEP (*(.init))
    KEEP (*(.fini))

    . = ALIGN(4);
    _etext = .;        /* define a global symbols at end of code */
  } >FLASH

  /* Constant data into "FLASH" */
  .rodata :
  {
    . = ALIGN(4);
    *(.rodata)         /* .rodata sections (constants, strings, etc.) */
    *(.rodata*)        /* .rodata* sections (constants, strings, etc.) */
    . = ALIGN(4);
  } >FLASH

  /* .ARM.extab and .ARM.exidx are related to unwinding C++ exception */
  .ARM.extab (READONLY) :
  {
    . = ALIGN(4);
    *(.ARM.extab* .gnu.linkonce.armextab.*)
    . = ALIGN(4);
  } >FLASH

  .ARM (READONLY) :
  {
    . = ALIGN(4);
    __exidx_start = .;
    *(.ARM.exidx*)
    __exidx_end = .;
    . = ALIGN(4);
  } >FLASH

  /* .preinit_array and .init_array is to do with initialization of C/C++ objects */
  .preinit_array (READONLY) :
  {
    . = ALIGN(4);
    PROVIDE_HIDDEN (__preinit_array_start = .);
    KEEP (*(.preinit_array*))
    PROVIDE_HIDDEN (__preinit_array_end = .);
    . = ALIGN(4);
  } >FLASH

  .init_array (READONLY) :
  {
    . = ALIGN(4);
    PROVIDE_HIDDEN (__init_array_start = .);
    KEEP (*(SORT(.init_array.*)))
    KEEP (*(.init_array*))
    PROVIDE_HIDDEN (__init_array_end = .);
    . = ALIGN(4);
  } >FLASH

  /* .fini_array is to do with tear down of C/C++ objects */
  .fini_array (READONLY) :
  {
    . = ALIGN(4);
    PROVIDE_HIDDEN (__fini_array_start = .);
    KEEP (*(SORT(.fini_array.*)))
    KEEP (*(.fini_array*))
    PROVIDE_HIDDEN (__fini_array_end = .);
    . = ALIGN(4);
  } >FLASH

  /* Used by the startup to initialize data */
  _sidata = LOADADDR(.data);

  /* Initialized data sections into "RAM" */
  .data :
  {
    . = ALIGN(4);
    _sdata = .;        /* create a global symbol at data start */
    *(.data)           /* .data sections */
    *(.data*)          /* .data* sections */
    *(.RamFunc)        /* .RamFunc sections */
    *(.RamFunc*)       /* .RamFunc* sections */

    . = ALIGN(4);
    _edata = .;        /* define a global symbol at data end */

  } >RAM AT> FLASH

  /* Uninitialized data section into "RAM" */
  . = ALIGN(4);
  .bss :
  {
    /* This is used by the startup in order to initialize the .bss section */
    _sbss = .;         /* define a global symbol at bss start */
    __bss_start__ = _sbss;
    *(.bss)
    *(.bss*)
    *(COMMON)

    . = ALIGN(4);
    _ebss = .;         /* define a global symbol at bss end */
    __bss_end__ = _ebss;
  } >RAM

  /* User_heap_stack section, used to check that there is enough "RAM" left */
  ._user_heap_stack :
  {
    . = ALIGN(8);
    PROVIDE ( end = . );
    PROVIDE ( _end = . );
    . = . + _Min_Heap_Size;
    . = . + _Min_Stack_Size;
    . = ALIGN(8);
  } >RAM

  /* Remove information from the compiler libraries */
  /DISCARD/ :
  {
    libc.a ( * )
    libm.a ( * )
    libgcc.a ( * )
  }

  .ARM.attributes 0 : { *(.ARM.attributes) }

  /*
   * This section stores metadata that may be used during tokenized string
   * decoding. This metadata describes properties that may affect how the
   * tokenized string is encoded or decoded -- the maximum length of the hash
   * function and the sizes of certain integer types.
   *
   * Metadata is declared as key-value pairs. See the metadata variable in
   * tokenize.cc for further details.
   */
  .pw_tokenizer.info 0x0 (INFO) :
  {
    KEEP(*(.pw_tokenizer.info))
  }

  /*
   * Tokenized string entries are stored in this section. Each entry contains
   * the original string literal and the calculated token that represents it. In
   * the compiled code, the token and a compact argument list encoded in a
   * uint32_t are used in place of the format string. The compiled code
   * contains no references to the tokenized string entries in this section.
   *
   * The tokenized string entry format is specified by the
   * pw::tokenizer::internal::Entry class in
   * pw_tokenizer/public/pw_tokenizer/internal/tokenize_string.h.
   *
   * The section contents are declared with KEEP so that they are not removed
   * from the ELF. These are never emitted in the final binary or loaded into
   * memory.
   */
  .pw_tokenizer.entries 0x0 (INFO) :
  {
    KEEP(*(.pw_tokenizer.entries.*))
    /* GCC has a known bug (https://gcc.gnu.org/bugzilla/show_bug.cgi?id=88061)
     * that causes it to ignore any user-specified section placement for
     * variables declared inside function templates. The symbols for these
     * variables instead end up in a .rodata.* subsection. The subsection names
     * for these symbols all contain the string "_pw_tokenizer_string_entry_"
     * (as long as -fdata-sections was used when compiling). Thus we can pick
     * the relevant sections by using an appropriate wildcard.
     *
     * Note that this technique only works because nothing in the source code
     * references the *_pw_tokenizer_string_entry_* symbols. This ensures the
     * linker will never place such symbols in the final .data (aka .rodata)
     * output section, meaning such symbols remain available for us to place
     * into the  .pw_tokenizer_entries section.
     */
    KEEP(*(.rodata.*_pw_tokenizer_string_entry_*))
  }
}
