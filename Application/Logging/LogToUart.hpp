/*
 * SPDX-License-Identifier: Apache-2.0
 *
 * Author: Manoj Kumar Paladugu <paladugumanojkumar@gmail.com>
 */

#pragma once

// ----------------------------------------------------------------------------
// Header includes
// ----------------------------------------------------------------------------

#include "LogConsumerId.h"
#if CONFIG_LIB_COMMONS_TOKENIZED_LOGGING
    #include "TokenizedLogToOutput.hpp"
#else
    #include "LogToOutput.hpp"
#endif

// ----------------------------------------------------------------------------
// Class definition
// ----------------------------------------------------------------------------

#if CONFIG_LIB_COMMONS_TOKENIZED_LOGGING
class LogToUart final : public TokenizedLogToOutput
#else
class LogToUart final : public LogToOutput
#endif
{
public:

    /**
     * @brief Initialize the log consumer for UART output.
     */
    void Initialize() override;

    /**
     * @brief Process a log message and output it to UART
     *
     * @param[in] pMessage Pointer to the log message.
     * @param[in] length Length of the log message.
     */
    void ProcessLogMessage(const uint8_t* pMessage, size_t length) override;
};
