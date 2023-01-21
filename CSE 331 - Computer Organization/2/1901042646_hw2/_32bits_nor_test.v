`define DELAY 20
module _32bits_nor_test();
reg [31:0] A, B;
wire [31:0] Res;

_32_bits_nor T(.Res(Res), .A(A), .B(B));

initial
begin
A = 32'hABCDEF11; B = 32'hFFFFFFFF;
#`DELAY;
A = 32'h00AA0000; B = 32'h0CD0BB00;
#`DELAY;
A = 32'hF0000001; B = 32'hA0013001;
end

initial
begin
$monitor("32 Bit NOR Test: A = %32b, B = %32b, RESULT = %32b", A, B, Res);
end
 
endmodule