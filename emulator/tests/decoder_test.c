#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include "../emu.h"

#define RD_OFFSET       7
#define RD_MASK         ((0x1 << 5) - 1) << RD_OFFSET
#define IMM_OFFSET      20
#define IMM_MASK        ((0x1 << 12) - 1) << IMM_OFFSET

void bintostr(int32_t data, size_t size) {
    
    for (int i=0; i<32; i++) {
        if (data & (0x1 << i)) {
            printf("1");
        } else {
            printf("0");
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s [binary] [assembly]", argv[0]);
        return 1;
    }

    uint32_t instruction = 0;
    for (uint8_t i=0; i<32; i++) {
        instruction = instruction | ((argv[1][i] - '0') << (31-i));
    }
    struct DecodeResult res = decode(instruction, 0, 0);
    printf("# %s\n", argv[2]);
    printf("0b%s 0x%X 0x%X 0x%X 0x%X 0x%X 0x%X\n", argv[1], res.rd, res.rs1, res.rs2, res.op1, res.op2, res.funct);

    return 0;
}