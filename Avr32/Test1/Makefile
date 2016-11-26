# ------------------------------------------------
# Makefile for C projects
# ------------------------------------------------

# project name (generate executable with this name)
TARGET     = out

#DEVICE     = attiny2313
DEVICE     = atmega32
CLOCK      = 8000000
PROGRAMMER = -c arduino -P /dev/ttyACM0 -b 19200
FUSES      = -U lfuse:w:0x64:m -U hfuse:w:0xdd:m -U efuse:w:0xff:m

CC         = gcc
# compiling flags here
CFLAGS     = -std=c99 -Wall -I.

AVRDUDE = avrdude $(PROGRAMMER) -p $(DEVICE)
COMPILE = avr-gcc -Wall -Os -DF_CPU=$(CLOCK) -mmcu=$(DEVICE)

LINKER   = gcc -o
# linking flags here
LFLAGS   = -Wall -I. -lm

# change these to proper directories where each file should be
SRCDIR   = src
INCDIR   = inc
OBJDIR   = obj
BINDIR   = bin
HEXDIR   = hex
ELFDIR   = elf
ASSDIR   = s

SOURCES  := $(wildcard $(SRCDIR)/*.c)
INCLUDES := $(wildcard $(INCDIR)/*.h)
OBJECTS  := $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
rm       = rm -f

all: $(HEXDIR)/out.hex

$(BINDIR)/$(TARGET): $(OBJECTS)
	@$(COMPILE) $(CFLAGS) $(OBJECTS) -o $@
	@echo "Linking complete!"

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.c
	@$(COMPILE) $(CFLAGS) -c $< -o $@
	@echo "Compiled "$<" successfully!"

$(ASSDIR)/$(TARGET): $(SOURCES)
	@$(COMPILE) -S $< -o $@

# file targets:
$(ELFDIR)/out.elf: $(OBJECTS)
	$(COMPILE) -o $@ $(OBJECTS)

$(HEXDIR)/out.hex: $(ELFDIR)/out.elf
	rm -f $@
	avr-objcopy -j .text -j .data -O ihex $(ELFDIR)/out.elf $(HEXDIR)/out.hex
# If you have an EEPROM section, you must also create a hex file for the
# EEPROM and add it to the "flash" target.

.PHONY: flash
flash:	all
	$(AVRDUDE) -U flash:w:$(HEXDIR)/out.hex:i

.PHONY: fuse
fuse:
	$(AVRDUDE) $(FUSES)

.PHONY: clean
clean:
	@$(rm) $(OBJECTS)
	@echo "Cleanup complete!"

install: flash fuse

.PHONY: remove
remove: clean
	@$(rm) $(BINDIR)/$(TARGET)
	@echo "Executable removed!"
