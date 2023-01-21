module _32_bits_nor(Res, A, B);
input [31:0] A, B;
output [31:0] Res;

nor N0(Res[0], A[0], B[0]);
nor N1(Res[1], A[1], B[1]);
nor N2(Res[2], A[2], B[2]);
nor N3(Res[3], A[3], B[3]);
nor N4(Res[4], A[4], B[4]);
nor N5(Res[5], A[5], B[5]);
nor N6(Res[6], A[6], B[6]);
nor N7(Res[7], A[7], B[7]);
nor N8(Res[8], A[8], B[8]);
nor N9(Res[9], A[9], B[9]);
nor N10(Res[10], A[10], B[10]);
nor N11(Res[11], A[11], B[11]);
nor N12(Res[12], A[12], B[12]);
nor N13(Res[13], A[13], B[13]);
nor N14(Res[14], A[14], B[14]);
nor N15(Res[15], A[15], B[15]);
nor N16(Res[16], A[16], B[16]);
nor N17(Res[17], A[17], B[17]);
nor N18(Res[18], A[18], B[18]);
nor N19(Res[19], A[19], B[19]);
nor N20(Res[20], A[20], B[20]);
nor N21(Res[21], A[21], B[21]);
nor N22(Res[22], A[22], B[22]);
nor N23(Res[23], A[23], B[23]);
nor N24(Res[24], A[24], B[24]);
nor N25(Res[25], A[25], B[25]);
nor N26(Res[26], A[26], B[26]);
nor N27(Res[27], A[27], B[27]);
nor N28(Res[28], A[28], B[28]);
nor N29(Res[29], A[29], B[29]);
nor N30(Res[30], A[30], B[30]);
nor N31(Res[31], A[31], B[31]);

endmodule