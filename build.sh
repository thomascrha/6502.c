#!/bin/sh

set -xe

gcc -Wall -Werror -Wextra -pedantic -std=c99 -o 6502 src/bus.c src/cpu.c src/6502.c

