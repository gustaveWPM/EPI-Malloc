#!/bin/bash

cp main.c ..
cd ..
gcc *.c -I "include/" -Wall -Wextra -pedantic -O1
if ./a.out; then
    echo "PASSED"
else
    echo "FAILED: $?"
fi
rm main.c
rm a.out
cd tests/
