#include "Core.h"

#define STACK_ADDRESS (SRAM2_BASE + SRAM2_SIZE)

#define ISR_VECTOR_SIZE_WORDS 118

extern uint32_t _sidata, _sdata, _edata, _sbss, _ebss;
extern void main(void);

void ResetHandler(void);
void DefaultHandler(void);

// Cortex-M system exceptions
void NMI_Handler(void) __attribute__((weak, alias("DefaultHandler")));
void HardFault_Handler(void) __attribute__((weak, alias("DefaultHandler")));
void MemManage_Handler(void) __attribute__((weak, alias("DefaultHandler")));
void BusFault_Handler(void) __attribute__((weak, alias("DefaultHandler")));
void UsageFault_Handler(void) __attribute__((weak, alias("DefaultHandler")));
void SVC_Handler(void) __attribute__((weak, alias("DefaultHandler")));
void DebugMon_Handler(void) __attribute__((weak, alias("DefaultHandler")));
void PendSV_Handler(void) __attribute__((weak, alias("DefaultHandler")));
void SysTick_Handler(void);

// STM32G491RET6 interrupt handlers
void WWDG_IRQHandler(void) __attribute__((weak, alias("DefaultHandler")));
void PVD_PVM_IRQHandler(void) __attribute__((weak, alias("DefaultHandler")));
void RTC_TAMP_LSECSS_IRQHandler(void) __attribute__((weak, alias("DefaultHandler")));
void RTC_WKUP_IRQHandler(void) __attribute__((weak, alias("DefaultHandler")));
void FLASH_IRQHandler(void) __attribute__((weak, alias("DefaultHandler")));
void RCC_IRQHandler(void) __attribute__((weak, alias("DefaultHandler")));
void EXTI0_IRQHandler(void) __attribute__((weak, alias("DefaultHandler")));
void EXTI1_IRQHandler(void) __attribute__((weak, alias("DefaultHandler")));
void EXTI2_IRQHandler(void) __attribute__((weak, alias("DefaultHandler")));
void EXTI3_IRQHandler(void) __attribute__((weak, alias("DefaultHandler")));
void EXTI4_IRQHandler(void) __attribute__((weak, alias("DefaultHandler")));
void DMA1_Channel1_IRQHandler(void) __attribute__((weak, alias("DefaultHandler")));
void DMA1_Channel2_IRQHandler(void) __attribute__((weak, alias("DefaultHandler")));
void DMA1_Channel3_IRQHandler(void) __attribute__((weak, alias("DefaultHandler")));
void DMA1_Channel4_IRQHandler(void) __attribute__((weak, alias("DefaultHandler")));
void DMA1_Channel5_IRQHandler(void) __attribute__((weak, alias("DefaultHandler")));
void DMA1_Channel6_IRQHandler(void) __attribute__((weak, alias("DefaultHandler")));
void DMA1_Channel7_IRQHandler(void) __attribute__((weak, alias("DefaultHandler")));
void ADC1_2_IRQHandler(void) __attribute__((weak, alias("DefaultHandler")));
void USB_HP_IRQHandler(void) __attribute__((weak, alias("DefaultHandler")));
void USB_LP_IRQHandler(void) __attribute__((weak, alias("DefaultHandler")));
void FDCAN1_IT0_IRQHandler(void) __attribute__((weak, alias("DefaultHandler")));
void FDCAN1_IT1_IRQHandler(void) __attribute__((weak, alias("DefaultHandler")));
void EXTI9_5_IRQHandler(void) __attribute__((weak, alias("DefaultHandler")));
void TIM1_BRK_TIM15_IRQHandler(void) __attribute__((weak, alias("DefaultHandler")));
void TIM1_UP_TIM16_IRQHandler(void) __attribute__((weak, alias("DefaultHandler")));
void TIM1_TRG_COM_TIM17_IRQHandler(void) __attribute__((weak, alias("DefaultHandler")));
void TIM1_CC_IRQHandler(void) __attribute__((weak, alias("DefaultHandler")));
void TIM2_IRQHandler(void) __attribute__((weak, alias("DefaultHandler")));
void TIM3_IRQHandler(void) __attribute__((weak, alias("DefaultHandler")));
void TIM4_IRQHandler(void) __attribute__((weak, alias("DefaultHandler")));
void I2C1_EV_IRQHandler(void) __attribute__((weak, alias("DefaultHandler")));
void I2C1_ER_IRQHandler(void) __attribute__((weak, alias("DefaultHandler")));
void I2C2_EV_IRQHandler(void) __attribute__((weak, alias("DefaultHandler")));
void I2C2_ER_IRQHandler(void) __attribute__((weak, alias("DefaultHandler")));
void SPI1_IRQHandler(void) __attribute__((weak, alias("DefaultHandler")));
void SPI2_IRQHandler(void) __attribute__((weak, alias("DefaultHandler")));
void USART1_IRQHandler(void) __attribute__((weak, alias("DefaultHandler")));
void USART2_IRQHandler(void) __attribute__((weak, alias("DefaultHandler")));
void USART3_IRQHandler(void) __attribute__((weak, alias("DefaultHandler")));
void EXTI15_10_IRQHandler(void) __attribute__((weak, alias("DefaultHandler")));
void RTC_Alarm_IRQHandler(void) __attribute__((weak, alias("DefaultHandler")));
void USBWakeUp_IRQHandler(void) __attribute__((weak, alias("DefaultHandler")));
void TIM8_BRK_IRQHandler(void) __attribute__((weak, alias("DefaultHandler")));
void TIM8_UP_IRQHandler(void) __attribute__((weak, alias("DefaultHandler")));
void TIM8_TRG_COM_IRQHandler(void) __attribute__((weak, alias("DefaultHandler")));
void TIM8_CC_IRQHandler(void) __attribute__((weak, alias("DefaultHandler")));
void ADC3_IRQHandler(void) __attribute__((weak, alias("DefaultHandler")));
void LPTIM1_IRQHandler(void) __attribute__((weak, alias("DefaultHandler")));
void SPI3_IRQHandler(void) __attribute__((weak, alias("DefaultHandler")));
void UART4_IRQHandler(void) __attribute__((weak, alias("DefaultHandler")));
void UART5_IRQHandler(void) __attribute__((weak, alias("DefaultHandler")));
void TIM6_DAC_IRQHandler(void) __attribute__((weak, alias("DefaultHandler")));
void TIM7_IRQHandler(void) __attribute__((weak, alias("DefaultHandler")));
void DMA2_Channel1_IRQHandler(void) __attribute__((weak, alias("DefaultHandler")));
void DMA2_Channel2_IRQHandler(void) __attribute__((weak, alias("DefaultHandler")));
void DMA2_Channel3_IRQHandler(void) __attribute__((weak, alias("DefaultHandler")));
void DMA2_Channel4_IRQHandler(void) __attribute__((weak, alias("DefaultHandler")));
void DMA2_Channel5_IRQHandler(void) __attribute__((weak, alias("DefaultHandler")));
void UCPD1_IRQHandler(void) __attribute__((weak, alias("DefaultHandler")));
void COMP1_2_3_IRQHandler(void) __attribute__((weak, alias("DefaultHandler")));
void COMP4_IRQHandler(void) __attribute__((weak, alias("DefaultHandler")));
void CRS_IRQHandler(void) __attribute__((weak, alias("DefaultHandler")));
void SAI1_IRQHandler(void) __attribute__((weak, alias("DefaultHandler")));
void TIM20_BRK_IRQHandler(void) __attribute__((weak, alias("DefaultHandler")));
void TIM20_UP_IRQHandler(void) __attribute__((weak, alias("DefaultHandler")));
void TIM20_TRG_COM_IRQHandler(void) __attribute__((weak, alias("DefaultHandler")));
void TIM20_CC_IRQHandler(void) __attribute__((weak, alias("DefaultHandler")));
void FPU_IRQHandler(void) __attribute__((weak, alias("DefaultHandler")));
void FDCAN2_IT0_IRQHandler(void) __attribute__((weak, alias("DefaultHandler")));
void FDCAN2_IT1_IRQHandler(void) __attribute__((weak, alias("DefaultHandler")));
void RNG_IRQHandler(void) __attribute__((weak, alias("DefaultHandler")));
void LPUART1_IRQHandler(void) __attribute__((weak, alias("DefaultHandler")));
void I2C3_EV_IRQHandler(void) __attribute__((weak, alias("DefaultHandler")));
void I2C3_ER_IRQHandler(void) __attribute__((weak, alias("DefaultHandler")));
void DMAMUX_OVR_IRQHandler(void) __attribute__((weak, alias("DefaultHandler")));
void QUADSPI_IRQHandler(void) __attribute__((weak, alias("DefaultHandler")));
void DMA1_Channel8_IRQHandler(void) __attribute__((weak, alias("DefaultHandler")));
void DMA2_Channel6_IRQHandler(void) __attribute__((weak, alias("DefaultHandler")));
void DMA2_Channel7_IRQHandler(void) __attribute__((weak, alias("DefaultHandler")));
void DMA2_Channel8_IRQHandler(void) __attribute__((weak, alias("DefaultHandler")));
void CORDIC_IRQHandler(void) __attribute__((weak, alias("DefaultHandler")));
void FMAC_IRQHandler(void) __attribute__((weak, alias("DefaultHandler")));
