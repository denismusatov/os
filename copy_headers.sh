#
# This script copies the necessary headers into sysroot
# directory, which will be used when compiling the kernel
#

if [ -z "${SYSROOT}" ]; then
    export SYSROOT="sysroot"
fi

export USR="$SYSROOT/usr"
export INCLUDE="$USR/include"
export INCLUDE_CPP="$INCLUDE/c++"

if ! [ -d $SYSROOT ]; then
    mkdir $SYSROOT
    mkdir $USR
    mkdir $INCLUDE
    mkdir $INCLUDE_CPP
    mkdir $USR/lib
fi


cp klibc/include/* $INCLUDE

cp klibc++/* $INCLUDE/c++

