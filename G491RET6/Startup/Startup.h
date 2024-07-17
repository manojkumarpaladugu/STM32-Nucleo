#include <stdint.h>

#define SRAM_START (0x20000000U)
#define SRAM_SIZE (112 * 1024U)
#define SRAM_END (SRAM_START + SRAM_SIZE)
#define STACK_ADDRESS (SRAM_END)

#define ISR_VECTOR_SIZE_WORDS 118

extern uint32_t _etext, _sdata, _edata, _sbss, _ebss;

void ResetHandler(void);
void default_handler(void);
void nmi_handler(void) __attribute__((weak, alias("default_handler")));
void hard_fault_handler(void) __attribute__((weak, alias("default_handler")));
void mem_manage_handler(void) __attribute__((weak, alias("default_handler")));
void bus_fault_handler(void) __attribute__((weak, alias("default_handler")));
void usage_fault_handler(void) __attribute__((weak, alias("default_handler")));
void svcall_handler(void) __attribute__((weak, alias("default_handler")));
void debug_monitor_handler(void) __attribute__((weak, alias("default_handler")));
void pendsv_handler(void) __attribute__((weak, alias("default_handler")));
void systick_handler(void) __attribute__((weak, alias("default_handler")));
extern void main(void);
