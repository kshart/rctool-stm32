#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=arm-none-eabi-gcc
CCC=arm-none-eabi-g++
CXX=arm-none-eabi-g++
FC=gfortran
AS=arm-none-eabi-as

# Macros
CND_PLATFORM=MinGW-Windows
CND_DLIB_EXT=dll
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal.o \
	${OBJECTDIR}/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_cortex.o \
	${OBJECTDIR}/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.o \
	${OBJECTDIR}/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_exti.o \
	${OBJECTDIR}/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_flash.o \
	${OBJECTDIR}/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_flash_ex.o \
	${OBJECTDIR}/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_gpio.o \
	${OBJECTDIR}/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_gpio_ex.o \
	${OBJECTDIR}/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_pwr.o \
	${OBJECTDIR}/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_rcc.o \
	${OBJECTDIR}/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_rcc_ex.o \
	${OBJECTDIR}/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_tim.o \
	${OBJECTDIR}/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_tim_ex.o \
	${OBJECTDIR}/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_uart.o \
	${OBJECTDIR}/src/core/PackageBuffer.o \
	${OBJECTDIR}/src/core/PackageManager.o \
	${OBJECTDIR}/src/core/gpio.o \
	${OBJECTDIR}/src/core/stm32f1xx_hal_msp.o \
	${OBJECTDIR}/src/core/stm32f1xx_it.o \
	${OBJECTDIR}/src/core/system_stm32f1xx.o \
	${OBJECTDIR}/src/core/tim.o \
	${OBJECTDIR}/src/core/usart.o \
	${OBJECTDIR}/src/hc05/hc05.o \
	${OBJECTDIR}/src/hc05/package.o \
	${OBJECTDIR}/src/main.o \
	${OBJECTDIR}/startup_stm32f103x6.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/rctool-stm32.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/rctool-stm32.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/rctool-stm32 ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal.o: Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal.c
	${MKDIR} -p ${OBJECTDIR}/Drivers/STM32F1xx_HAL_Driver/Src
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal.o Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal.c

${OBJECTDIR}/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_cortex.o: Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_cortex.c
	${MKDIR} -p ${OBJECTDIR}/Drivers/STM32F1xx_HAL_Driver/Src
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_cortex.o Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_cortex.c

${OBJECTDIR}/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.o: Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.c
	${MKDIR} -p ${OBJECTDIR}/Drivers/STM32F1xx_HAL_Driver/Src
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.o Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.c

${OBJECTDIR}/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_exti.o: Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_exti.c
	${MKDIR} -p ${OBJECTDIR}/Drivers/STM32F1xx_HAL_Driver/Src
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_exti.o Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_exti.c

${OBJECTDIR}/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_flash.o: Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_flash.c
	${MKDIR} -p ${OBJECTDIR}/Drivers/STM32F1xx_HAL_Driver/Src
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_flash.o Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_flash.c

${OBJECTDIR}/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_flash_ex.o: Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_flash_ex.c
	${MKDIR} -p ${OBJECTDIR}/Drivers/STM32F1xx_HAL_Driver/Src
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_flash_ex.o Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_flash_ex.c

${OBJECTDIR}/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_gpio.o: Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_gpio.c
	${MKDIR} -p ${OBJECTDIR}/Drivers/STM32F1xx_HAL_Driver/Src
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_gpio.o Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_gpio.c

${OBJECTDIR}/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_gpio_ex.o: Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_gpio_ex.c
	${MKDIR} -p ${OBJECTDIR}/Drivers/STM32F1xx_HAL_Driver/Src
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_gpio_ex.o Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_gpio_ex.c

${OBJECTDIR}/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_pwr.o: Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_pwr.c
	${MKDIR} -p ${OBJECTDIR}/Drivers/STM32F1xx_HAL_Driver/Src
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_pwr.o Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_pwr.c

${OBJECTDIR}/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_rcc.o: Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_rcc.c
	${MKDIR} -p ${OBJECTDIR}/Drivers/STM32F1xx_HAL_Driver/Src
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_rcc.o Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_rcc.c

${OBJECTDIR}/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_rcc_ex.o: Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_rcc_ex.c
	${MKDIR} -p ${OBJECTDIR}/Drivers/STM32F1xx_HAL_Driver/Src
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_rcc_ex.o Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_rcc_ex.c

${OBJECTDIR}/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_tim.o: Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_tim.c
	${MKDIR} -p ${OBJECTDIR}/Drivers/STM32F1xx_HAL_Driver/Src
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_tim.o Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_tim.c

${OBJECTDIR}/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_tim_ex.o: Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_tim_ex.c
	${MKDIR} -p ${OBJECTDIR}/Drivers/STM32F1xx_HAL_Driver/Src
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_tim_ex.o Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_tim_ex.c

${OBJECTDIR}/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_uart.o: Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_uart.c
	${MKDIR} -p ${OBJECTDIR}/Drivers/STM32F1xx_HAL_Driver/Src
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_uart.o Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_uart.c

${OBJECTDIR}/src/core/PackageBuffer.o: src/core/PackageBuffer.cpp
	${MKDIR} -p ${OBJECTDIR}/src/core
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/core/PackageBuffer.o src/core/PackageBuffer.cpp

${OBJECTDIR}/src/core/PackageManager.o: src/core/PackageManager.cpp
	${MKDIR} -p ${OBJECTDIR}/src/core
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/core/PackageManager.o src/core/PackageManager.cpp

${OBJECTDIR}/src/core/gpio.o: src/core/gpio.c
	${MKDIR} -p ${OBJECTDIR}/src/core
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/core/gpio.o src/core/gpio.c

${OBJECTDIR}/src/core/stm32f1xx_hal_msp.o: src/core/stm32f1xx_hal_msp.c
	${MKDIR} -p ${OBJECTDIR}/src/core
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/core/stm32f1xx_hal_msp.o src/core/stm32f1xx_hal_msp.c

${OBJECTDIR}/src/core/stm32f1xx_it.o: src/core/stm32f1xx_it.c
	${MKDIR} -p ${OBJECTDIR}/src/core
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/core/stm32f1xx_it.o src/core/stm32f1xx_it.c

${OBJECTDIR}/src/core/system_stm32f1xx.o: src/core/system_stm32f1xx.c
	${MKDIR} -p ${OBJECTDIR}/src/core
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/core/system_stm32f1xx.o src/core/system_stm32f1xx.c

${OBJECTDIR}/src/core/tim.o: src/core/tim.c
	${MKDIR} -p ${OBJECTDIR}/src/core
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/core/tim.o src/core/tim.c

${OBJECTDIR}/src/core/usart.o: src/core/usart.c
	${MKDIR} -p ${OBJECTDIR}/src/core
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/core/usart.o src/core/usart.c

${OBJECTDIR}/src/hc05/hc05.o: src/hc05/hc05.c
	${MKDIR} -p ${OBJECTDIR}/src/hc05
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/hc05/hc05.o src/hc05/hc05.c

${OBJECTDIR}/src/hc05/package.o: src/hc05/package.c
	${MKDIR} -p ${OBJECTDIR}/src/hc05
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/hc05/package.o src/hc05/package.c

${OBJECTDIR}/src/main.o: src/main.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/main.o src/main.cpp

${OBJECTDIR}/startup_stm32f103x6.o: startup_stm32f103x6.s
	${MKDIR} -p ${OBJECTDIR}
	$(AS) $(ASFLAGS) -o ${OBJECTDIR}/startup_stm32f103x6.o startup_stm32f103x6.s

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
