module _32_bits_or(Res, A, B);
input [31:0] A, B;
output [31:0] Res;

or O0(Res[0], A[0], B[0]);
or O1(Res[1], A[1], B[1]);
or O2(Res[2], A[2], B[2]);
or O3(Res[3], A[3], B[3]);
or O4(Res[4], A[4], B[4]);
or O5(Res[5], A[5], B[5]);
or O6(Res[6], A[6], B[6]);
or O7(Res[7], A[7], B[7]);
or O8(Res[8], A[8], B[8]);
or O9(Res[9], A[9], B[9]);
or O10(Res[10], A[10], B[10]);
or O11(Res[11], A[11], B[11]);
or O12(Res[12], A[12], B[12]);
or O13(Res[13], A[13], B[13]);
or O14(Res[14], A[14], B[14]);
or O15(Res[15], A[15], B[15]);
or O16(Res[16], A[16], B[16]);
or O17(Res[17], A[17], B[17]);
or O18(Res[18], A[18], B[18]);
or O19(Res[19], A[19], B[19]);
or O20(Res[20], A[20], B[20]);
or O21(Res[21], A[21], B[21]);
or O22(Res[22], A[22], B[22]);
or O23(Res[23], A[23], B[23]);
or O24(Res[24], A[24], B[24]);
or O25(Res[25], A[25], B[25]);
or O26(Res[26], A[26], B[26]);
or O27(Res[27], A[27], B[27]);
or O28(Res[28], A[28], B[28]);
or O29(Res[29], A[29], B[29]);
or O30(Res[30], A[30], B[30]);
or O31(Res[31], A[31], B[31]);

endmodule