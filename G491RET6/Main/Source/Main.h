#include <inttypes.h>

#define BIT(n) (1<<(n))

#define PERIPHERAL_BASE         (0x40000000U)
#define AHB1_RCC_BASE           (0x40021000U)
#define AHB2_GPIOA_BASE         (0x48000000U)

#define RCC_AHB2ENR_OFFSET      (0x4CU)
#define RCC_AHB2ENR_BASE        ((volatile uint32_t*)(AHB1_RCC_BASE + RCC_AHB2ENR_OFFSET))
#define RCC_AHB2ENR_GPIOAEN_BIT BIT(0)

#define GPIOA_MODER_OFFSET      (0x0U)
#define GPIOA_MODER_BASE        ((volatile uint32_t*)(AHB2_GPIOA_BASE + GPIOA_MODER_OFFSET))
#define GPIO_MODER_MODER5       (10U)
#define GPIOA_ODR_OFFSET        (0x14U)
#define GPIOA_ODR_BASE          ((volatile uint32_t*)(AHB2_GPIOA_BASE + GPIOA_ODR_OFFSET))

#define USER_LED_PIN5           BIT(5)
