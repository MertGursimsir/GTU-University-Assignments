module _32_bit_subtractor(A, B, SUB, Cout, C30);
input [31:0] A,B;
output [31:0] SUB;
output Cout;
output C30;

wire [31:0] comp;
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
not N16(comp[16], B[16]);
not N17(comp[17], B[17]);
not N18(comp[18], B[18]);
not N19(comp[19], B[19]);
not N20(comp[20], B[20]);
not N21(comp[21], B[21]);
not N22(comp[22], B[22]);
not N23(comp[23], B[23]);
not N24(comp[24], B[24]);
not N25(comp[25], B[25]);
not N26(comp[26], B[26]);
not N27(comp[27], B[27]);
not N28(comp[28], B[28]);
not N29(comp[29], B[29]);
not N30(comp[30], B[30]);
not N31(comp[31], B[31]);

_32_bit_adder A0(A, comp, SUB, 1'b1, Cout, C30);

endmodule