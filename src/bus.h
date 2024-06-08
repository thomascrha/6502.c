#ifndef BUS_H
#define BUS_H

#include <stdint.h>


struct Bus {
    uint8_t* memory;
    uint16_t size;
};

void Bus_print(struct Bus* bus);

#endif // BUS_H
