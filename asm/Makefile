
CC:=i686-elf-gcc
CFLAGS:=-std=c11
COMMON_FLAGS:=-g -ffreestanding -O2 -Wall -Wextra

make:
	$(CC) -c $(CFALGS) $(COMMON_FLAGS) io.c -o ../build/io.o
	$(CC) -c $(CFALGS) $(COMMON_FLAGS) interrupts.c -o ../build/interrupts.o
	$(CC) -c $(CFALGS) $(COMMON_FLAGS) cpu.c -o ../build/cpu.o

clean:
	rm ../build/io.o
	rm ../build/interrupts.o
	rm ../build/cpu.o
