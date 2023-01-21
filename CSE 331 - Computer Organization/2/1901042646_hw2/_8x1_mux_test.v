`define DELAY 20
module _8x1_mux_test();
reg I0, I1, I2, I3, I4, I5, I6, I7;
reg [2:0] S;
wire RES;

_8x1_mux T(.I0(I0), .I1(I1), .I2(I2), .I3(I3), .I4(I4), .I5(I5), .I6(I6), .I7(I7), .S(S), .RES(RES));

initial
begin
I0 = 1'b1; I1 = 1'b0; I2 = 1'b0; I3 = 1'b0; I4 = 1'b0; I5 = 1'b0; I6 = 1'b0; I7 = 1'b0; S = 3'b000;
#`DELAY;
I0 = 1'b1; I1 = 1'b0; I2 = 1'b1; I3 = 1'b1; I4 = 1'b1; I5 = 1'b1; I6 = 1'b1; I7 = 1'b1; S = 3'b001;
#`DELAY;
I0 = 1'b1; I1 = 1'b1; I2 = 1'b1; I3 = 1'b1; I4 = 1'b1; I5 = 1'b1; I6 = 1'b1; I7 = 1'b0; S = 3'b111;
end

 
initial
begin
$monitor("8x1 MUX Test: RESULT = %1b, I0 = %1b, I1 = %1b, I2 = %1b, I3 = %1b, I4= %1b, I5 = %1b, I6 = %1b, I7 = %1b, S = %3b", RES , I0, I1, I2, I3, I4, I5, I6, I7, S);
end
 
endmodule