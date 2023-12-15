#include <stdint.h>
#define FMTLEN 6  // total instruction formats
#define OPLEN 10  // total opcodes in RV32I
#define XLEN  32 // total registers


enum Register {
    R1  = 0x01,
    R2  = 0x02,
    R3  = 0x03,
    R4  = 0x04,
    R5  = 0x05,
    R6  = 0x06,
    R7  = 0x07,
    R8  = 0x08,
    R9  = 0x09,
    R10  = 0x0A,
    R11  = 0x0B,
    R12  = 0x0C,
    R13  = 0x0D,
    R14  = 0x0E,
    R15  = 0x0F,
    R16  = 0x10,
    R17  = 0x11,
    R18  = 0x12,
    R19  = 0x13,
    R20  = 0x14,
    R21  = 0x15,
    R22  = 0x16,
    R23  = 0x17,
    R24  = 0x18,
    R25  = 0x19,
    R26  = 0x1A,
    R27  = 0x1B,
    R28  = 0x1C,
    R29  = 0x1D,
    R30  = 0x1E,
    R31  = 0x1F
};

enum Format {
  UNKNOWN_FORMAT = 0,
  R = 1,
  I,
  S,
  B,
  U,
  J
};

enum Opcode {
    OP = 0b0110011,
    OP_IMM = 0b0010011,
};

struct DecodeResult {
    uint8_t rs1    : 5;
    uint8_t rs2    : 5;
    uint8_t rd     : 5;
    uint32_t op1   : 32;
    uint32_t op2   : 32;
    uint16_t funct : 10;
};


struct DecodeResult decode(uint32_t instruction, uint32_t value_rs1, uint32_t value_rs2);