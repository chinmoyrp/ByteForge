#bankdef mybank {
  #outp 0x0
  #bits 32
}

#bank mybank

#subruledef register {
    r0   => 0x00
    r1   => 0x01
    r2   => 0x02
    r3   => 0x03
    r4   => 0x04
    r5   => 0x05
    r6   => 0x06
    r7   => 0x07
    r8   => 0x08
    r9   => 0x09
    r10  => 0x0A
    r11  => 0x0B
    r12  => 0x0C
    r13  => 0x0D
    r14  => 0x0E
    r15  => 0x0F
    r16  => 0x10
    r17  => 0x11
    r18  => 0x12
    r19  => 0x13
    r20  => 0x14
    r21  => 0x15
    r22  => 0x16
    r23  => 0x17
    r24  => 0x18
    r25  => 0x19
    r26  => 0x1A
    r27  => 0x1B
    r28  => 0x1C
    r29  => 0x1D
    r30  => 0x1E
    r31  => 0x1F
}

#subruledef opcode {
    OP      => 0b0110011
    OP_IMM  => 0b0010011
}

#ruledef {
    add {rd:register}, {rs1:register}, {rs2:register}  =>   0x00`7   @  rs2`5   @   rs1`5   @   0x0`3   @   rd`5    @   0b0110011
    addi {rd:register}, {rs1:register}, {imm}          =>   imm`12   @              rs1`5   @   0x0`3   @   rd`5    @   0b0010011
}

