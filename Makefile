cc = gcc
CFLAGS = -ffreestanding -m64 -Wall -Wextra

all: build/kernel.o

build/kernel.o: kernel/kernel.c
	mkdir -p build
	$(cc) $(CFLAGS) -c kernel/kernel.c -o build/kernel.o

clean:
	rm -rf build
