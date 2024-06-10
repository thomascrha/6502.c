#include "../src/cpu.h"
#include "../src/bus.h"
#include "../src/constants.h"

#include <sys/time.h>
#include <stdlib.h>
#include <assert.h>


const uint16_t MEMORY_SIZE = 0xFFFF;
const uint16_t MEMORY_PRINT_WIDTH = 10000;


// simple macro to run a test and print the time it took
#define RUN_TEST(test) do { \
    struct timeval start, end; \
    gettimeofday(&start, NULL); \
    test(); \
    gettimeofday(&end, NULL); \
    long time_taken = (end.tv_usec - start.tv_usec); \
    printf("Test %s passed, time: %ld microseconds\n", #test, time_taken); \
} while(0)


struct Bus* setup_bus() {
    struct Bus* bus = calloc(0, sizeof(struct Bus));
    bus->memory = calloc(MEMORY_SIZE, sizeof(uint8_t));
    bus->size = MEMORY_SIZE;
    return bus;
}


struct CPU* setup_cpu() {
    struct Bus* bus = setup_bus();
    struct CPU* cpu = calloc(0, sizeof(struct CPU));
    cpu->bus = bus;
    return cpu;
}

void teardown_bus(struct Bus* bus) {
    free(bus->memory);
    free(bus);
}

void teardown_cpu(struct CPU* cpu) {
    teardown_bus(cpu->bus);
    free(cpu);
}


///////////////////////////////////////////////////////////////
////TESTS//////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////


void test_cpu_reset() {
    struct CPU* cpu = setup_cpu();
    CPU_reset(cpu);
    assert(cpu->program_counter == 0);
    assert(cpu->x_register == 0);
    assert(cpu->y_register == 0);
    assert(cpu->a_register == 0);
    assert(cpu->stack_pointer == 0);
    teardown_cpu(cpu);
}

void test_cpu_setup() {
    struct CPU* cpu = setup_cpu();
    assert(cpu->bus->size == MEMORY_SIZE);
    assert(cpu->bus->memory != NULL);
    teardown_cpu(cpu);
}

void test_cpu_setup_program_counter() {
    struct Bus* bus = setup_bus();

    struct CPU* cpu = calloc(0, sizeof(struct CPU));
    cpu->bus = bus;
    cpu->program_counter = 0x1234;

    assert(cpu->program_counter == 0x1234);

    CPU_reset(cpu);
    assert(cpu->program_counter == 0);
}

int main() {
    RUN_TEST(test_cpu_reset);
    RUN_TEST(test_cpu_setup);
    RUN_TEST(test_cpu_setup_program_counter);
    return 0;
}
