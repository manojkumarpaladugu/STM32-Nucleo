#include "Main.h"

int main(void)
{
    *RCC_AHB2ENR_BASE |= RCC_AHB2ENR_GPIOAEN_BIT;

    // do two dummy reads after enabling the peripheral clock, as per the errata
    volatile uint32_t dummy;
    dummy = *(RCC_AHB2ENR_BASE);
    dummy = *(RCC_AHB2ENR_BASE);

  *GPIOA_MODER_BASE |= (1 << GPIO_MODER_MODER5);

  while(1)
  {
    *GPIOA_ODR_BASE ^= (USER_LED_PIN5);
    for (uint32_t i = 0; i < 1000000; i++);
  }

    return 0;
}
