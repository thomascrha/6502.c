#ifndef BUS_H
#define BUS_H

#include <stdint.h>

const uint16_t MEMORY_SIZE = 0xFFFF;
const uint16_t MEMORY_PRINT_WIDTH = 3000;

struct Bus {
    uint8_t* memory;
    uint16_t size;
};

void Bus_print(struct Bus* bus);

#endif // BUS_H
