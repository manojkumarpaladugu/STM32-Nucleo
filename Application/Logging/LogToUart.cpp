/*
 * SPDX-License-Identifier: Apache-2.0
 *
 * Author: Manoj Kumar Paladugu <paladugumanojkumar@gmail.com>
 */

// ----------------------------------------------------------------------------
// Header includes
// ----------------------------------------------------------------------------

#include "LogToUart.hpp"
#include "System.h"

// ----------------------------------------------------------------------------
// Public functions
// ----------------------------------------------------------------------------

void LogToUart::ProcessLogMessage(const uint8_t* message, size_t length)
{
    // Output the log message to standard output (UART in this case)
    System_UartPrint(message, length);
}
