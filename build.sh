#!/bin/sh
set -e
. ./headers.sh

for PROJECT in $PROJECTS; do
    echo "make install $PROJECT"
    (cd $PROJECT && DESTDIR="$SYSROOT" $MAKE install)
done

