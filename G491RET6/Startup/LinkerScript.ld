ENTRY(ResetHandler)

/* Highest address of the user mode stack */
_estack = ORIGIN(SRAM) + LENGTH(SRAM); /* end of "RAM" Ram type memory */

MEMORY
{
    FLASH (rx)  : ORIGIN = 0x08000000, LENGTH = 512K
    SRAM  (rwx) : ORIGIN = 0x20000000, LENGTH = 112K
}

SECTIONS
{
    /* Vector table at the beginning of flash */
    .isr_vector :
    {
        . = ALIGN(4);
        KEEP(*(.isr_vector))
        . = ALIGN(4);
    } >FLASH

    /* Program code and read only data into flash memory */
    .text :
    {
        . = ALIGN(4);
        *(.text)
        *(.rodata)
        . = ALIGN(4);
        _etext = .;     /* define a global symbols at end of code */
    } >FLASH

    /* Initialized data sections into SRAM */
    .data :
    {
        _sdata = .;     /* create a global symbol at data start */
        . = ALIGN(4);
        *(.data)
        . = ALIGN(4);
        _edata = .;     /* define a global symbol at data end */
    } >SRAM AT> FLASH

    /* Uninitialized data sections into SRAM */
    .bss :
    {
        _sbss = .;      /* define a global symbol at bss start */
        . = ALIGN(4);
        *(.bss)
        . = ALIGN(4);
        _ebss = .;      /* define a global symbol at bss end */
    } >SRAM
}
