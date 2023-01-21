`define DELAY 20
module _32_bit_set_less_than_test();
reg [31:0] A, B;
wire Res;

_32_bit_set_less_than T(.A(A), .B(B), .Res(Res));

initial
begin
A = 32'd34; B = 32'd16;
#`DELAY;
A = 32'd165; B = 32'd166;
#`DELAY;
A = 32'd100; B = 32'd99;
#`DELAY;
A = 32'd0; B = 32'd0;
end


initial
begin
$monitor("32 Bit Set-Less-Than Test: A = %d, B = %d, Set = %1b", A, B, Res);
end
 
endmodule