#include "emu.h"
#define OPCODE_MASK     ((0x1 << 7) - 1) 
#define RD_OFFSET       7
#define RD_MASK         ((0x1 << 5) - 1) << RD_OFFSET
#define FUNCT3_OFFSET   12
#define FUNCT3_MASK     ((0x1 << 3) - 1) << FUNCT3_OFFSET
#define RS1_OFFSET      15
#define RS1_MASK        ((0x1 << 5) - 1) << RS1_OFFSET

#define RS2_OFFSET      20
#define RS2_MASK        ((0x1 << 5) - 1) << RS2_OFFSET
#define FUNCT7_OFFSET   24
#define FUNCT7_MASK     ((0x1 << 7) - 1) << FUNCT7_OFFSET

#define IMM_OFFSET      20
#define IMM_MASK        ((0x1 << 12) - 1) << IMM_OFFSET

/**
 *
    Inst    Name                    FMT     Opcode      funct3  funct7  Description        
    add     ADD                     R       0110011     0x0     0x00    rd = rs1 + rs2      
    sub     SUB                     R       0110011     0x0     0x20    rd = rs1 - rs2
    xor     XOR                     R       0110011     0x4     0x00    rd = rs1 ˆ rs2
    or      OR                      R       0110011     0x6     0x00    rd = rs1 | rs2
    and     AND                     R       0110011     0x7     0x00    rd = rs1 & rs2
    sll     Shift Left Logical      R       0110011     0x1     0x00    rd = rs1 << rs2
    srl     Shift Right Logical     R       0110011     0x5     0x00    rd = rs1 >> rs2
    sra     Shift Right Arith*      R       0110011     0x5     0x20    rd = rs1 >> rs2
    slt     Set Less Than           R       0110011     0x2     0x00    rd = (rs1 < rs2)?1:0
    sltu    Set Less Than (U)       R       0110011     0x3     0x00    rd = (rs1 < rs2)?1:0
*/

enum Format opcode_to_format(uint8_t opcode) {
    switch(opcode) {
        case OP:    return R;
        case OP_IMM: return I;
        default: return UNKNOWN_FORMAT;
    }
}


struct DecodeResult decode_r(uint32_t instruction, uint32_t value_rs1, uint32_t value_rs2) {
    struct DecodeResult res;
    uint8_t funct3 = (instruction & FUNCT3_MASK) >> FUNCT3_OFFSET;
    uint8_t funct7 = (instruction & FUNCT7_MASK) >> FUNCT7_OFFSET;
    res.funct = (funct7 << 3) | funct3;
    res.op1 = value_rs1;
    res.op2 = value_rs2;
    res.rd = (instruction & RD_MASK) >> RD_OFFSET;
    res.rs1 = (instruction & RS1_MASK) >> RS1_OFFSET;
    res.rs2 = (instruction & RS2_MASK) >> RS2_OFFSET;
    return res;
}

struct DecodeResult decode_i(uint32_t instruction, uint32_t value_rs1, uint32_t value_rs2) {
    struct DecodeResult res;
    uint8_t funct3 = (instruction & FUNCT3_MASK) >> FUNCT3_OFFSET;
    uint16_t imm = (instruction & IMM_MASK) >> IMM_OFFSET;
    struct { int32_t imm : 12; } _signed;
    _signed.imm = imm;
    res.funct = (0x0 << 3) | funct3;
    res.op1 = value_rs1;
    res.op2 = _signed.imm;
    res.rd = (instruction & RD_MASK) >> RD_OFFSET;
    res.rs1 = (instruction & RS1_MASK) >> RS1_OFFSET;
    res.rs2 = 0;
    return res;
}

struct DecodeResult decode(uint32_t instruction, uint32_t value_rs1, uint32_t value_rs2) {
    struct DecodeResult res;
    uint8_t opcode = instruction & OPCODE_MASK;
    enum Format fmt = opcode_to_format(opcode);

    switch (fmt) {
    case R:
        res = decode_r(instruction, value_rs1, value_rs2);
        break;
    case I:
        res = decode_i(instruction, value_rs1, value_rs2);
        break;
    default:
        break;
    }

    return res;
}