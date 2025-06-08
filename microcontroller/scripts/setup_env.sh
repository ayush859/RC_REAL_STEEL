# Ensure that the path to your ARM GCC toolchain binaries is correctly specified.

#!/bin/bash

# Set environment variables for cross-compilation
export PATH=/usr/bin:$PATH
export CROSS_COMPILE=arm-none-eabi-
