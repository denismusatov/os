SYSTEM_HEADER_PROJECTS="libc libc++ kernel"
PROJECTS="libc libc++ kernel"

export MAKE=${MAKE:-make}
export HOST=${HOST:-$(./default-host.sh)}

export AR=${HOST}-ar
export AS=${HOST}-as
export CC=${HOST}-gcc
export CPPC=${HOST}-g++

export PREFIX="/usr"
export EXEC_PREFIX=$PREFIX
export BOOTDIR="/boot"
export LIBDIR=$EXEC_PREFIX/lib
export INCLUDEDIR=$PREFIX/include

export CFLAGS=''
export COMMON_FLAGS='-O2 -g'
export CPPFLAGS=''

# Configure the cross-compiler to use the desired system root.
export SYSROOT="$(pwd)/sysroot"
export CC="$CC --sysroot=$SYSROOT"
export CPPC="$CPPC --sysroot=$SYSROOT"

# Work around that the -elf gcc targets don't have a system include directory
# because it was configured with --without-headers rather than --with-sysroot.
if echo "$HOST" | grep -Eq -- '-elf($|-)'; then
    export CC="$CC -isystem=$INCLUDEDIR"
    export CPPC="$CPPC -isystem=$INCLUDEDIR -isystem=$INCLUDEDIR/c++"
fi

