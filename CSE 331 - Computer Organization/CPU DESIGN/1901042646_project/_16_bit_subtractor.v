module _16_bit_subtractor(A, B, SUB, Cout, C14);
input [15:0] A,B;
output [15:0] SUB;
output Cout;
output C14;

wire [15:0] comp;
not N0(comp[0], B[0]);
not N1(comp[1], B[1]);
not N2(comp[2], B[2]);
not N3(comp[3], B[3]);
not N4(comp[4], B[4]);
not N5(comp[5], B[5]);
not N6(comp[6], B[6]);
not N7(comp[7], B[7]);
not N8(comp[8], B[8]);
not N9(comp[9], B[9]);
not N10(comp[10], B[10]);
not N11(comp[11], B[11]);
not N12(comp[12], B[12]);
not N13(comp[13], B[13]);
not N14(comp[14], B[14]);
not N15(comp[15], B[15]);


_16_bit_adder A0(A, comp, SUB, 1'b1, Cout, C14);

endmodule