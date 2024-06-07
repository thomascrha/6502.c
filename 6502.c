#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

const uint16_t MEMORY_SIZE = 0xFFFF;
const uint16_t MEMORY_PRINT_WIDTH = 3000;

struct Bus {
    uint8_t* memory;
    uint16_t size;
};


struct CPU {
    uint16_t program_counter;
    uint8_t x_register;
    uint8_t y_register;
    uint8_t a_register;
    uint8_t stack_pointer;
    struct Bus* bus;
};

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

void Bus_print(struct Bus* bus) {
    // size of the individual memory members
    printf("Memory has %d bytes allocated\n", bus->size);
    printf("[");
    for (size_t i = 0; i < bus->size; i += MEMORY_PRINT_WIDTH) {
        printf("%d", bus->memory[i]);

        if (i + MEMORY_PRINT_WIDTH < bus->size) {
            printf(", ... ");
        }
    }
    printf("]\n");
}

void CPU_reset(struct CPU* cpu) {
    cpu->program_counter = 0;
    cpu->x_register = 0;
    cpu->y_register = 0;
    cpu->a_register = 0;
    cpu->stack_pointer = 0;
}

int main () {
    struct Bus bus;
    bus.memory = calloc(MEMORY_SIZE, sizeof(uint8_t));
    bus.size = MEMORY_SIZE;
    Bus_print(&bus);


    struct CPU cpu;
    cpu.bus = &bus;
    CPU_reset(&cpu);

    CPU_print(&cpu);


    return 0;
}
