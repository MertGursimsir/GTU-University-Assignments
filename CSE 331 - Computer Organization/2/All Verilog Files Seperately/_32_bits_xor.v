module _32_bits_xor(Res, A, B);
input [31:0] A, B;
output [31:0] Res;

xor X0(Res[0], A[0], B[0]);
xor X1(Res[1], A[1], B[1]);
xor X2(Res[2], A[2], B[2]);
xor X3(Res[3], A[3], B[3]);
xor X4(Res[4], A[4], B[4]);
xor X5(Res[5], A[5], B[5]);
xor X6(Res[6], A[6], B[6]);
xor X7(Res[7], A[7], B[7]);
xor X8(Res[8], A[8], B[8]);
xor X9(Res[9], A[9], B[9]);
xor X10(Res[10], A[10], B[10]);
xor X11(Res[11], A[11], B[11]);
xor X12(Res[12], A[12], B[12]);
xor X13(Res[13], A[13], B[13]);
xor X14(Res[14], A[14], B[14]);
xor X15(Res[15], A[15], B[15]);
xor X16(Res[16], A[16], B[16]);
xor X17(Res[17], A[17], B[17]);
xor X18(Res[18], A[18], B[18]);
xor X19(Res[19], A[19], B[19]);
xor X20(Res[20], A[20], B[20]);
xor X21(Res[21], A[21], B[21]);
xor X22(Res[22], A[22], B[22]);
xor X23(Res[23], A[23], B[23]);
xor X24(Res[24], A[24], B[24]);
xor X25(Res[25], A[25], B[25]);
xor X26(Res[26], A[26], B[26]);
xor X27(Res[27], A[27], B[27]);
xor X28(Res[28], A[28], B[28]);
xor X29(Res[29], A[29], B[29]);
xor X30(Res[30], A[30], B[30]);
xor X31(Res[31], A[31], B[31]);

endmodule