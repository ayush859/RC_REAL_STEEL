# RC Car Firmware System

## Table of Contents

* [Aim](#aim)
* [Hardware and Software Requirements](#hardware-and-software-requirements)
* [Project Directory Structure](#project-directory-structure)
* [Build and Flash Instructions](#build-and-flash-instructions)
* [Screenshots / Diagrams](#screenshots--diagrams)

---

## AIM

This firmware project aims to enable remote control of an RC car using a Wi-Fi module and UART communication to an Arduino or motor driver. It supports basic command reception and forwarding, providing a modular approach with separate components for Wi-Fi communication and UART interfacing. The system is designed for STM32-based microcontrollers, supporting cross-compilation and flashing through CMake and OpenOCD. It serves as a lightweight and customizable embedded control system for smart vehicle applications or robotics projects.

---

## HARDWARE AND SOFTWARE REQUIREMENTS

* **Hardware:**

  * STM32 Microcontroller Board
  * Arduino (Motor Controller or Bridge to RC Car Hardware)
  * Wi-Fi Module (e.g., ESP8266 or ESP01)
  * USB to UART or ST-Link V2 for flashing

* **Software:**

  * Linux x86 (Development and flashing environment)
  * ARM GCC Toolchain (arm-none-eabi)
  * CMake (>= 3.15) — Build automation and code organization tool
  * OpenOCD — For flashing STM32 microcontrollers

---

## PROJECT DIRECTORY STRUCTURE

```
microcontroller/
├── src/
│   ├── main.c
│   ├── wifi_module.c
│   └── uart_module.c
├── include/
│   ├── wifi_module.h
│   └── uart_module.h
├── CMakeLists.txt
├── stm32_toolchain.cmake
└── scripts/
    ├── flash.sh
    └── setup_env.sh
```

---

## BUILD AND FLASH INSTRUCTIONS

1. **Set Up Environment**

   ```bash
   source scripts/setup_env.sh
   ```

2. **Create Build Directory**

   ```bash
   mkdir build && cd build
   ```

3. **Configure with CMake**

   ```bash
   cmake -DCMAKE_TOOLCHAIN_FILE=../stm32_toolchain.cmake ..
   ```

4. **Build the Project**

   ```bash
   cmake --build .
   ```

5. **Flash the Firmware**

   ```bash
   ../scripts/flash.sh
   ```

---

## SCREENSHOTS / DIAGRAMS

### 1. System Block Diagram

<p align="center">
  <img src="https://user-images.githubusercontent.com/your-placeholder/system-diagram.png" alt="System Block Diagram" width="600">
</p>
<p align="center"><i>Figure 1: RC Car System Architecture</i></p>

---

### 2. Microcontroller Firmware Flow

<p align="center">
  <img src="https://user-images.githubusercontent.com/your-placeholder/firmware-flow.png" alt="Firmware Flow" width="600">
</p>
<p align="center"><i>Figure 2: Firmware Logical Flow</i></p>

---

### 3. Build Output & Flash Confirmation

<p align="center">
  <img src="https://user-images.githubusercontent.com/your-placeholder/build-output.png" alt="Build Output" width="600">
</p>
<p align="center"><i>Figure 3: Successful Build and Flash via OpenOCD</i></p>


