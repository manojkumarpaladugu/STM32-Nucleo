/*
 * SPDX-License-Identifier: Apache-2.0
 *
 * Author: Manoj Kumar Paladugu <paladugumanojkumar@gmail.com>
 */

// ----------------------------------------------------------------------------
// Header includes
// ----------------------------------------------------------------------------

#define LOG_MODULE_NAME "main"
#define MODULE_LOG_LEVEL LOG_LEVEL_DEBUG
#define LOG_LINE_ENDING "\n\r"

// Must be included after the log level and module name definitions
#include "Logging.h"
#include "Assert.h"
#include "CommonTypes.h"
#include "LogCore.hpp"
#include "System.h"
#include "LogToUart.hpp"

#include <cstddef>

// Dummy implementation of _sbrk to avoid linking errors
extern "C" {
    void *_sbrk(ptrdiff_t incr) {
        UNUSED(incr);
        // Return an error as dynamic memory allocation is not used
        return (void *)-1;
    }
}

// ----------------------------------------------------------------------------
// Public functions
// ----------------------------------------------------------------------------
int main(void)
{
    System_OneTimeInitialization();

    // Register the consumer
    static LogToUart logToUart;
    LogCore::RegisterConsumer(cLogToUartId, logToUart);
    LOG_INFO("Logging initialized successfully");

    while (1)
    {
        LOG_DEBUG("This is a debug message");
        System_ToggleUserLed();
        System_Delay(1000);
        LOG_INFO("This is a info message");
        System_ToggleUserLed();
        System_Delay(1000);
        LOG_WARN("This is a warn message");
        System_ToggleUserLed();
        System_Delay(1000);
    }
}
