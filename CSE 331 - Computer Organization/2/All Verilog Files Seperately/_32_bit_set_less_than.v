module _32_bit_set_less_than(Res, A, B);
input [31:0] A,B;
output Res;

wire [31:0] temp;
wire Cout;
wire C30;

_32_bit_subtractor sub(A, B, temp, Cout, C30);

wire V;
xor OF(V, Cout, C30);

xor OUTPUT(Res, V, temp[31]);

endmodule