// Includes -------------------------------------------------------------
#include "System.h"

// Private variables ----------------------------------------------------
uint8_t tx_buffer[] = "Welcome to UART programming!\n\r";
uint8_t tx_buffer2[] = "Welcome Manoj!\n\r";

// Private functions ----------------------------------------------------
int main(void)
{
    System_OneTimeInitialization();

    while (1)
    {
        System_UartPrint(tx_buffer, 30);
        System_Delay(1000);
        System_UartPrint(tx_buffer2, 17);
        System_Delay(1000);
        System_ToggleUserLed();
    }
}
