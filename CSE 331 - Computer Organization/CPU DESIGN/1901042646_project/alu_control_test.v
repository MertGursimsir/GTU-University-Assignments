`define DELAY 20
module alu_control_test();
reg [2:0] AluOP;
reg [5:0] Func;
wire [2:0] AluCtr;

alu_control T(.AluOP(AluOP), .Func(Func), .AluCtr(AluCtr));

initial begin
//ADD
AluOP = 3'b010; Func = 6'b100000;
#`DELAY;

//SUB
AluOP = 3'b010; Func = 6'b100010;
#`DELAY;

//SRL
AluOP = 3'b010; Func = 6'b000010;
#`DELAY;

//SLL
AluOP = 3'b010; Func = 6'b000000;
#`DELAY;

//AND
AluOP = 3'b010; Func = 6'b100100;
#`DELAY;

//OR
AluOP = 3'b010; Func = 6'b100101;
#`DELAY;

//SLT
AluOP = 3'b010; Func = 6'b101010;
#`DELAY;

//LW
AluOP = 3'b000; Func = 6'bxxxxxx;
#`DELAY;

//SW
AluOP = 3'b000;
#`DELAY;

//BEQ
AluOP = 3'b001;
#`DELAY;

//BNE
AluOP = 3'b001;
#`DELAY;

//SLTI
AluOP = 3'b110;
#`DELAY;

//ANDI
AluOP = 3'b100;
#`DELAY;

//ORI
AluOP = 3'b101;
#`DELAY;

//ADDI
AluOP = 3'b000;
#`DELAY;
end

initial
begin
$monitor("ALU CONTROL Results: ALUOP = %3b, FUNCTION FIELD = %6b, ALUCTR = %3b", AluOP, Func, AluCtr);
end

endmodule