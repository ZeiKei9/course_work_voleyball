#!/bin/bash
cd "$(dirname "$0")"
if [ ! -f volleyball-sim ]; then
    make || exit 1
fi
./volleyball-sim
make clean
