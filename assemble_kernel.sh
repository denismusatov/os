#!/bin/sh

if [ -s iso/*.iso ]; then
    rm iso/*.iso
fi

if [ -d build ]; then
    if [ -s build/*.o ]; then
        # Clean object files
        rm build/*.o
        rm bin/*.bin
    fi
else
    mkdir build
fi

if ! [ -d bin ]; then
    mkdir bin
fi

export SYSROOT="sysroot"
export CPPFLAGS="-std=c++14 -fno-rtti -fno-exceptions "
export COMMON_FLAGS="-g -ffreestanding -O2 -Wall -Wextra"
export CFLAGS="-std=c11 $COMMON_FLAGS"

. ./copy_headers.sh

printf "Assembling bootstrap..."
i686-elf-as kernel/boot/boot.s -o build/boot.o && echo "success"

# Assemble libc
i686-elf-gcc -c klibc/src/string.c -o build/string.o $CFLAGS
i686-elf-gcc -c klibc/src/kprintf.c -o build/kprintf.o $CFLAGS

# Assemble inline assembly functions
make -C asm

printf "Assembling kernel..."
i686-elf-g++ $CPPFLAGS -c kernel/src/kernel.cpp -o build/kernel.o $COMMON_FLAGS\
    && echo "success"
i686-elf-gcc $CFLAGS -c kernel/src/keyboard.c -o build/keyboard.o $COMMON_FLAGS\
    && echo "success"

i686-elf-g++ $CPPFLAGS -c kernel/src/vga/vga.cpp -o build/vga.o $COMMON_FLAGS


printf "Linking final binary... "
i686-elf-gcc -T link/linker.ld -o bin/os.bin $COMMON_FLAGS \
    -nostdlib build/boot.o build/kernel.o build/keyboard.o build/vga.o build/string.o \
    build/kprintf.o build/io.o build/interrupts.o -lgcc && echo "success"

cp bin/os.bin isodir/boot/

rm -r build
rm bin/*.bin

printf "Producing an iso image..."

if [ -d iso ]; then
    true
else
    mkdir iso
fi

grub-mkrescue -o iso/os.iso isodir  2> /dev/null && echo "success"

