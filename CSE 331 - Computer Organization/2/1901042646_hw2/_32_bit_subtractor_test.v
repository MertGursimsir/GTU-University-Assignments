`define DELAY 20
module _32_bit_subtractor_test();
reg [31:0] A, B;
wire [31:0] SUB;
wire Cout, C30;

_32_bit_subtractor T(.A(A), .B(B), .SUB(SUB), .Cout(Cout), .C30(C30));

initial
begin
A = 32'd34; B = 32'd16;
#`DELAY;
A = 32'd165; B = 32'd128;
#`DELAY;
A = 32'd100; B = 32'd40;
#`DELAY;
A = 32'd0; B = 32'd0;
end


initial
begin
$monitor("32 Bit Subtractor Test: A = %d, B = %d, RESULT = %d", A, B, SUB);
end
 
endmodule