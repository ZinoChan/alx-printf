#!/bin/bash

if gcc -Wall -Wextra -Werror -pedantic -std=gnu89 -Wno-format *.c tests/main.c -o printf; then
    echo "Your output: "
    ./printf
else
    echo "Compilation failed"
fi

