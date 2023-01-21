module _16_bit_set_less_than(Res, A, B);
input [15:0] A,B;
output Res;

wire [15:0] temp;
wire Cout;
wire C14;

_16_bit_subtractor sub(A, B, temp, Cout, C14);

wire V;
xor OF(V, Cout, C14);
xor OUTPUT(Res, V, temp[15]);

endmodule