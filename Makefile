CC = gcc
LD = ld

CFLAGS = -ffreestanding -m64 -Wall -Wextra

ISO = build/GUAOS.iso

all: $(ISO)

build/kernel.o: kernel/kernel.c
	mkdir -p build
	$(CC) $(CFLAGS) -c kernel/kernel.c -o build/kernel.o

build/kernel.elf: build/kernel.o linker.ld
	$(LD) -T linker.ld -o build/kernel.elf build/kernel.o

$(ISO): build/kernel.elf
	mkdir -p iso/boot
	cp build/kernel.elf iso/boot/kernel.elf
	grub-mkrescue -o $(ISO) iso

clean:
	rm -rf build