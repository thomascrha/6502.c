#include <stdio.h>
#include <stdint.h>

struct CPU {
    int16_t program_counter;
    int8_t x_register;
    int8_t y_register;
    int8_t a_register;
    int8_t stack_pointer;
};


int main () {
    struct CPU cpu = {10, 0, 0, 0, 0};
    printf("CPU PC %d", cpu.program_counter);
    return 0;
}
