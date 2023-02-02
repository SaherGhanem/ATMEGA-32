################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DIO.c \
../Delay.c \
../EXTI.c \
../GIE.c \
../LED.c \
../PUSHBUTTON.c \
../main.c 

OBJS += \
./DIO.o \
./Delay.o \
./EXTI.o \
./GIE.o \
./LED.o \
./PUSHBUTTON.o \
./main.o 

C_DEPS += \
./DIO.d \
./Delay.d \
./EXTI.d \
./GIE.d \
./LED.d \
./PUSHBUTTON.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


