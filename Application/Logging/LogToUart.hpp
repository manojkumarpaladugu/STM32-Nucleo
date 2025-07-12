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
#include "LogToOutput.hpp"

// ----------------------------------------------------------------------------
// Class definition
// ----------------------------------------------------------------------------

class LogToUart final : public LogToOutput
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
