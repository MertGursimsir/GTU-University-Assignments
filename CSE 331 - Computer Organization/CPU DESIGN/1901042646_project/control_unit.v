module control_unit(
input [5:0] opcode,

output beq,
output bne,

output [2:0] AluOP,

output memToReg,
output ALUSrc,
output regDst,

output memWrite,
output regWrite,
output memRead
);

wire r_type, jr, j, jal, lw, sw, slti, andi, ori, addi;
wire op_not_0, op_not_1, op_not_2, op_not_3, op_not_4, op_not_5; 

not N0(op_not_0,opcode[0]);
not N1(op_not_1,opcode[1]);
not N2(op_not_2,opcode[2]);
not N3(op_not_3,opcode[3]);
not N4(op_not_4,opcode[4]);
not N5(op_not_5,opcode[5]);

and A0(r_type, op_not_0, op_not_1, op_not_2, op_not_3, op_not_4, op_not_5);
and A1(j, op_not_0, opcode[1], op_not_2, op_not_3, op_not_4, op_not_5);
and A2(jal, opcode[0], opcode[1], op_not_2, op_not_3, op_not_4, op_not_5);
and A3(lw, opcode[0], opcode[1], op_not_2, op_not_3, op_not_4, opcode[5]);
and A4(sw, opcode[0], opcode[1], op_not_2, opcode[3], op_not_4, opcode[5]);
and A5(beq, op_not_0, op_not_1, opcode[2], op_not_3, op_not_4, op_not_5);
and A6(bne, opcode[0], op_not_1, opcode[2], op_not_3, op_not_4, op_not_5);
and A7(slti, op_not_0, opcode[1], op_not_2, opcode[3], op_not_4, op_not_5);
and A8(andi, op_not_0, op_not_1, opcode[2], opcode[3], op_not_4, op_not_5);
and A9(ori, opcode[0], op_not_1, opcode[2], opcode[3], op_not_4, op_not_5);
and A10(addi, op_not_0, op_not_1, op_not_2, opcode[3], op_not_4, op_not_5);

or O0(memToReg, lw, 0);
or O1(ALUSrc, lw, sw, slti, andi, ori, addi);
or O2(regDst, r_type, 0);
or O3(memWrite, sw, 0);
or O4(regWrite, r_type, lw, slti, andi, ori, addi);
or O5(memRead, lw, 0);
or O6(AluOP[2], slti, andi, ori);
or O7(AluOP[1], r_type, slti);
or O8(AluOP[0], beq, bne, ori);

endmodule