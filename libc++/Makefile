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
CPPFLAGS:=$(CPPFLAGS) -D__is_libcpp -Iinclude
LIBK_CFLAGS:=$(CFLAGS)
LIBK_CPPFLAGS:=$(CPPFLAGS) -D__is_libkpp

CFLAGS:=$(CFLAGS) $(ARCH_CFLAGS)
COMMON_FLAGS:=$(COMMON_FLAGS) $(ARCH_COMMON_FLAGS)
CPPFLAGS:=$(CPPFLAGS) $(ARCH_CPPFLAGS)
LIBKPP_CFLAGS:=$(LIBK_CFLAGS) $(KERNEL_ARCH_CFLAGS)
LIBKPP_COMMON_FLAGS:=$(LIBK_COMMON_FLAGS) $(KERNEL_ARCH_COMMON_FLAGS)
LIBKPP_CPPFLAGS:=$(LIBK_CPPFLAGS) $(KERNEL_ARCH_CPPFLAGS)

FREEOBJS=\
		$(ARCH_FREEOBJS) \

HOSTEDOBJS=\
		$(ARCH_HOSTEDOBJS) \

OBJS=\
	$(FREEOBJS) \
	$(HOSTEDOBJS) \

.PHONY: all clean install install-headers

all: install

clean:
	    rm -f $(BINARIES) *.a
		rm -f $(OBJS) $(LIBK_OBJS) *.o */*.o */*/*.o
		rm -f $(OBJS:.o=.d) $(LIBK_OBJS:.o=.d) *.d */*.d */*/*.d

install: install-headers

install-headers:
	    mkdir -p $(DESTDIR)$(INCLUDEDIR)
		mkdir -p $(DESTDIR)$(INCLUDEDIR)/c++
		cp -R --preserve=timestamps include/. $(DESTDIR)$(INCLUDEDIR)/c++/.

