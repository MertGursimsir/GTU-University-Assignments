`define DELAY 20
module _2x1_mux_test(); 
reg  I0, I1, S;
wire RES;

_2x1_mux T(.I0(I0), .I1(I1), .S(S), .RES(RES));

initial begin
I0 = 1'b0; I1 = 1'b0; S = 1'b1;
#`DELAY;
I0 = 1'b0; I1 = 1'b1; S = 1'b1;
#`DELAY;
I0 = 1'b1; I1 = 1'b0; S = 1'b1;
#`DELAY;
I0 = 1'b1; I1 = 1'b0; S = 1'b0;
end
 
 
initial 
begin
$monitor("2x1 MUX Test: RESULT = %1b, I0 = %1b, I1 = %1b, S = %1b", RES, I0, I1, S);
end
 
endmodule