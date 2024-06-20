#@ Youssef Samy Youssef
PROJ_NAME=learn-in-depth
CC=arm-none-eabi-
LIBS=
INCS=-I.
CFLAGS=-g -mcpu=arm926ej-s

SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)

all: $(PROJ_NAME).bin
	@echo "-------Build is Done"

%.o: %.c
	$(CC)gcc -c $(INCS) $(CFLAGS)  $< -o $@

%.o: %.s
	$(CC)as -g -mcpu=arm926ej-s $< -o $@

$(PROJ_NAME).elf: $(OBJ) startup.o
	$(CC)ld -T linker_script.ld startup.o $(OBJ) $(LIBS) -o $@ -Map=Map_file.map 

$(PROJ_NAME).bin: $(PROJ_NAME).elf
	$(CC)objcopy -O binary $< $@

clean:
	rm *.elf *.bin

clean-all:
	rm *.o *.elf *.bin

