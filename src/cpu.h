#ifndef CPU_H
#define CPU_H


#include <stdio.h>
#include <stdint.h>
#include "bus.h"

struct CPU {
    uint16_t program_counter;
    uint8_t x_register;
    uint8_t y_register;
    uint8_t a_register;
    uint8_t stack_pointer;
    struct Bus* bus;
};

char* hex_str_16(uint16_t value);
char* hex_str_8(uint8_t value);
void CPU_print(struct CPU* cpu);
void CPU_reset(struct CPU* cpu);

#endif  // CPU_H
