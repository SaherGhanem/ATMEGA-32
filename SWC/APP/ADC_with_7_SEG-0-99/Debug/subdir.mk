################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../7_Segment.c \
../ADC.c \
../DIO.c \
../Delay.c \
../LED.c \
../main.c 

OBJS += \
./7_Segment.o \
./ADC.o \
./DIO.o \
./Delay.o \
./LED.o \
./main.o 

C_DEPS += \
./7_Segment.d \
./ADC.d \
./DIO.d \
./Delay.d \
./LED.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


