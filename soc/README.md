### Design
- Use RISC-V RV32I
- 32-bits address bus
- 32-bits register width
- 40 Instructions or 38 Instructions (+ 6 privileged instruction)

### Instructions
ADDI
STLI
STLU
ANDI
ORI
XORI
SLLI
SRLI
SRAI
LUI
AUIPC
ADD
SLT
SLTU
AND
OR
XOR
SLL
SRL
SUB
SRA
NOP
JAL
JALI
BEQ
BNE
BLT
BLTU
BGE
BGEU
LW
LH
LHU
LB
LBU
SW
SH
SB
FENCE
SYSTEM
HINT

### Registers
- x0: hardwired with all bits set to 0
- x1-x31: general purpose register
- pc: program counter