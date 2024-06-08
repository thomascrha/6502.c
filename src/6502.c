#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "cpu.h"
#include "bus.h"

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
