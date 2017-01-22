
SYSROOT:="sysroot"

CC:=i686-elf-gcc
AS:=i686-elf-as
CFLAGS:=-std=c11 
CPPFLAGS:=
LDFLAGS:=



make:
	sh assemble_kernel.sh


run:
	sh qemu.sh

