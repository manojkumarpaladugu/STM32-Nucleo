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

void LogToUart::Initialize()
{

}

void LogToUart::ProcessLogMessage(const uint8_t* pMessage, size_t length)
{
    const uint8_t* pLogMessage = pMessage;
    size_t messageLength = length;

#if CONFIG_LIB_COMMONS_TOKENIZED_LOGGING
    size_t base64MessageLength = 0;
    const char* pBase64Message = ConvertToBase64(pLogMessage, messageLength, base64MessageLength);
    if( pBase64Message != nullptr)
    {
        pLogMessage = reinterpret_cast<const uint8_t*>(pBase64Message);
        messageLength = base64MessageLength;
    }
#endif

    // Output the log message to UART
    System_UartPrint(pLogMessage, messageLength);
}
