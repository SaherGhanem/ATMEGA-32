################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
INC_DEC_7_SEGMENT.lss \

FLASH_IMAGE += \
INC_DEC_7_SEGMENT.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: INC_DEC_7_SEGMENT.elf secondary-outputs

# Tool invocations
INC_DEC_7_SEGMENT.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,INC_DEC_7_SEGMENT.map -mmcu=atmega32 -o "INC_DEC_7_SEGMENT.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

INC_DEC_7_SEGMENT.lss: INC_DEC_7_SEGMENT.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S INC_DEC_7_SEGMENT.elf  >"INC_DEC_7_SEGMENT.lss"
	@echo 'Finished building: $@'
	@echo ' '

INC_DEC_7_SEGMENT.hex: INC_DEC_7_SEGMENT.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex INC_DEC_7_SEGMENT.elf  "INC_DEC_7_SEGMENT.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: INC_DEC_7_SEGMENT.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 INC_DEC_7_SEGMENT.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) INC_DEC_7_SEGMENT.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
