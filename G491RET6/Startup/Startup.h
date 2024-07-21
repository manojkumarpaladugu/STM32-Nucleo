#include <stdint.h>

#define SRAM_START (0x20000000U)
#define SRAM_SIZE (112 * 1024U)
#define SRAM_END (SRAM_START + SRAM_SIZE)
#define STACK_ADDRESS (SRAM_END)

#define ISR_VECTOR_SIZE_WORDS 118

extern uint32_t _etext, _sdata, _edata, _sbss, _ebss;
extern void main(void);

void ResetHandler(void);
void default_handler(void);

// Cortex-M system exceptions
void NMI_Handler(void) __attribute__((weak, alias("default_handler")));
void HardFault_Handler(void) __attribute__((weak, alias("default_handler")));
void MemManage_Handler(void) __attribute__((weak, alias("default_handler")));
void BusFault_Handler(void) __attribute__((weak, alias("default_handler")));
void UsageFault_Handler(void) __attribute__((weak, alias("default_handler")));
void SVC_Handler(void) __attribute__((weak, alias("default_handler")));
void DebugMon_Handler(void) __attribute__((weak, alias("default_handler")));
void PendSV_Handler(void) __attribute__((weak, alias("default_handler")));
void SysTick_Handler(void) __attribute__((weak, alias("default_handler")));

// STM32G491RET6 interrupt handlers
void WWDG_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void PVD_PVM_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void RTC_TAMP_LSECSS_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void RTC_WKUP_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void FLASH_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void RCC_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void EXTI0_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void EXTI1_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void EXTI2_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void EXTI3_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void EXTI4_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void DMA1_Channel1_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void DMA1_Channel2_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void DMA1_Channel3_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void DMA1_Channel4_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void DMA1_Channel5_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void DMA1_Channel6_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void DMA1_Channel7_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void ADC1_2_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void USB_HP_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void USB_LP_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void FDCAN1_IT0_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void FDCAN1_IT1_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void EXTI9_5_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void TIM1_BRK_TIM15_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void TIM1_UP_TIM16_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void TIM1_TRG_COM_TIM17_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void TIM1_CC_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void TIM2_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void TIM3_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void TIM4_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void I2C1_EV_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void I2C1_ER_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void I2C2_EV_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void I2C2_ER_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void SPI1_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void SPI2_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void USART1_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void USART2_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void USART3_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void EXTI15_10_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void RTC_Alarm_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void USBWakeUp_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void TIM8_BRK_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void TIM8_UP_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void TIM8_TRG_COM_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void TIM8_CC_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void ADC3_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void LPTIM1_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void SPI3_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void UART4_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void UART5_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void TIM6_DAC_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void TIM7_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void DMA2_Channel1_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void DMA2_Channel2_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void DMA2_Channel3_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void DMA2_Channel4_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void DMA2_Channel5_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void UCPD1_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void COMP1_2_3_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void COMP4_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void CRS_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void SAI1_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void TIM20_BRK_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void TIM20_UP_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void TIM20_TRG_COM_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void TIM20_CC_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void FPU_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void FDCAN2_IT0_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void FDCAN2_IT1_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void RNG_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void LPUART1_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void I2C3_EV_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void I2C3_ER_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void DMAMUX_OVR_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void QUADSPI_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void DMA1_Channel8_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void DMA2_Channel6_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void DMA2_Channel7_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void DMA2_Channel8_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void CORDIC_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void FMAC_IRQHandler(void) __attribute__((weak, alias("default_handler")));
