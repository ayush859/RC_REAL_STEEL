# stm32_toolchain.cmake

# Target system name
set(CMAKE_SYSTEM_NAME Generic)

# Target processor
set(CMAKE_SYSTEM_PROCESSOR arm)

# Specify the cross compiler
set(CMAKE_C_COMPILER arm-none-eabi-gcc)
set(CMAKE_CXX_COMPILER arm-none-eabi-g++)

# Specify the path to the toolchain
set(CMAKE_FIND_ROOT_PATH /usr/arm-none-eabi)

# Adjust the default behavior of the FIND_XXX() commands:
# Search programs in the host environment
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)

# Search headers and libraries in the target environment
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
