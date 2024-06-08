#include "bus.h"
#include <stdio.h>

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

