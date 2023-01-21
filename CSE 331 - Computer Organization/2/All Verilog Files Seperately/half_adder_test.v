`define DELAY 20
module half_adder_test(); 
reg  A, B;
wire Sum, Carry;

half_adder T(.Sum(Sum), .Carry(Carry), .A(A), .B(B));

initial begin
A = 1'b0; B = 1'b0;
#`DELAY;
A = 1'b0; B = 1'b1;
#`DELAY;
A = 1'b1; B = 1'b0;
#`DELAY;
A = 1'b1; B = 1'b1;
end
 
 
initial 
begin
$monitor("Half Adder Test: RESULT = %1b, A = %1b, B = %1b, Cout = %1b", Sum, A, B, Carry);
end
 
endmodule