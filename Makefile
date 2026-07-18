CC = gcc
LD = ld
AS = nasm

CFLAGS = -ffreestanding -m32 -Wall -Wextra
ASFLAGS = -f elf32

ISO = build/GUAOS.iso

all: $(ISO)

build/boot.o: boot/boot.asm
	mkdir -p build
	$(AS) $(ASFLAGS) boot/boot.asm -o build/boot.o

build/kernel.o: kernel/kernel.c
	$(CC) $(CFLAGS) -c kernel/kernel.c -o build/kernel.o
build/keyboard.o: kernel/keyboard.c
	$(CC) $(CFLAGS) -c kernel/keyboard.c -o build/keyboard.o
build/io.o: kernel/io.c
	$(CC) $(CFLAGS) -c kernel/io.c -o build/io.o

build/kernel.elf: build/boot.o build/kernel.o build/io.o build/keyboard.o linker.ld
	$(LD) -m elf_i386 -T linker.ld -o build/kernel.elf \
		build/boot.o build/kernel.o build/io.o build/keyboard.o

$(ISO): build/kernel.elf
	mkdir -p iso/boot
	cp build/kernel.elf iso/boot/kernel.elf
	grub-mkrescue -o $(ISO) iso

clean:
	rm -rf build