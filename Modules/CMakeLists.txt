#
# SPDX-License-Identifier: Apache-2.0
#
# Author: Manoj Kumar Paladugu <paladugumanojkumar@gmail.com>
#

cmake_minimum_required(VERSION 4.0.0)

# Configure logging settings
set(CONFIG_LIB_COMMONS_LOGGING y)
set(CONFIG_LIB_COMMONS_LOGGING_MAX_CONSUMERS 1)
set(CONFIG_LIB_COMMONS_LOGGING_MAX_STRING_LENGTH 128)

add_subdirectory(Commons)