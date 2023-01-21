`define DELAY 20
module alu32_test();
reg [31:0] A, B;
reg [2:0] ALUop;
wire [31:0] Result;

alu32 T(.A(A), .B(B), .ALUop(ALUop), .Result(Result));

initial begin
//ADD --> 000
A = 32'd16; B = 32'd34; ALUop = 3'b000;
#`DELAY;
A = 32'd100; B = 32'd100; ALUop = 3'b000;
#`DELAY;

//SUB --> 001
A = 32'd100; B = 32'd47; ALUop = 3'b001;
#`DELAY;
A = 32'd105; B = 32'd3; ALUop = 3'b001;
#`DELAY;

//XOR --> 011
A = 32'hFFFFFFFF; B = 32'h00000000; ALUop = 3'b011;
#`DELAY;
A = 32'hABDF1234; B = 32'h01259ECF; ALUop = 3'b011;
#`DELAY;

//AND --> 100
A = 32'hFFFFFFFF; B = 32'h00000000; ALUop = 3'b100;
#`DELAY;
A = 32'hABDF1234; B = 32'h01259ECF; ALUop = 3'b100;
#`DELAY;

//OR --> 101
A = 32'hFFFFFFFF; B = 32'h00000000; ALUop = 3'b101;
#`DELAY;
A = 32'hABDF1234; B = 32'h01259ECF; ALUop = 3'b101;
#`DELAY;

//SLT --> 110
A = 32'd100; B = 32'd47; ALUop = 3'b110;
#`DELAY;
A = 32'd100; B = 32'd147; ALUop = 3'b110;
#`DELAY;

//NOR --> 111
A = 32'hFFFFFFFF; B = 32'h00000000; ALUop = 3'b111;
#`DELAY;
A = 32'hABDF1234; B = 32'h01259ECF; ALUop = 3'b111;
#`DELAY;
end

initial
begin
$monitor("ALU Results: Result = %d, A = %d, B = %d, ALUop = %3b", Result, A, B, ALUop);
end
 

endmodule