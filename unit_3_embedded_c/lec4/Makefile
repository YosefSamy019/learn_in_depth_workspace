#@ Youssef Samy Youssef
PROJ_NAME=toggle_led_tiva_c

CC=arm-none-eabi-
LIBS=
INCS=-I .
CFLAGS= -mcpu=cortex-m4 -mthumb -gdwarf-2 -g

SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

ASS = $(wildcard *.s)
ASS_OBJ = $(ASS:.s=.o)

all: $(PROJ_NAME).bin
	@echo "-------Build is Done-------"

%.o: %.c
	$(CC)gcc -c $(CFLAGS) $(INCS)  $< -o $@

%.o: %.s
	$(CC)as $(CFLAGS) $< -o $@

$(PROJ_NAME).elf: $(OBJ) $(ASS_OBJ)
	$(CC)ld -T linker_script.ld $(ASS_OBJ) $(OBJ) $(LIBS) -o $@ -Map=Map_file.map 
	cp $(PROJ_NAME).elf $(PROJ_NAME).axf

$(PROJ_NAME).bin: $(PROJ_NAME).elf
	$(CC)objcopy -O binary $< $@

clean:
	rm *.elf *.bin

clean-all:
	rm *.o *.elf *.bin

