module half_adder(Sum, Carry, A, B);
input A, B;
output Sum, Carry;

xor G1(Sum, A, B);
and G2(Carry, A, B);

endmodule