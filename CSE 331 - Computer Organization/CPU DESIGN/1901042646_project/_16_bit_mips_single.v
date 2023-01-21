`define DELAY 20
module _16_bit_mips_single(
	input [9:0] PC,
	input clk
);

wire [31:0] instruction;
wire [5:0] opcode, func;
wire [3:0] rs, rt, rd, shamt, writeReg;
wire [15:0] imm;
wire [9:0] addr;
wire beq, bne, memToReg, ALUSrc, regDst, memWrite, regWrite, memRead;
wire [2:0] AluOP;
wire [15:0] rs_content, rt_content;
wire [15:0] alu_operand;
wire [2:0] AluCtr;
wire [15:0] AluRes;
wire zero;
wire [15:0] memOut, write_data;

instruction_block I(PC, instruction);

and A0(opcode[5], instruction[31], 1);
and A1(opcode[4], instruction[30], 1);
and A2(opcode[3], instruction[29], 1);
and A3(opcode[2], instruction[28], 1);
and A4(opcode[1], instruction[27], 1);
and A5(opcode[0], instruction[26], 1);

and A6(rs[3], instruction[25], 1);
and A7(rs[2], instruction[24], 1);
and A8(rs[1], instruction[23], 1);
and A9(rs[0], instruction[22], 1);

and A10(rt[3], instruction[21], 1);
and A11(rt[2], instruction[20], 1);
and A12(rt[1], instruction[19], 1);
and A13(rt[0], instruction[18], 1);

and A14(rd[3], instruction[17], 1);
and A15(rd[2], instruction[16], 1);
and A16(rd[1], instruction[15], 1);
and A17(rd[0], instruction[14], 1);

and A18(shamt[3], instruction[13], 1);
and A19(shamt[2], instruction[12], 1);
and A20(shamt[1], instruction[11], 1);
and A21(shamt[0], instruction[10], 1);

and A22(func[5], instruction[9], 1);
and A23(func[4], instruction[8], 1);
and A24(func[3], instruction[7], 1);
and A25(func[2], instruction[6], 1);
and A26(func[1], instruction[5], 1);
and A27(func[0], instruction[4], 1);

and A28(imm[15], instruction[17], 1);
and A29(imm[14], instruction[16], 1);
and A30(imm[13], instruction[15], 1);
and A31(imm[12], instruction[14], 1);
and A32(imm[11], instruction[13], 1);
and A33(imm[10], instruction[12], 1);
and A34(imm[9], instruction[11], 1);
and A35(imm[8], instruction[10], 1);
and A36(imm[7], instruction[9], 1);
and A37(imm[6], instruction[8], 1);
and A38(imm[5], instruction[7], 1);
and A39(imm[4], instruction[6], 1);
and A40(imm[3], instruction[5], 1);
and A41(imm[2], instruction[4], 1);
and A42(imm[1], instruction[3], 1);
and A43(imm[0], instruction[2], 1);

and A44(addr[9], instruction[25], 1);
and A45(addr[8], instruction[24], 1);
and A46(addr[7], instruction[23], 1);
and A47(addr[6], instruction[22], 1);
and A48(addr[5], instruction[21], 1);
and A49(addr[4], instruction[20], 1);
and A50(addr[3], instruction[19], 1);
and A51(addr[2], instruction[18], 1);
and A52(addr[1], instruction[17], 1);
and A53(addr[0], instruction[16], 1);

control_unit CONT0(.opcode(opcode), .beq(beq), .bne(bne), .AluOP(AluOP), .memToReg(memToReg), .ALUSrc(ALUSrc), .regDst(regDst), .memWrite(memWrite), .regWrite(regWrite), .memRead(memRead));

_2x1_mux MUX0(rt[0], rd[0], regDst, writeReg[0]);
_2x1_mux MUX1(rt[1], rd[1], regDst, writeReg[1]);
_2x1_mux MUX2(rt[2], rd[2], regDst, writeReg[2]);
_2x1_mux MUX3(rt[3], rd[3], regDst, writeReg[3]);

register_block regist(.regWrite(regWrite), .reg_1(rs), .reg_2(rt), .write_addr(writeReg), .write_data(write_data), .data_1(rs_content), .data_2(rt_content));

_2x1_16_bit_mux MUXEx0(rt_content, imm, ALUSrc, alu_operand);

alu_control _aluc(AluOP, func, AluCtr);

alu16 _alu(.A(rs_content), .B(alu_operand), .shamt(shamt), .ALUop(AluCtr), .Result(AluRes), .Zero(zero));

memory_block mem(AluRes, rt_content, memWrite, memOut);

_2x1_16_bit_mux MUXEx1(AluRes, memOut, memToReg, write_data);


initial begin
#`DELAY;
$monitor("opcode: %6b, shamt: %4b, func: %6b, imm: %16b, rs: %4b, rt: %4b, rd: %4b, rs_content: %16b, rt_content: %16b, AluOP: %3b, AluCtr: %3b, beq: %1b, bne: %1b, memToReg: %1b, ALUsrc: %1b, regDst: %1b, memWrite: %1b, regWrite: %1b, memRead: %1b, ALUresult: %16b, writeData: %16b", opcode,shamt,func,imm,rs,rt,rd,rs_content,rt_content,AluOP,AluCtr,beq,bne,memToReg,ALUSrc,regDst,memWrite,regWrite,memRead,AluRes,write_data);
end

endmodule