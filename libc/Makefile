DEFAULT_HOST!=../default-host.sh
HOST?=DEFAULT_HOST
HOSTARCH!=../target-triplet-to-arch.sh $(HOST)

CFLAGS?=
COMMON_FLAGS?=-O2 -g
CPPFLAGS?=
LDFLAGS?=
LIBS?=

DESTDIR?=
PREFIX?=/usr/local
EXEC_PREFIX?=$(PREFIX)
INCLUDEDIR?=$(PREFIX)/include
LIBDIR?=$(EXEC_PREFIX)/lib

CFLAGS:=$(CFLAGS) -ffreestanding -Wall -Wextra
COMMON_FLAGS:=$(COMMON_FLAGS)
CPPFLAGS:=$(CPPFLAGS) -D__is_libc -Iinclude
LIBK_CFLAGS:=$(CFLAGS)
LIBK_CPPFLAGS:=$(CPPFLAGS) -D__is_libk

ARCHDIR=arch/$(HOSTARCH)

include $(ARCHDIR)/make.config
 
CFLAGS:=$(CFLAGS) $(ARCH_CFLAGS)
COMMON_FLAGS:=$(COMMON_FLAGS) $(ARCH_COMMON_FLAGS)
CPPFLAGS:=$(CPPFLAGS) $(ARCH_CPPFLAGS)
LIBK_CFLAGS:=$(LIBK_CFLAGS) $(KERNEL_ARCH_CFLAGS)
LIBK_COMMON_FLAGS:=$(LIBK_COMMON_FLAGS) $(KERNEL_ARCH_COMMON_FLAGS)
LIBK_CPPFLAGS:=$(LIBK_CPPFLAGS) $(KERNEL_ARCH_CPPFLAGS)
 
FREEOBJS=\
		$(ARCH_FREEOBJS) \
		../asm/cpu.o \
		../asm/io.o \
		../asm/interrupts.o \
		src/stdio/printf.o \
		src/stdlib/abort.o \
		src/string/memcmp.o \
		src/string/memcpy.o \
		src/string/memmove.o \
		src/string/memset.o \
		src/string/strlen.o \

HOSTEDOBJS=\
		$(ARCH_HOSTEDOBJS) \
			 
OBJS=\
	$(FREEOBJS) \
	$(HOSTEDOBJS) \
	   
LIBK_OBJS=$(FREEOBJS:.o=.libk.o)
  
#BINARIES=libc.a libk.a # Not ready for libc yet.
BINARIES=libk.a

.PHONY: all clean install install-headers install-libs
.SUFFIXES: .o .libk.o .c .S

all: $(BINARIES)

libc.a: $(OBJS)
	    $(AR) rcs $@ $(OBJS)

libk.a: $(LIBK_OBJS)
	    $(AR) rcs $@ $(LIBK_OBJS)

.c.o:
	    $(CC) -MD -c $< -o $@ -std=gnu11 $(CFLAGS) $(COMMON_FLAGS) $(CPPFLAGS)

.c.S:
	    $(CC) -MD -c $< -o $@ $(CFLAGS) $(CPPFLAGS) $(COMMON_FLAGS)

.c.libk.o:
	    $(CC) -MD -c $< -o $@ -std=gnu11 $(LIBK_CFLAGS) $(LIBK_COMMON_FLAGS) $(LIBK_CPPFLAGS)

.S.libk.o:
	    $(CC) -MD -c $< -o $@ $(LIBK_CFLAGS) $(LIBK_COMMON_FLAGS) $(LIBK_CPPFLAGS)

clean:
	    rm -f $(BINARIES) *.a
		rm -f $(OBJS) $(LIBK_OBJS) *.o */*.o */*/*.o
		rm -f $(OBJS:.o=.d) $(LIBK_OBJS:.o=.d) *.d */*.d */*/*.d

install: install-headers install-libs

install-headers:
	    mkdir -p $(DESTDIR)$(INCLUDEDIR)
		cp -R --preserve=timestamps include/. $(DESTDIR)$(INCLUDEDIR)/.

install-libs: $(BINARIES)
	    mkdir -p $(DESTDIR)$(LIBDIR)
		cp $(BINARIES) $(DESTDIR)$(LIBDIR)

-include $(OBJS:.o=.d)
-include $(LIBK_OBJS:.o=.d)

