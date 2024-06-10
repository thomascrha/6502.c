#!/bin/make

help:
	@echo "Usage: make [target]"
	@echo "Targets:"
	@awk 'BEGIN {FS = ":.*?## "} /^[a-zA-Z_-]+:.*?## / {printf "  %-20s %s\n", $$1, $$2}' $(MAKEFILE_LIST)
.PHONY: help

default: help

clean: ## Clean up the build
	rm -f 6502
	rm -f test_cpu
.PHONY: clean

build: clean ## Build the 6502 emulator
	@echo "Building 6502 emulator..."
	gcc -Wall -Werror -Wextra -pedantic -std=c99 -o 6502 src/bus.c src/cpu.c src/6502.c
	./6502
.PHONY: all

test_cpu: clean ## Run the tests for the CPU
	@echo "Running tests..."
	gcc -Wall -Werror -Wextra -pedantic -std=c99 -o test_cpu tests/test_cpu.c src/cpu.c src/bus.c
	./test_cpu
.PHONY: test_cpu
