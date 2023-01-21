module _16_bits_or(Res, A, B);
input [15:0] A, B;
output [15:0] Res;

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

endmodule