#pragma once

// Includes -------------------------------------------------------------
#include <cstdint>

// Exported functions prototypes ----------------------------------------
/**
  * @brief Initializes system and it's peripherals
  * @param None
  * @retval None
  */
void System_OneTimeInitialization(void);

/**
  * @brief Writes data stream to UART port
  * @param pData  pointer to the data stream
  * @param size   size of data stream
  * @retval None
  */
void System_UartPrint(const uint8_t *pData, uint16_t size);

/**
  * @brief Toggles user LED
  * @param None
  * @retval None
  */
void System_ToggleUserLed(void);

/**
  * @brief Delay by the specified amount of time
  * @param delay delay in milliseconds
  * @retval None
  */
void System_Delay(uint32_t delay);
