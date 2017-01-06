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

if [ -d bin ]; then
    true
else
    mkdir bin
fi

printf "Assembling bootstrap..."
i686-elf-as src/boot/boot.s -o build/boot.o && echo "success"

printf "Assembling kernel..."
i686-elf-g++ -std=c++14 -c src/kernel/kernel.cpp -o build/kernel.o -ffreestanding -O2 \
    -Wall -Wextra -fno-exceptions -fno-rtti && echo "success"

i686-elf-g++ -std=c++14 -c src/kernel/vga/vga.cpp -o build/vga.o -ffreestanding -O2 \
    -Wall -Wextra -fno-exceptions -fno-rtti

printf "Linking final binary... "
i686-elf-gcc -T src/linker/linker.ld -o bin/os.bin -ffreestanding -O2 \
    -nostdlib build/boot.o build/kernel.o build/vga.o -lgcc && echo "success"

cp bin/os.bin isodir/boot/

rm -r build
rm bin/*.bin

printf "Producing iso image..."
grub-mkrescue -o iso/os.iso isodir  2> /dev/null && echo "success"

