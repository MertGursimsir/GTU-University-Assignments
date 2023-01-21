`define DELAY 20
module control_test();
reg [5:0] opcode;
wire beq, bne, memToReg, ALUSrc, regDst, memWrite, regWrite, memRead;
wire [2:0] AluOP;

control_unit T(.opcode(opcode), .beq(beq), .bne(bne), .AluOP(AluOP), .memToReg(memToReg),
				.ALUSrc(ALUSrc), .regDst(regDst), .memWrite(memWrite), .regWrite(regWrite), .memRead(memRead));

initial begin
//R TYPE
opcode = 6'b000000;
#`DELAY;

//J
opcode = 6'b000010;
#`DELAY;

//JAL
opcode = 6'b000011;
#`DELAY;

//LW
opcode = 6'b100011;
#`DELAY;

//SW
opcode = 6'b101011;
#`DELAY;

//BEQ
opcode = 6'b000100;
#`DELAY;

//BNE
opcode = 6'b000101;
#`DELAY;

//SLTI
opcode = 6'b001010;
#`DELAY;

//ANDI
opcode = 6'b001100;
#`DELAY;

//ORI
opcode = 6'b001101;
#`DELAY;

//ADDI
opcode = 6'b001000;
#`DELAY;
end

initial
begin
$monitor("CONTROL Results: OPCODE = %6b, beq = %1b, bne = %1b, AluOP = %3b, memToReg = %1b, ALUSrc = %1b, regDst = %1b, memWrite = %1b, regWrite = %1b, memRead = %1b", opcode, beq, bne, AluOP, memToReg, ALUSrc, regDst, memWrite, regWrite, memRead);
end

endmodule