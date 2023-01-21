`define DELAY 20
module _32_bit_adder_test();
reg [31:0] A, B;
reg CIn;
wire [31:0] S;
wire COut, C30;

_32_bit_adder T(.A(A), .B(B), .CIn(CIn), .S(S), .COut(COut), .C30(C30));

initial
begin
A = 32'd16; B = 32'd34; CIn = 1'b0;
#`DELAY;
A = 32'd165; B = 32'd128; CIn = 1'b0;
#`DELAY;
A = 32'd100; B = 32'd100; CIn = 1'b0;
#`DELAY;
A = 32'd0; B = 32'd0; CIn = 1'b1;
end


initial
begin
$monitor("32 Bit Adder Test: A = %d, B = %d, RESULT = %d, Cin = %1b, Cout = %1b", A, B, S, CIn, COut);
end
 
endmodule