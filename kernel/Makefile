DEFAULT_HOST!=../default-host.sh
HOST?=DEFAULT_HOST
HOSTARCH!=../target-triplet-to-arch.sh $(HOST)

CFLAGS?=
COMMON_FLAGS?=-O2 -g
CPPFLAGS?=-std=c++11
LDFLAGS?=
LIBS?=

DESTDIR?=
PREFIX?=/usr/local
EXEC_PREFIX?=$(PREFIX)
BOOTDIR?=$(EXEC_PREFIX)/boot
INCLUDEDIR?=$(PREFIX)/include

CFLAGS:=$(CFLAGS) -ffreestanding -Wall -Wextra
CPPFLAGS:=$(CPPFLAGS) -D__is_kernel -Iinclude
LDFLAGS:=$(LDFLAGS)
LIBS:=$(LIBS) -nostdlib -lk -lgcc

ARCHDIR=arch/$(HOSTARCH)

include $(ARCHDIR)/make.config

CFLAGS:=$(CFLAGS) $(KERNEL_ARCH_CFLAGS)
COMMON_FLAGS:=$(COMMON_FLAGS)
CPPFLAGS:=$(LDFLAGS) $(KERNEL_ARCH_LDFLAGS)
LIBS:=$(LIBS) $(KERNEL_ARCH_LIBS)

KERNEL_OBJS=\
			$(KERNEL_ARCH_OBJS) \
			kernel\kernel.o \

OBJS=\
	 $(ARCHDIR)/crti.o \
	 $(ARCHDIR)/crtbegin.o \
	 $(KERNEL_OBJS) \
	 $(ARCHDIR)/crtend.o \
	 $(ARCHDIR)/crtn.o \

LINK_LIST=\
		  $(LDFLAGS) \
		  $(ARCHDIR)/crti.o \
		  $(ARCHDIR)/crtbegin.o \
		  $(KERNEL_OBJS) \
		  $(LIBS) \
		  $(ARCHDIR)/crtend.o \
		  $(ARCHDIR)/crtn.o \

.PHONY: all clean install install-headers install-kernel
.SUFFIXES: .o .c .cpp .S

all: os.kernel

os.kernel: $(OBJS) $(ARCHDIR)/linker.ld
	$(CC) -T $(ARCHDIR)/linker.ld -o $@ $(COMMON_FLAGS) $(CFLAGS) $(LINK_LIST)
	grub-file --is-x86-multiboot os.kernel

$(ARCHDIR)/crtbegin.o $(ARCHDIR)/crtend.o:
	OBJ=`$(CC) $(COMMON_FLAGS) $(CFLAGS) $(LDFLAGS) -print-file-name=$(@F)` &&\
	   	cp "$$OBJ" $@

.c.o:
	$(CC) -MD -c $< -o $@ -std=gnull $(COMMON_FLAGS) $(CFLAGS)

.cpp.o:
	$(CPPC) -MD -c $< -o $@ $(COMMON_FLAGS) $(CPPFLAGS)

.S.o:
	$(CC) -MD -c $< -o $@ $(CFLAGS) $(CPPFLAGS) $(COMMON_FLAGS)

clean:
	rm -f os.kernel
	rm -f $(OBJS) *.o */*.o */*/*.o
	rm -f $(OBJS:.o=.d) *.d */*.d */*/*.d

install: install-headers install-kernel

install-headers:
	mkdir -p $(DESTDIR)$(INCLUDEDIR)
	cp -R --preserve=timestamps include/. $(DESTDIR)$(INCLUDEDIR)/.

install-kernel:
	mkdir -p $(DESTDIR)$(BOOTDIR)
	cp os.kernel $(DESTDIR)$(BOOTDIR)

-include $(OBJS:.o=.d)

