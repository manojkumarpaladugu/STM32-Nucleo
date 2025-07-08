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
#include "IConsumer.hpp"

// ----------------------------------------------------------------------------
// Class definition
// ----------------------------------------------------------------------------

class LogToUart final : public IConsumer
{
public:

    /**
     * @brief Process a log message and output it to UART
     *
     * @param[in] message Pointer to the log message.
     * @param[in] length Length of the log message.
     */
    void ProcessLogMessage(const uint8_t* message, size_t length) override;
};
