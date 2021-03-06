#!/bin/bash

. ./scripts/env.sh

cd $DEPS

echo "Downloading $GMP from $GMP_URL"

curl -C - --fail --output $GMP_FILE $GMP_URL || wget --continue $GMP_URL -O $GMP_FILE

if [ $? != 0 ] ; then
    echo "Unable to download gmp library"
    exit 1
fi

rm -rf $GMP_DEPS

tar jxf $GMP_FILE

mv $GMP $GMP_DEPS

cd $GMP_DEPS

if [ "$PLATFORM" != "SunOS" ] ; then
  if [ -e "$BUILD/lib/libgmp.la" ]; then
      echo "Gmp has already been built"
      exit 0
  fi

  ./configure --prefix=$BUILD --disable-assembly --disable-shared CFLAGS="-fPIC"

  make

  if [ $? != 0 ] ; then
      echo "Unable to build gmp library"
      exit 1
  fi

  make install
fi


#ln -s `g++ -print-file-name=libgcc.a`
#ln -s `g++ -print-file-name=libstdc++.a`
# CFLAGS="-pthread -lrt -ldl -static -static-libgcc -static-libstdc++ -fPIC'  LDFLAGS="-L. -lgcc -lstdc++"
