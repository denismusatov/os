#
# This script copies the necessary headers into sysroot
# directory, which will be used when compiling the kernel
#

set -e
. ./config.sh

mkdir -p "$SYSROOT"

for PROJECT in $SYSTEM_HEADER_PROJECTS; do
    echo 'project='$PROJECT
    (cd $PROJECT && DESTDIR="$SYSROOT" $MAKE install-headers)
done

