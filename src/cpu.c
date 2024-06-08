#include <stdint.h>
#include <stdio.h>
#include "cpu.h"

char* hex_str_16(uint16_t value) {
    static char hex_string[7];
    sprintf(hex_string, "0x%04X", value);
    return hex_string;
}

char* hex_str_8(uint8_t value) {
    static char hex_string[5];
    sprintf(hex_string, "0x%02X", value);
    return hex_string;
}

void CPU_print(struct CPU* cpu) {
    printf(
        "CPU PC: %s X: %s Y: %s A: %s SP: %s\n", hex_str_16(cpu->program_counter),
                                                 hex_str_8(cpu->x_register),
                                                 hex_str_8(cpu->y_register),
                                                 hex_str_8(cpu->a_register),
                                                 hex_str_8(cpu->stack_pointer));
}

void CPU_reset(struct CPU* cpu) {
    cpu->program_counter = 0;
    cpu->x_register = 0;
    cpu->y_register = 0;
    cpu->a_register = 0;
    cpu->stack_pointer = 0;
}
