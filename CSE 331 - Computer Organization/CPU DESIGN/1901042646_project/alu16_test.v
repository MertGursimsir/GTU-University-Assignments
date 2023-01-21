`define DELAY 20
module alu16_test();
reg [15:0] A, B;
reg [3:0] shamt;
reg [2:0] ALUop;
wire [15:0] Result;
wire Zero;

alu16 T(.A(A), .B(B), .ALUop(ALUop), .Result(Result), .shamt(shamt), .Zero(Zero));

initial begin
//ADD --> 000
A = 16'd16; B = 16'd34; ALUop = 3'b000; shamt = 4'b0000;
#`DELAY;
A = 16'd100; B = 16'd100; ALUop = 3'b000; shamt = 4'b0000;
#`DELAY;

//SUB --> 001
A = 16'd100; B = 16'd47; ALUop = 3'b001; shamt = 4'b0000;
#`DELAY;
A = 16'd105; B = 16'd3; ALUop = 3'b001; shamt = 4'b0000;
#`DELAY;

//SLT --> 110
A = 32'd100; B = 32'd47; ALUop = 3'b110; shamt = 4'b0000;
#`DELAY;
A = 32'd100; B = 32'd147; ALUop = 3'b110; shamt = 4'b0000;
#`DELAY;

//SLL --> 011
A = 16'hDEDE; B = 16'hXXXX; ALUop = 3'b011; shamt = 4'b0001;
#`DELAY;
A = 16'hBABA; B = 16'hXXXX; ALUop = 3'b011; shamt = 4'b0010;
#`DELAY;

//SRL --> 111
A = 16'hDEDE; B = 16'hXXXX; ALUop = 3'b111; shamt = 4'b0001;
#`DELAY;
A = 16'hBABA; B = 16'hXXXX; ALUop = 3'b111; shamt = 4'b0010;
#`DELAY;

//AND --> 100
A = 16'hFFFF; B = 16'h0000; ALUop = 3'b100; shamt = 4'b0000;
#`DELAY;
A = 16'hABDF; B = 16'h9ECF; ALUop = 3'b100; shamt = 4'b0000;
#`DELAY;

//OR --> 101
A = 16'hFFFF; B = 16'h0000; ALUop = 3'b101; shamt = 4'b0000;
#`DELAY;
A = 16'hABDF; B = 16'h9ECF; ALUop = 3'b101; shamt = 4'b0000;
#`DELAY;

end

initial
begin
$monitor("ALU Results: Result = %d, A = %d, B = %d, shamt = %4b, ALUop = %3b", Result, A, B, shamt, ALUop);
end
 

endmodule