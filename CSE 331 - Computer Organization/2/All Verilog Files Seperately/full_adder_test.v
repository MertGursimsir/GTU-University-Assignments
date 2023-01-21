`define DELAY 20
module full_adder_test(); 
reg  A, B, Cin;
wire Sum, Cout;

full_adder T(.Sum(Sum), .Cin(Cin), .Cout(Cout), .A(A), .B(B));

initial begin
A = 1'b0; B = 1'b0; Cin = 1'b0;
#`DELAY;
A = 1'b0; B = 1'b1; Cin = 1'b0;
#`DELAY;
A = 1'b1; B = 1'b0; Cin = 1'b0;
#`DELAY;
A = 1'b1; B = 1'b0; Cin = 1'b1;
end
 
 
initial 
begin
$monitor("Full Adder Test: A = %1b, B = %1b, RESULT = %1b, Cout = %1b, Cin = %1b", A, B, Sum, Cout, Cin);
end
 
endmodule