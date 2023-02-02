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
_7_SEGMENT_WITH_EXTERNAL_INTURRUPT.lss \

FLASH_IMAGE += \
_7_SEGMENT_WITH_EXTERNAL_INTURRUPT.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: _7_SEGMENT_WITH_EXTERNAL_INTURRUPT.elf secondary-outputs

# Tool invocations
_7_SEGMENT_WITH_EXTERNAL_INTURRUPT.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,_7_SEGMENT_WITH_EXTERNAL_INTURRUPT.map -mmcu=atmega32 -o "_7_SEGMENT_WITH_EXTERNAL_INTURRUPT.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

_7_SEGMENT_WITH_EXTERNAL_INTURRUPT.lss: _7_SEGMENT_WITH_EXTERNAL_INTURRUPT.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S _7_SEGMENT_WITH_EXTERNAL_INTURRUPT.elf  >"_7_SEGMENT_WITH_EXTERNAL_INTURRUPT.lss"
	@echo 'Finished building: $@'
	@echo ' '

_7_SEGMENT_WITH_EXTERNAL_INTURRUPT.hex: _7_SEGMENT_WITH_EXTERNAL_INTURRUPT.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex _7_SEGMENT_WITH_EXTERNAL_INTURRUPT.elf  "_7_SEGMENT_WITH_EXTERNAL_INTURRUPT.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: _7_SEGMENT_WITH_EXTERNAL_INTURRUPT.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 _7_SEGMENT_WITH_EXTERNAL_INTURRUPT.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) _7_SEGMENT_WITH_EXTERNAL_INTURRUPT.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
