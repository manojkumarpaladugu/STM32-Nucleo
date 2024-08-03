// Includes ------------------------------------------------------------
#include "Startup.h"

// External variables ---------------------------------------------------
extern uint32_t _sidata, _sdata, _edata, _sbss, _ebss;

// Private variables ---------------------------------------------------
uint32_t isr_vector[ISR_VECTOR_SIZE_WORDS] __attribute__((section(".isr_vector"))) = {
  STACK_ADDRESS,
  // Cortex-M system exceptions
  (uint32_t)&ResetHandler,
  (uint32_t)&NMI_Handler,
  (uint32_t)&HardFault_Handler,
  (uint32_t)&MemManage_Handler,
  (uint32_t)&BusFault_Handler,
  (uint32_t)&UsageFault_Handler,
  0,
  0,
  0,
  0,
  (uint32_t)&SVC_Handler,
  (uint32_t)&DebugMon_Handler,
  0,
  (uint32_t)&PendSV_Handler,
  (uint32_t)&SysTick_Handler,
  // STM32G491RET6 interrupt handlers
  (uint32_t)&WWDG_IRQHandler,
  (uint32_t)&PVD_PVM_IRQHandler,
  (uint32_t)&RTC_TAMP_LSECSS_IRQHandler,
  (uint32_t)&RTC_WKUP_IRQHandler,
  (uint32_t)&FLASH_IRQHandler,
  (uint32_t)&RCC_IRQHandler,
  (uint32_t)&EXTI0_IRQHandler,
  (uint32_t)&EXTI1_IRQHandler,
  (uint32_t)&EXTI2_IRQHandler,
  (uint32_t)&EXTI3_IRQHandler,
  (uint32_t)&EXTI4_IRQHandler,
  (uint32_t)&DMA1_Channel1_IRQHandler,
  (uint32_t)&DMA1_Channel2_IRQHandler,
  (uint32_t)&DMA1_Channel3_IRQHandler,
  (uint32_t)&DMA1_Channel4_IRQHandler,
  (uint32_t)&DMA1_Channel5_IRQHandler,
  (uint32_t)&DMA1_Channel6_IRQHandler,
  (uint32_t)&DMA1_Channel7_IRQHandler,
  (uint32_t)&ADC1_2_IRQHandler,
  (uint32_t)&USB_HP_IRQHandler,
  (uint32_t)&USB_LP_IRQHandler,
  (uint32_t)&FDCAN1_IT0_IRQHandler,
  (uint32_t)&FDCAN1_IT1_IRQHandler,
  (uint32_t)&EXTI9_5_IRQHandler,
  (uint32_t)&TIM1_BRK_TIM15_IRQHandler,
  (uint32_t)&TIM1_UP_TIM16_IRQHandler,
  (uint32_t)&TIM1_TRG_COM_TIM17_IRQHandler,
  (uint32_t)&TIM1_CC_IRQHandler,
  (uint32_t)&TIM2_IRQHandler,
  (uint32_t)&TIM3_IRQHandler,
  (uint32_t)&TIM4_IRQHandler,
  (uint32_t)&I2C1_EV_IRQHandler,
  (uint32_t)&I2C1_ER_IRQHandler,
  (uint32_t)&I2C2_EV_IRQHandler,
  (uint32_t)&I2C2_ER_IRQHandler,
  (uint32_t)&SPI1_IRQHandler,
  (uint32_t)&SPI2_IRQHandler,
  (uint32_t)&USART1_IRQHandler,
  (uint32_t)&USART2_IRQHandler,
  (uint32_t)&USART3_IRQHandler,
  (uint32_t)&EXTI15_10_IRQHandler,
  (uint32_t)&RTC_Alarm_IRQHandler,
  (uint32_t)&USBWakeUp_IRQHandler,
  (uint32_t)&TIM8_BRK_IRQHandler,
  (uint32_t)&TIM8_UP_IRQHandler,
  (uint32_t)&TIM8_TRG_COM_IRQHandler,
  (uint32_t)&TIM8_CC_IRQHandler,
  (uint32_t)&ADC3_IRQHandler,
  0,
  (uint32_t)&LPTIM1_IRQHandler,
  0,
  (uint32_t)&SPI3_IRQHandler,
  (uint32_t)&UART4_IRQHandler,
  (uint32_t)&UART5_IRQHandler,
  (uint32_t)&TIM6_DAC_IRQHandler,
  (uint32_t)&TIM7_IRQHandler,
  (uint32_t)&DMA2_Channel1_IRQHandler,
  (uint32_t)&DMA2_Channel2_IRQHandler,
  (uint32_t)&DMA2_Channel3_IRQHandler,
  (uint32_t)&DMA2_Channel4_IRQHandler,
  (uint32_t)&DMA2_Channel5_IRQHandler,
  0,
  0,
  (uint32_t)&UCPD1_IRQHandler,
  (uint32_t)&COMP1_2_3_IRQHandler,
  (uint32_t)&COMP4_IRQHandler,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  (uint32_t)&CRS_IRQHandler,
  (uint32_t)&SAI1_IRQHandler,
  (uint32_t)&TIM20_BRK_IRQHandler,
  (uint32_t)&TIM20_UP_IRQHandler,
  (uint32_t)&TIM20_TRG_COM_IRQHandler,
  (uint32_t)&TIM20_CC_IRQHandler,
  (uint32_t)&FPU_IRQHandler,
  0,
  0,
  0,
  0,
  (uint32_t)&FDCAN2_IT0_IRQHandler,
  (uint32_t)&FDCAN2_IT1_IRQHandler,
  0,
  0,
  (uint32_t)&RNG_IRQHandler,
  (uint32_t)&LPUART1_IRQHandler,
  (uint32_t)&I2C3_EV_IRQHandler,
  (uint32_t)&I2C3_ER_IRQHandler,
  (uint32_t)&DMAMUX_OVR_IRQHandler,
  (uint32_t)&QUADSPI_IRQHandler,
  (uint32_t)&DMA1_Channel8_IRQHandler,
  (uint32_t)&DMA2_Channel6_IRQHandler,
  (uint32_t)&DMA2_Channel7_IRQHandler,
  (uint32_t)&DMA2_Channel8_IRQHandler,
  (uint32_t)&CORDIC_IRQHandler,
  (uint32_t)&FMAC_IRQHandler
};

// External functions prototypes ----------------------------------------
extern void main(void);

// Private functions ----------------------------------------------------
/**
  * @brief This function handles System tick timer
  * @param None
  * @retval None
  */
void SysTick_Handler(void)
{
  HAL_IncTick();
}

/**
  * @brief This is the default handler for most of the system exceptions
  * @param None
  * @retval None
  */
void DefaultHandler(void)
{
  while(1);
}

/**
  * @brief This function is the entry point that gets executed on CPU reset
  * @param None
  * @retval None
  */
void ResetHandler(void)
{
  // Copy .data from FLASH to SRAM
  uint32_t dataSize = (uint32_t)&_edata - (uint32_t)&_sdata;
  uint8_t *flashData = (uint8_t*) &_sidata;
  uint8_t *sramData = (uint8_t*) &_sdata;

  for (uint32_t i = 0; i < dataSize; i++)
  {
    sramData[i] = flashData[i];
  }

  // Zero-fill .bss section in SRAM
  uint32_t bssSize = (uint32_t)&_ebss - (uint32_t)&_sbss;
  uint8_t *bss = (uint8_t*) &_sbss;

  for (uint32_t i = 0; i < bssSize; i++)
  {
    bss[i] = 0;
  }

  SystemInit();

  // Jump to main function
  main();
}
