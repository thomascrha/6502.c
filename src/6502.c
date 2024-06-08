#include <stdint.h>
#include <stdlib.h>

#include "cpu.h"
#include "bus.h"

#include "constants.h"

const uint16_t MEMORY_SIZE = 0xFFFF;
const uint16_t MEMORY_PRINT_WIDTH = 10000;

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
