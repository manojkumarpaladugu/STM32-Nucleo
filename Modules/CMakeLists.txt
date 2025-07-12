#
# SPDX-License-Identifier: Apache-2.0
#
# Author: Manoj Kumar Paladugu <paladugumanojkumar@gmail.com>
#

cmake_minimum_required(VERSION 4.0.0)

# Configure logging settings
set(CONFIG_LIB_COMMONS_LOGGING ON)
set(CONFIG_LIB_COMMONS_LOGGING_TOKENIZED ON)
set(CONFIG_LIB_COMMONS_LOGGING_BASE64_ENCODING ON)
set(CONFIG_LIB_COMMONS_LOGGING_MAX_CONSUMERS 1)
set(CONFIG_LIB_COMMONS_LOGGING_BUFFER_SIZE 128)

add_subdirectory(Commons)
