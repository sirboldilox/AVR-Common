# Makefile for AVRisp MKII
#
# Required Packages:
#   avr-gcc         (AVR Compiler)
#   avr-libc        (AVR C Libraries)
#   avrdude         (AVR Programmer toolkit)
#

# Chip
MCU = attiny85
#MCU = attiny44

# Paramaters
MAIN=blink

CC = avr-gcc
CFLAGS = -O -Wall -mmcu=$(MCU) --std=c99

OBJCOPY = avr-objcopy

ISP = avrispmkII
FUSE = -U lfuse:w:0x62:m -U hfuse:w:0x57:m -U efuse:w:0xff:m 

all: $(MAIN)

$(MAIN): $(MAIN).c
	$(CC) $(CFLAGS) $(MAIN).c -o $(MAIN).elf
	$(OBJCOPY) -O ihex $(MAIN).elf $(MAIN).hex 

flash: $(MAIN).hex
	avrdude -p $(MCU) -c $(ISP) -U flash:w:$(MAIN).hex 

clean:
	rm -f *.elf *.hex *.o

rebuild: clean all

reflash: rebuild flash
