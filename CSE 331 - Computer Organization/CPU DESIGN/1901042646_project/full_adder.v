module full_adder(Sum, Cout, A, B, Cin);
input A, B, Cin;
output Cout, Sum;
wire w1, w2, w3;

half_adder HA1(w1, w2, A, B);
half_adder HA2(Sum, w3, Cin, w1);
or (Cout, w2, w3);

endmodule